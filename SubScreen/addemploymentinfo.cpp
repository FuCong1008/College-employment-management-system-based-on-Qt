#include "addemploymentinfo.h"
#include "ui_addemploymentinfo.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

AddEmploymentInfo::AddEmploymentInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEmploymentInfo)
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
    QValidator *validator = new QRegExpValidator(regx,ui->le_stuNumber);
    ui->le_stuNumber->setValidator(validator);
    ui->le_stuNumber->setMaxLength(11); //学号长度最长为11
    QValidator *validatorStuPhone = new QRegExpValidator(regx,ui->le_stuPhone);
    ui->le_stuPhone->setValidator(validatorStuPhone);
    ui->le_stuPhone->setMaxLength(11);  //电话号码长度最长为11
    QValidator *validatorContactsPhone = new QRegExpValidator(regx,ui->le_contacterPhone);
    ui->le_contacterPhone->setValidator(validatorContactsPhone);
    ui->le_contacterPhone->setMaxLength(11);
}

AddEmploymentInfo::~AddEmploymentInfo()
{
    delete ui;
}

bool AddEmploymentInfo::dealWithLineEditIsNull()
{
    //账号判空提示(这里可以优化下)
    if(ui->le_ability->text().isEmpty() || ui->le_company->text().isEmpty()
            || ui->le_contacterName->text().isEmpty() || ui->le_contacterPhone->text().isEmpty() || ui->le_post->text().isEmpty()
            || ui->le_salary->text().isEmpty() || ui->le_stuClass->text().isEmpty() || ui->le_stuJiuYeDate->text().isEmpty()
            || ui->combox_stuMajor->currentText().isEmpty() || ui->le_stuName->text().isEmpty() || ui->le_stuPhone->text().isEmpty()
            || ui->le_stuNumber->text().isEmpty())
    {
        return true;
    }
    return false;
}

void AddEmploymentInfo::initComboxItem()
{
    //一，省信息
    ui->combox_subProvince->clear();
    ui->combox_subCity->clear();

    QSqlQuery cityQuery(db);
    cityQuery.prepare("select distinct province from city");
    if(cityQuery.exec()){
        QStringList provinces;
        while (cityQuery.next()){
            provinces << cityQuery.value("province").toString();
        }
        ui->combox_subProvince->addItems(provinces); //添加省
    }

    //二，院系信息
    ui->combox_faculty->clear();
    ui->combox_stuMajor->clear();

    QSqlQuery facultyQuery(db);
    facultyQuery.prepare("select distinct faculty from major");
    if(facultyQuery.exec()){
        QStringList facultys;
        while (facultyQuery.next()){
            facultys << facultyQuery.value("faculty").toString();
        }
        cout <<facultys.count();
        ui->combox_faculty->addItems(facultys); //添加院系
    }
}

