#include "addcompany.h"
#include "ui_addcompany.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

AddCompany::AddCompany(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCompany)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);   //背景透明
    //this->setWindowFlags(Qt::WindowCloseButtonHint);    //只有关闭按钮
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowStaysOnTopHint);    //只有关闭按钮
    //this->setWindowModified(Qt::ApplicationModal);  //阻止同一应用的其它窗口获取输入事件（应用级别的模态）
    this->setWindowOpacity(0.95);       //设置这个窗口的透明度
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    initComboxItem();

    QRegExp regx("[0-9]+$");    //限制只能输入数字
    QValidator *validatorContactsPhone = new QRegExpValidator(regx,ui->le_contacterPhone);
    ui->le_contacterPhone->setValidator(validatorContactsPhone);
    ui->le_contacterPhone->setMaxLength(11);
}

AddCompany::~AddCompany()
{
    delete ui;
}

bool AddCompany::dealWithLineEditIsNull()
{
    //账号判空提示(这里可以优化下)
    if(ui->le_ability->text().isEmpty() || ui->le_company->text().isEmpty()
            || ui->le_contacterName->text().isEmpty() || ui->le_contacterPhone->text().isEmpty() || ui->le_post->text().isEmpty()
            || ui->le_salary->text().isEmpty())
    {
        return true;
    }
    return false;
}

void AddCompany::saveCompanyToDB(QSqlDatabase &db)
{
    VariableSet::Company com;
    com.CompanySide = ui->combox_showProvince->currentText()+ui->combox_showCity->currentText();    //就业城市
    com.CompanyName = ui->le_company->text();   //公司名称
    com.Contacts = ui->le_contacterName->text();        //公司联系人
    com.ContactsPhone = ui->le_contacterPhone->text();  //公司联系人电话
    com.JobPost = ui->le_post->text();      //就业岗位
    com.Salary = ui->le_salary->text();     //就业薪资
    com.AbilityRecquire = ui->le_ability->text();   //能力需求

    //保存该公司的信息
    QSqlQuery comQuery(db);
    comQuery.prepare("insert into company (companySide,companyName,contacts,contactsPhone,jobPost,salary,abilityRecquire)"
                     "values(?,?,?,?,?,?,?)");
    comQuery.bindValue(0,com.CompanySide);
    comQuery.bindValue(1,com.CompanyName);
    comQuery.bindValue(2,com.Contacts);
    comQuery.bindValue(3,com.ContactsPhone);
    comQuery.bindValue(4,com.JobPost);
    comQuery.bindValue(5,com.Salary);
    comQuery.bindValue(6,com.AbilityRecquire);
    if(comQuery.exec()){
        cout << QStringLiteral("保存公司信息成功");
    }
    emit sig_companyInfo(com);
}

void AddCompany::initComboxItem()
{
    ui->combox_showProvince->clear();
    ui->combox_showCity->clear();
    QSqlDatabase db;
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));
    QSqlQuery cityQuery(db);
    cityQuery.prepare("select distinct province from city");
    if(cityQuery.exec()){
        QStringList provinces;
        while (cityQuery.next()){
            provinces << cityQuery.value("province").toString();
        }
        ui->combox_showProvince->addItems(provinces); //添加省
    }
}

void AddCompany::on_btn_submit_clicked()
{
    //账号判空提示
    if(dealWithLineEditIsNull() == false){
        QString CompanyName = ui->le_company->text();
        QString JobPost = ui->le_post->text();      //就业岗位

        QSqlQuery queryCom(db);
        queryCom.prepare("select companyName,jobPost from company where companyName=? and jobPost=?");
        queryCom.bindValue(0,CompanyName);
        queryCom.bindValue(1,JobPost);
        QStringList record;
        if(queryCom.exec()){
            while (queryCom.next()){
                record << queryCom.value("companyName").toString();
                record << queryCom.value("jobPost").toString();
            }
        }
        if(record.size()!=2){
            //公司情况信息保存(该公司信息不存在重复)
            saveCompanyToDB(db);
        }else{
            //该公司信息存在重复，再添加给予警告
            Warning::setWarning("该记录已重复添加啦");
            return;
        }
    }else{
        Warning::setInformation("有文本框为空");
        return;
    }
}

void AddCompany::on_btn_reset_clicked()
{
    //重置为空
    ui->le_company->clear();
    ui->combox_showProvince->setCurrentIndex(0);
    ui->le_contacterName->clear();
    ui->le_contacterPhone->clear();
    ui->le_post->clear();
    ui->le_salary->clear();
    ui->le_ability->clear();
}

void AddCompany::on_combox_showProvince_currentTextChanged(const QString &arg1)
{
    ui->combox_showCity->clear();
    QSqlDatabase db;
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));
    QSqlQuery queryTown(db);
    queryTown.prepare("select town from city where province=?");
    queryTown.bindValue(0,arg1);
    if(queryTown.exec()){
        QStringList towns;
        while (queryTown.next()){
            towns << queryTown.value("town").toString();
        }
        ui->combox_showCity->addItems(towns);   //添加市
    }
}
