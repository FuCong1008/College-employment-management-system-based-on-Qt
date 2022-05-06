#include "login.h"
#include "ui_login.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    switchScreen = Q_NULLPTR;
    regUser = Q_NULLPTR;
    tcpServerr = Q_NULLPTR;
    tcpClient = Q_NULLPTR;

    //this->setWindowFlags(Qt::FramelessWindowHint);    //只有关闭按钮
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnBottomHint);    //只有关闭按钮
    this->setAttribute(Qt::WA_TranslucentBackground);   //背景透明
    this->setWindowOpacity(0.95);       //设置这个窗口的透明度
    //this->setWindowFlag(Qt::SplashScreen); //设置为splash窗口,无边框，且在windows任务栏上没有显示
    //this->setAttribute(Qt::WA_DeleteOnClose);   //关闭窗口时，释放内存(去掉注释这里会有异常)
//    this->setPalette(Qt::black);

    //加载用户信息到本地
    loadDBToLocal();

    //加载用户登录记录信息到本地
    loadDBofRecordLoginToLocal();

    ComboxAddItem();

    QRegExp regx("[0-9]+[a-z]+[A-Z]+$");    //限制只能输入数字, 大小写字母
    QValidator *validator = new QRegExpValidator(regx,ui->combox_account);
    ui->combox_account->setValidator(validator);
    ui->combox_account->setFocus();
    ui->le_pwd->setMaxLength(15);

    //ui->le_pwd->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

void Login::loadDBToLocal()
{
    //加载用户信息到本地
    userInfo.clear();    //每次加载到本地时，对本地学生数据进行清零

    QSqlQuery queryUser(db);
    queryUser.prepare("select * from user");
    if(queryUser.exec())
    {
        while(queryUser.next())
        {
            VariableSet::User user;
            user.Account = queryUser.value("account").toString();
            user.Password = queryUser.value("pwd").toString();
            user.Identity = queryUser.value("identity").toString();
            user.userName = queryUser.value("userName").toString();
            userInfo.push_back(user);
        }
    }else{
        Warning::setInformation(QStringLiteral("加载用户信息到本地失败"));
        cout << QStringLiteral("访问数据库失败");
    }
}

void Login::loadDBofRecordLoginToLocal()
{
    //加载记录登录信息到本地
    recLoginInfo.clear();    //每次加载到本地时，对本地记录登录信息进行清零

    QSqlQuery recLoginQuery(db);
    recLoginQuery.prepare("select * from recordlogin");
    if(recLoginQuery.exec())
    {
        while(recLoginQuery.next())
        {
            VariableSet::RecordLoginInfo recLogin;
            recLogin.Account = recLoginQuery.value("account").toString();
            recLogin.Password = recLoginQuery.value("pwd").toString();
            recLogin.LoginFlag = recLoginQuery.value("loginFlag").toString();
            recLoginInfo.push_back(recLogin);
        }
    }else{
        Warning::setInformation(QStringLiteral("访问SEMS中的登录记录信息表失败"));
        cout << QStringLiteral("访问SEMS中的登录记录信息表失败");
    }
}

void Login::ComboxAddItem()
{
    //下拉框添加项之前都得清空下拉框的所有内容
    ui->combox_account->clear();

     //初始化combox账号的项
    for (int i = 0; i < recLoginInfo.count(); ++i){
        VariableSet::RecordLoginInfo recLogin = recLoginInfo.at(i);
        ui->combox_account->addItem(recLogin.Account);
    }
}

void Login::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void Login::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag == true){
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

void Login::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_bDrag = false;
    }
}

void Login::keyPressEvent(QKeyEvent *ev)
{//针对焦点处理
    if(ev->key() == Qt::Key_Enter || ev->key() == Qt::Key_Return){
        if(ui->combox_account->hasFocus()){
            ui->le_pwd->setFocus();
            keyPressTime = 0;
            return;
        }
        if(ui->le_pwd->hasFocus()){
            keyPressTime+=1;
        }
        return;
    }
    if(ev->key() == Qt::Key_Up){
        ui->combox_account->setFocus();
    }
}