void AddEmploymentInfo::saveStudentToDB(QSqlDatabase &db)
{
    QString jobTime = ui->le_stuJiuYeDate->text();      //就业时间
    QString companyName = ui->le_company->text();       //公司名称
    QString jobPost = ui->le_post->text();    //就业岗位

    VariableSet::Student stu;
    stu.StuNumber = ui->le_stuNumber->text();   //学号
    stu.StuClass = ui->le_stuClass->text();     //班级
    stu.StuName = ui->le_stuName->text();       //学生姓名
    if(ui->rbtn_man->isChecked()){
        stu.StuSex = ui->rbtn_man->text();      //学生性别(男),默认
    }else{
        stu.StuSex = ui->rbtn_woman->text();    //学生性别(女)
    }
    stu.Major = ui->combox_stuMajor->currentText();     //学生专业
    stu.StuPhone = ui->le_stuPhone->text();     //学生联系电话

    //就业学生信息保存到数据库
    if(!jobTime.isEmpty()&&!companyName.isEmpty()&&!jobPost.isEmpty()){
        //说明该学生已就业
        stu.JobTime = jobTime;      //就业时间
        stu.CompanyName = companyName;  //就业公司名称
        stu.JobPost = jobPost;          //就业岗位
    }

    //未就业学生信息保存数据库(因为是添加就业信息子界面,所以这不太可能会执行,因为就业嘛)
    if(jobTime.isEmpty()&&companyName.isEmpty()&&jobPost.isEmpty()){
        //说明该学生未就业
        stu.JobTime = Q_NULLPTR;      //就业时间(未就业填空)
        stu.CompanyName = Q_NULLPTR;  //就业公司名称(未就业填空)
        stu.JobPost = Q_NULLPTR;          //就业岗位(未就业填空)
    }
    //保存该学生的信息到数据库
    QSqlQuery stuQuery(db);
    stuQuery.prepare("insert into student (stuNumber,stuClass,stuName,stuSex,stuMajor,stuPhone,jobTime,companyName,jobPost)"
                     "values(?,?,?,?,?,?,?,?,?)");
    stuQuery.bindValue(0,stu.StuNumber);
    stuQuery.bindValue(1,stu.StuClass);
    stuQuery.bindValue(2,stu.StuName);
    stuQuery.bindValue(3,stu.StuSex);
    stuQuery.bindValue(4,stu.Major);
    stuQuery.bindValue(5,stu.StuPhone);
    stuQuery.bindValue(6,stu.JobTime);
    stuQuery.bindValue(7,stu.CompanyName);
    stuQuery.bindValue(8,stu.JobPost);
    if(stuQuery.exec()){
        if(stu.JobPost.isEmpty()){
            Warning::setInformation(QStringLiteral("保存未就业学生信息成功"));//这里几乎不可能执行！！！
            cout << QStringLiteral("保存未就业学生信息成功");
        }else{
            Warning::setInformation(QStringLiteral("保存就业学生信息成功"));
            cout << QStringLiteral("保存就业学生信息成功");
        }
    }
}

void AddEmploymentInfo::saveCompanyToDB(QSqlDatabase &db)
{
    VariableSet::Company com;
    com.CompanySide = ui->combox_subProvince->currentText()+ui->combox_subCity->currentText();    //就业城市
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
        Warning::setInformation(QStringLiteral("保存公司信息成功"));
        cout << QStringLiteral("保存公司信息成功");
    }
}

void AddEmploymentInfo::on_btn_reset_clicked()
{
    //重置
    ui->le_ability->clear();
    ui->combox_subProvince->setCurrentIndex(0);
    ui->combox_faculty->setCurrentIndex(0);
    ui->le_contacterName->clear();
    ui->le_contacterPhone->clear();
    ui->le_post->clear();
    ui->le_salary->clear();
    ui->le_stuClass->clear();
    ui->le_stuJiuYeDate->clear();
//    ui->combox_stuMajor->setCurrentIndex(0);
    ui->le_stuName->clear();
    ui->le_stuPhone->clear();
    ui->le_company->clear();
    ui->le_stuNumber->clear();
    ui->rbtn_man->setChecked(true);
    ui->rbtn_woman->setChecked(false);
}

