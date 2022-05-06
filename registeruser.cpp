#include "registeruser.h"
#include "ui_registeruser.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

RegisterUser::RegisterUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterUser)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);   //背景透明
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnBottomHint);    //只有关闭按钮

    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    QRegExp regx("[0-9]+$");    //限制只能输入数字
    QValidator *validator = new QRegExpValidator(regx,ui->le_account);
    ui->le_account->setValidator(validator);
    ui->le_account->setMaxLength(11); //账号长度最长为11
}

RegisterUser::~RegisterUser()
{
    delete ui;
}

void RegisterUser::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void RegisterUser::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag == true){
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

void RegisterUser::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_bDrag = false;
    }
}

void RegisterUser::on_btn_ack_clicked()
{
    QString name = ui->le_name->text();
    QString account = ui->le_account->text();   //为主键
    QString pwd = ui->le_pwd->text();
    QString actPwd = ui->le_pwdAct->text();
    QString id;
    if(ui->rbtn_stu->isChecked()){
        //默认学生身份
        id = ui->rbtn_stu->text();
    }
    if(ui->rbtn_teacher->isChecked()){
        id = ui->rbtn_teacher->text();
    }
    if(ui->rbtn_admin->isChecked()){
        id = ui->rbtn_admin->text();
    }

    //姓名判空提示
    if(name.isEmpty()){
        Warning::setInformation(QStringLiteral("请输入用户姓名"));
        return;
    }

    //账号判空提示
    if(account.isEmpty()){
        Warning::setInformation("请输入账号");
        return;
    }
    if(account.length()!=11){
        Warning::setInformation(QStringLiteral("请输入11位长度的账号哈"));
        return;
    }

    //密码判空提示
    if(pwd.isEmpty()){
        Warning::setInformation("请输入密码");
        return;
    }

    //两次密码输入不一致的判错处理
    if(actPwd != pwd){
        Warning::setInformation("密码不一致错误");
        return;
    }

    //保证用户账号不重复创建
    QSqlQuery repeatQuery(db);
    repeatQuery.prepare("select account from user");
    QStringList accountList;
    if(repeatQuery.exec()){
        while(repeatQuery.next()){
            accountList << repeatQuery.value("account").toString();
        }
        //判断当前注册用户是否已注册
        if(accountList.contains(account)){
            Warning::setWarning("该用户已注册");
            return;
        }
    }

    //该唯一的用户存到数据库中
    QSqlQuery insertQuery(db);
    insertQuery.prepare("insert into user (account,pwd,identity,userName)values(?,?,?,?)");
    insertQuery.bindValue(0,account);
    insertQuery.bindValue(1,actPwd);
    insertQuery.bindValue(2,id);
    insertQuery.bindValue(3,name);
    if(insertQuery.exec())
    {
        Warning::setInformation(QStringLiteral("插入用户数据成功"));
        return;
    }else{
        Warning::setInformation(QStringLiteral("插入用户数据失败"));
        return;
    }
}

void RegisterUser::on_btn_back_clicked()
{
    emit sig_close();
    this->hide();
}