void Login::keyReleaseEvent(QKeyEvent *ev)
{//针对焦点处理
    if(ev->key() == Qt::Key_Enter || ev->key() == Qt::Key_Return){
        //焦点从账号框切换到密码框
        if(ui->combox_account->hasFocus()){
            ui->le_pwd->setFocus();
            return;
        }
        if(ui->le_pwd->hasFocus()){
            if(keyPressTime == 1){
                this->loginOperate();
            }
        }
    }else{
        if(ev->key() == Qt::Key_Up){
            ui->combox_account->setFocus();
        }
        keyPressTime = 0;
    }
}

void Login::loginOperate()
{
    //    loadDBToLocal();    //这里可能是点击了注册，然后更新到本地

        //使登录记录信息表的登录标志全设置为no(一次只能登录一个账号,未登录前登录标志都为no,登录后只对当前登录账号设置登录标志为yes)(多台主机登录时，这里会不合理)
        //改进：只对当前登入账号的登入标志设置为yes，当前账号退出后设置为no(所有账号未登入时全默认为no,所以注释掉以下代码块)
    //    QSqlQuery setNoQuery(db);
    //    setNoQuery.prepare("update recordlogin set loginFlag ='no'");
    //    if(setNoQuery.exec()){
    //        cout << QStringLiteral("登录前设置登录标志全为no成功");
    //    }

        QString curAccount = ui->combox_account->currentText();
        QString curPwd = ui->le_pwd->text();

//        //判断当前账号是否已注册
//        bool flag = false;
//        for (int i = 0; i < userInfo.size(); ++i){
//            if(userInfo.at(i).Account.contains(curAccount)){
//                flag = true;
//                break;
//            }
//        }
//        if(flag == false){
//            //该用户为注册
//            Warning::setInformation(QString("账号：%1").arg(curAccount)+QStringLiteral("\n该用户还未注册哦！"));
//            return;
//        }


        //账号判空提示
        if(curAccount.isEmpty())
        {
            Warning::setInformation("请输入账号");
            ui->combox_account->setFocus();
            return;
        }

        //密码判空提示
        if(curPwd.isEmpty())
        {
            Warning::setInformation("请输入密码");
            ui->le_pwd->setFocus();
            return;
        }

        //判断当前用户登录账号信息是否在本地用户信息中存在
        {
            bool isCurAccount = false;  //false表示不存在
            for (int i = 0; i < userInfo.count(); ++i){
                if(userInfo.at(i).Account.contains(curAccount)){
                    isCurAccount = true;
                    break;//存在记录跳出循环
                }
            }
            //账号错误警告(账号记录不存在)
            if(false == isCurAccount){
                Warning::setInformation(QStringLiteral("账号输入错误"));
                ui->combox_account->setFocus();
                //不存在可以选择去注册
                return;
            }
        }

        //判断当前登录密码是否在本地用户信息中存在(前提是账号要存在)
        {
            bool isCurPwd = false;
            for (int j = 0; j < userInfo.count(); ++j){
                if(userInfo.at(j).Account == curAccount && userInfo.at(j).Password == curPwd){
                    isCurPwd = true;
                    break;//存在记录跳出循环
                }
            }
            //密码错误警告(密码记录不存在)
            if(false == isCurPwd){
                Warning::setInformation(QStringLiteral("密码输入错误"));
                ui->le_pwd->setFocus();
                return;
            }
        }

        //判断当前登录账号是否在本地登录记录信中存在，不存在则插入到登入记录信息中
        {
            bool isCurAccount = false;
            for (int i = 0; i < recLoginInfo.count(); ++i){
                if(recLoginInfo.at(i).Account == curAccount){
                    isCurAccount = true;
                    break;//存在登录记录跳出循环
                }
            }

            //当前登录账号不存在于本地登录信息中(希望这样，同时设置登入标志为yes)
            if(false == isCurAccount){
                //将当前登录信息插入到数据库中"记录信息表"中(因为为点击登录槽函数里面，所以登录标志设置为yes)
                VariableSet::RecordLoginInfo recInfo;
                QSqlQuery recordQuery(db);
                recordQuery.prepare("insert into recordlogin (account,pwd,loginFlag) values(?,?,?)");
                recordQuery.bindValue(0,curAccount);
                recInfo.Account = curAccount;
                if(ui->rBtn_isRemPwd->isChecked()){
                    //记住密码，则保存密码
                    recordQuery.bindValue(1,curPwd);
                    recInfo.Password = curPwd;
                }else{
                    //不记住密码，则密码置空
                    recordQuery.bindValue(1,"");    //换为NULL会有问题
                    recInfo.Password = "";
                }
                recordQuery.bindValue(2,"yes");
                recInfo.LoginFlag = "yes";      //当前为登入按钮，点击登入后，设置当前账号登入标志为yes
                if(recordQuery.exec()){
    //                loadDBofRecordLoginToLocal();   //更新登录记录信息(因为当前登录账号不存在于本地登录信息中)
    //                ComboxAddItem();//更新账号下拉框内容？？？
                    recLoginInfo.push_back(recInfo);
                    ui->combox_account->addItem(curAccount);
                }
            }

            //针对勾选框是否勾选的处理(登录信息表记住登录密码)
            QSqlQuery updateQuery(db);
            if(!ui->rBtn_isRemPwd->isChecked()){
                //一:未勾选:删除当前密码文本框内容和置空登录记录信息表里相应账号的密码(不记录密码)
                updateQuery.prepare("update recordlogin set pwd=NULL where account=?");
                updateQuery.bindValue(0,curAccount);
                updateQuery.exec();
                ui->le_pwd->clear();//清空密码编辑框内容
            }else{
                //二:勾选:保存当前密码文本框内容和填写登录记录信息表里相应账号的密码(记录密码)
                updateQuery.prepare("update recordlogin set pwd=? where account=?");
                updateQuery.bindValue(0,curPwd);
                updateQuery.bindValue(1,curAccount);
                updateQuery.exec();
            }
            loadDBofRecordLoginToLocal();       //刷新本地登录记录数据(这里一定执行的，存在效率问题，可优化)
        }

        //点击该登录按钮说明当前账号登录了,设置登录标志为yes(Tip:登录记录信息表中的登录标志只能有一个yes)
        QSqlQuery yesQuery(db);
        yesQuery.prepare("update recordlogin set loginFlag ='yes' where account=?");
        yesQuery.bindValue(0,curAccount);
        if(yesQuery.exec()){
            cout << QStringLiteral("设置当前账号登录标志为yes成功");
        }

        //切换到登录后的界面
        if(Q_NULLPTR == switchScreen)
        {
            switchScreen = new SwitchScreen;
        }
        connect(switchScreen,SIGNAL(sig_close()),this,SLOT(show()));
        connect(switchScreen,SIGNAL(sig_close()),this,SLOT(slot_resetkeyPressTime()));
        this->hide();

        QString userId = switchScreen->getCurLoginUserIdentity();    //从数据库中获取当前登录账号的身份
        switchScreen->setCurLoginUserIdentity();   //设置当前登录账号的身份
        switchScreen->setLoginMainScreen();     //设置登录后主界面里显示的子界面为当前界面
        switchScreen->showFullScreen();

        //以下为网络通讯模块，只实现基本模块
        if(userId == "管理员"){
            if(Q_NULLPTR == tcpServerr)
            {
                tcpServerr = new TcpServer;
            }
            tcpServerr->startListen();  //管理员登录启动服务器端监听
            //cout << userId;
        }else{
            if(Q_NULLPTR == tcpClient)
            {
                tcpClient = new TcpClient;
            }
            tcpClient->connectServer();  //学生或教师登录启动客户端连接服务器
            //cout << userId;
        }
}

void Login::on_btn_login_clicked()
{
    this->loginOperate();
}

void Login::on_btn_register_clicked()
{
    if(regUser == Q_NULLPTR){
        regUser = new RegisterUser;
    }
    connect(regUser,SIGNAL(sig_close()),this,SLOT(show()));
    connect(regUser,SIGNAL(sig_close()),this,SLOT(loadDBToLocal()));
    this->hide();
    regUser->showNormal();
}

void Login::on_btn_exit_clicked()
{
    this->close();
}

void Login::on_combox_account_currentTextChanged(const QString &arg1)
{
    for (int i = 0; i < recLoginInfo.count(); ++i) {
        if(recLoginInfo.at(i).Account == arg1){
            ui->le_pwd->setText(recLoginInfo.at(i).Password);
            //cout << QStringLiteral("密码编辑框显示密码成功");
            break;
        }
    }
}

void Login::slot_resetkeyPressTime()
{
    keyPressTime = 0;
}
