#include "switchscreen.h"
#include "ui_switchscreen.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

SwitchScreen::SwitchScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SwitchScreen)
{
    ui->setupUi(this);
    userAccount = Q_NULLPTR;
    userId = Q_NULLPTR;

    employInfo = Q_NULLPTR;
    stuInfo =Q_NULLPTR;
    companyInfo = Q_NULLPTR;
    employStatis = Q_NULLPTR;
    userManagement = Q_NULLPTR;

    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    //this->setWindowModified(Qt::ApplicationModal);
    this->setWindowOpacity(0.97);       //设置这个窗口的透明度
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    //从数据库中获取当前登录账号的身份
//    getCurLoginUserIdentity();

    //设置子界面的显示
    setSubScreen();

//    if(currentTime == Q_NULLPTR){
//        currentTime = new QTimer();
//    }
//    currentTime->start(1000);
//    connect(currentTime,SIGNAL(timeout()),this,SLOT(setLabelShowTime()));
}

SwitchScreen::~SwitchScreen()
{
    delete ui;
}

void SwitchScreen::setSubScreen()
{
    if(Q_NULLPTR == employInfo)
    {
        employInfo = new EmploymentInfo(this);
    }
    if(Q_NULLPTR == stuInfo)
    {
        stuInfo = new StudentInfo(this);
    }
    if(Q_NULLPTR == companyInfo)
    {
        companyInfo = new CompanyInfo(this);
    }
    if(Q_NULLPTR == employStatis)
    {
        employStatis = new EmploymentStatistics(this);
    }
    if(Q_NULLPTR == userManagement)
    {
        userManagement = new UserManagement(this);
    }

    //添加子界面
    ui->stackedWidget->addWidget(employInfo);
    ui->stackedWidget->addWidget(stuInfo);
    ui->stackedWidget->addWidget(companyInfo);
    ui->stackedWidget->addWidget(employStatis);
    ui->stackedWidget->addWidget(userManagement);
}

void SwitchScreen::getUserIdOnDBLoginFlag()
{
    //加载记录登录信息到本地
    QString userId;

    //根据登录标志查询登录账号
    QSqlQuery recLoginQuery(db);
    recLoginQuery.prepare("select account from recordlogin where loginFlag='no'");
    if(recLoginQuery.exec())
    {
        QString account;
        while (recLoginQuery.next()){
            account = recLoginQuery.value("account").toString();
        }

        //根据账号查询用户身份
        QSqlQuery userIdQuery(db);
        userIdQuery.prepare("select identity from user where account=?");
        userIdQuery.bindValue(0,account);
        if(userIdQuery.exec()){
            while (userIdQuery.next()){
                userId = userIdQuery.value("identity").toString();
            }
        }
    }else{
        cout << QStringLiteral("访问SEMS中的登录记录信息表失败");
    }
    ui->tbn_userId->setText(userId);
}

QString SwitchScreen::getCurLoginUserIdentity()
{
    QSqlQuery showIdQuery(db);
    showIdQuery.prepare("select r.account,u.identity from recordlogin as r,user as u where r.loginFlag ='yes' and r.account = u.account");
    if(showIdQuery.exec()){
        QString curAccount;
        QString id;
        while (showIdQuery.next()){
            curAccount = showIdQuery.value("account").toString();
            id = showIdQuery.value("identity").toString();
        }
        userAccount = curAccount;
        userId = id;
    }
    return userId;
}

void SwitchScreen::setCurLoginUserIdentity()
{
    //先修改数据库配置文件的ip
    QString i = QString::number(-1);
    if(userId == QStringLiteral("学生")){
        i=QString::number(1);
    }
    if(userId == QStringLiteral("教师")){
        i=QString::number(2);
    }
    if(userId == QStringLiteral("管理员")){
        i=QString::number(3);
    }

    //同时修改配置文件的用户登录记录信息
    ConfigValue::setConfigValueWithKey("Config/userLogin.ini","USERLOGIN/ACCOUNT",userAccount);
    ConfigValue::setConfigValueWithKey("Config/userLogin.ini","USERLOGIN/IDENTITY",i);
    ui->tbn_userId->setText(userId);
}

void SwitchScreen::setLoginMainScreen()
{
    //是就业信息显示为主子界面
    ui->stackedWidget->setCurrentWidget(stuInfo);
}

void SwitchScreen::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
//    if(event->button() == Qt::LeftButton){
//        m_bDrag = true;
//        //获得鼠标的初始位置
//        mouseStartPoint = event->globalPos();
//        //获得窗口的初始位置
//        windowTopLeftPoint = this->frameGeometry().topLeft();
//    }
}

void SwitchScreen::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
//    if(m_bDrag == true){
//        //获得鼠标移动的距离
//        QPoint distance = event->globalPos() - mouseStartPoint;
//        //改变窗口的位置
//        this->move(windowTopLeftPoint + distance);
//    }
}

void SwitchScreen::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
//    if(event->button() == Qt::LeftButton){
//        m_bDrag = false;
//    }
}

//暂时不用
void SwitchScreen::setLabelShowTime()
{
    QDateTime current_time=QDateTime::currentDateTime();
    QString strCurrentTime = current_time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->le_showTime->setText(strCurrentTime);
}

void SwitchScreen::on_tbn_info_clicked()
{
    employInfo->loadDBToLocal();//加载数据库的数据到本地
    employInfo->insertDataToTableWidget();//先把本地已有的数据加载到表格中
    ui->stackedWidget->setCurrentWidget(employInfo);
}

void SwitchScreen::on_tbn_stuInfo_clicked()
{
    stuInfo->loadDBStudentInfoToLocal();//加载数据库的数据到本地
    stuInfo->insertDataToTableWidget();//先把本地已有的数据加载到表格中
    ui->stackedWidget->setCurrentWidget(stuInfo);
}

void SwitchScreen::on_tbn_count_clicked()
{
    ui->stackedWidget->setCurrentWidget(employStatis);
}

void SwitchScreen::on_tbn_userManagement_clicked()
{
    ui->stackedWidget->setCurrentWidget(userManagement);
    userManagement->setTableIsEnabled();
}

void SwitchScreen::on_tbn_company_clicked()
{
    companyInfo->loadDBCompanyInfoToLocal();//加载数据库的数据到本地
    companyInfo->insertDataToTableWidget();//先把本地已有的数据加载到表格中
    ui->stackedWidget->setCurrentWidget(companyInfo);
}

void SwitchScreen::on_tbn_exit_clicked()
{
    //退出系统的按钮
    //退出后,要将当前登录账号的登录标志设置为no
    QSqlQuery setCurAccountFalgQuery(db);
    QString curAccount = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/ACCOUNT").toString();
    setCurAccountFalgQuery.prepare("update recordlogin set loginFlag='no' where account=?");
    setCurAccountFalgQuery.bindValue(0,curAccount);
    if(setCurAccountFalgQuery.exec()){
        cout << QStringLiteral("退出当前系统,设置登录标志全为no成功") << curAccount;
    }
    emit sig_close();   //发射退出系统的通知信号给登录界面
    this->close();
    //this->deleteLater();
}

void SwitchScreen::on_tbn_userId_clicked()
{

}
