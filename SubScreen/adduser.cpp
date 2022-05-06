#include "adduser.h"
#include "ui_adduser.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

AddUser::AddUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    this->setAttribute(Qt::WA_TranslucentBackground);   //背景透明
    //this->setWindowFlags(Qt::WindowCloseButtonHint);    //只有关闭按钮
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowStaysOnTopHint);    //只有关闭按钮
    //this->setWindowModified(Qt::ApplicationModal);  //阻止同一应用的其它窗口获取输入事件（应用级别的模态）
    this->setWindowOpacity(0.95);       //设置这个窗口的透明度
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::closeEvent(QCloseEvent *event)
{
    this->close();
    event->accept();
}

void AddUser::on_btn_reset_clicked()
{
    ui->le_account->clear();
    ui->le_userPwd->setText("123456");
    ui->le_userName->clear();
    ui->rbtn_stu->setChecked(true);
    ui->rbtn_teacher->setChecked(false);
    ui->rbtn_admin->setChecked(false);
}

void AddUser::on_btn_submit_clicked()
{
    if(ui->le_account->text().isEmpty() || ui->le_userName->text().isEmpty()){
        Warning::setInformation("文本编辑框为空");
        return;
    }
    VariableSet::User userInfo;     //用户信息
    userInfo.Account = ui->le_account->text();
    userInfo.Password = ui->le_userPwd->text();
    userInfo.userName = ui->le_userName->text();
    if(ui->rbtn_stu->isChecked()){
        userInfo.Identity = ui->rbtn_stu->text();
    }
    if(ui->rbtn_teacher->isChecked()){
        userInfo.Identity = ui->rbtn_teacher->text();
    }
    if(ui->rbtn_admin->isChecked()){
        userInfo.Identity = ui->rbtn_admin->text();
    }

    QSqlQuery query(db);
    query.prepare("select account from user");
    QStringList accList;
    if(query.exec()){
        while (query.next()){
            accList << query.value("account").toString();
        }
//        cout << accList.count();
        //账号存在重复
        if(accList.contains(userInfo.Account)){
            QSqlQuery nameQuery(db);
            nameQuery.prepare("select account,pwd,identity,userName from user where account=?");
            nameQuery.bindValue(0,userInfo.Account);//因为账号唯一
            //cout <<userInfo.Account;
            if(nameQuery.exec()){
                QStringList tmpUser;
                while (nameQuery.next()){
                    tmpUser << nameQuery.value("account").toString();
                    tmpUser << nameQuery.value("pwd").toString();
                    tmpUser << nameQuery.value("identity").toString();
                    tmpUser << nameQuery.value("userName").toString();
                }
                QString tmpName = tmpUser.at(3);
                QString tmpPwd = tmpUser.at(1);
                QString tmpId = tmpUser.at(2);
                ui->le_userPwd->setText(tmpPwd);
                if(ui->rbtn_admin->text() == tmpId){
                    ui->rbtn_admin->setChecked(true);
                }
                if(ui->rbtn_stu->text() == tmpId){
                    ui->rbtn_stu->setChecked(true);
                }
                if(ui->rbtn_teacher->text() == tmpId){
                    ui->rbtn_teacher->setChecked(true);
                }
                cout <<tmpName << tmpId;
                //但用户名称为空
                if(tmpName.isEmpty()){
                    QSqlQuery updateQuery(db);
                    updateQuery.prepare("update user set userName=? where account=?");
                    updateQuery.bindValue(0,userInfo.userName);
                    updateQuery.bindValue(1,userInfo.Account);
                    if(updateQuery.exec()){
                        userInfo.Identity=tmpId;
                        emit sig_submitUserData(userInfo);//向主界面传递用户信息(已存在账号，更新用户姓名)
                        cout << QStringLiteral("更新已存在的账号但用户姓名为空的字段成功");
                    }
                }else{
                    Warning::setInformation(QStringLiteral("当前用户已存在"));
                }
            }
        }else{
            //不存在重复账号
            QSqlQuery saveQuery(db);
            saveQuery.prepare("insert into user values(?,?,?,?)");
            saveQuery.bindValue(0,userInfo.Account);
            saveQuery.bindValue(1,userInfo.Password);
            saveQuery.bindValue(2,userInfo.Identity);
            saveQuery.bindValue(3,userInfo.userName);
            if(saveQuery.exec()){
                emit sig_submitUserData(userInfo);//向主界面传递新用户信息
                cout << QStringLiteral("提交用户数据成功");
            }
        }
    }
}