void AddEmploymentInfo::on_btn_submit_clicked()
{
    //账号判空提示
    if(dealWithLineEditIsNull() == false){
        //提交学生信息部分
        VariableSet::Stu_Company stuCom;
        stuCom.StuNumber = ui->le_stuNumber->text();   //学生学号
        stuCom.StuClass = ui->le_stuClass->text();     //学生班级
        stuCom.StuName = ui->le_stuName->text();       //学生姓名
        if(ui->rbtn_man->isChecked()){
            stuCom.StuSex = ui->rbtn_man->text();      //学生性别(男)
        }else{
            stuCom.StuSex = ui->rbtn_woman->text();
        }
        stuCom.Major = ui->combox_stuMajor->currentText();         //学生专业
        stuCom.StuPhone = ui->le_stuPhone->text();                 //学生联系电话
        stuCom.JobTime = ui->le_stuJiuYeDate->text();              //学生就业日期
        stuCom.CompanyName = ui->le_company->text();               //与学生就业时间同存在的公司名称
        stuCom.CompanySide = ui->combox_subProvince->currentText() + ui->combox_subCity->currentText();//公司城市
        stuCom.Contacts = ui->le_contacterName->text();        //公司联系人
        stuCom.ContactsPhone = ui->le_contacterPhone->text();  //公司联系电话
        stuCom.JobPost = ui->le_post->text();              //就业岗位
        stuCom.Salary = ui->le_salary->text();             //薪资
        stuCom.AbilityRecquire = ui->le_ability->text();   //能力描述

        //判断数据库中是否存在该学生的就业信息
        QSqlQuery judge(db);
        judge.prepare("select stuNumber from stu_company where stuNumber=?");
        judge.bindValue(0,stuCom.StuNumber);
        if(judge.exec()){
            QStringList tmp;
            while (judge.next()){
                tmp << judge.value("stuNumber").toString();
            }
            if(tmp.size() != 0){
                Warning::setWarning(QStringLiteral("该学生已就业哈"));
                return;
            }
        }

        //提交到数据库中
        QSqlQuery stuComQuery(db);
        stuComQuery.prepare("insert into stu_company (stuNumber,stuClass,stuName,stuSex,stuMajor,stuPhone,jobTime,companyName,companySide"
                         ",contacts,contactsPhone,jobPost,salary,abilityRecquire)values(?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
        stuComQuery.bindValue(0,stuCom.StuNumber);
        stuComQuery.bindValue(1,stuCom.StuClass);
        stuComQuery.bindValue(2,stuCom.StuName);
        stuComQuery.bindValue(3,stuCom.StuSex);
        stuComQuery.bindValue(4,stuCom.Major);
        stuComQuery.bindValue(5,stuCom.StuPhone);
        stuComQuery.bindValue(6,stuCom.JobTime);
        stuComQuery.bindValue(7,stuCom.CompanyName);
        stuComQuery.bindValue(8,stuCom.CompanySide);
        stuComQuery.bindValue(9,stuCom.Contacts);
        stuComQuery.bindValue(10,stuCom.ContactsPhone);
        stuComQuery.bindValue(11,stuCom.JobPost);
        stuComQuery.bindValue(12,stuCom.Salary);
        stuComQuery.bindValue(13,stuCom.AbilityRecquire);
        if(stuComQuery.exec()){
            emit sig_employmentInfo(stuCom);   //向主界面发送信号(学号为主键，所以这里不会重复发送)
            Warning::setInformation(QStringLiteral("提交学生-公司信息成功"));
        }else{
            Warning::setInformation(QStringLiteral("执行保存就业信息的SQL语句失败！"));
            return;
            cout << QStringLiteral("该学生已提交过了");
        }

        //学生就业情况信息保存(就业/未就业)
        saveStudentToDB(db);

        //公司情况信息保存
        saveCompanyToDB(db);

    }else{
        Warning::setInformation("有文本框为空");
        return;
    }
}

void AddEmploymentInfo::on_combox_faculty_currentTextChanged(const QString &arg1)
{
    ui->combox_stuMajor->clear();

    QSqlQuery majorQuery(db);
    majorQuery.prepare("select stuMajor from major where faculty=?");
    majorQuery.bindValue(0,arg1);
    if(majorQuery.exec()){
        QStringList majors;
        while (majorQuery.next()){
            majors << majorQuery.value("stuMajor").toString();
        }
        ui->combox_stuMajor->addItems(majors);  //添加专业
    }
}

void AddEmploymentInfo::on_combox_subProvince_currentTextChanged(const QString &arg1)
{
    ui->combox_subCity->clear();

    QSqlQuery queryTown(db);
    queryTown.prepare("select town from city where province=?");
    queryTown.bindValue(0,arg1);
    if(queryTown.exec()){
        QStringList towns;
        while (queryTown.next()){
            towns << queryTown.value("town").toString();
        }
        ui->combox_subCity->addItems(towns);   //添加城市
    }
}
