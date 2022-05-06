#include "addstudent.h"
#include "ui_addstudent.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

AddStudent::AddStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudent)
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
}

AddStudent::~AddStudent()
{
    delete ui;
}

bool AddStudent::dealWithLineEditIsNull()
{
    //账号判空提示(这里可以优化下)
    //ui->le_company->text().isEmpty()|| ui->le_post->text().isEmpty()|| ui->le_stuJiuYeDate->text().isEmpty()
    if(ui->le_stuClass->text().isEmpty() || ui->combox_stuMajor->currentText().isEmpty()
            || ui->le_stuName->text().isEmpty() || ui->le_stuPhone->text().isEmpty()
            || ui->le_stuNumber->text().isEmpty())
    {
        return true;
    }
    return false;
}

void AddStudent::saveStudentToDB(QSqlDatabase &db)
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

    //就业学生信息保存
    if(!jobTime.isEmpty()&&!companyName.isEmpty()&&!jobPost.isEmpty()){
        //说明该学生已就业
        stu.JobTime = jobTime;      //就业时间
        stu.CompanyName = companyName;  //就业公司名称
        stu.JobPost = jobPost;          //就业岗位

        //保存该就业学生的信息
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
            Warning::setInformation(QStringLiteral("保存就业学生信息成功"));
        }
    }

    //未就业学生信息保存(因为是添加就业信息子界面,所以这不太可能会执行,因为就业嘛)
    if(jobTime.isEmpty()&&companyName.isEmpty()&&jobPost.isEmpty()){
        //说明该学生未就业
        stu.JobTime = Q_NULLPTR;      //就业时间(未就业填空)
        stu.CompanyName = Q_NULLPTR;  //就业公司名称(未就业填空)
        stu.JobPost = Q_NULLPTR;          //就业岗位(未就业填空)

        //保存该就业学生的信息
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
            Warning::setInformation(QStringLiteral("保存未就业学生信息成功"));
        }
    }

    emit sig_studentInfo(stu);   //向主界面发送信号(学号为主键，所以这里不会重复发送)
}

void AddStudent::initComboxItem()
{
    //一，院系信息
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

void AddStudent::resetStuNameAndStuNumber()
{
    quint8 id = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/IDENTITY").toInt();
    if(id==1){
        //学生身份
        QString stuNum = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/ACCOUNT").toString();
        QSqlQuery nameQuery(db);
        nameQuery.prepare("select userName from user where account=?");
        nameQuery.bindValue(0,stuNum);
        QStringList name;
        if(nameQuery.exec()){
            while (nameQuery.next()){
                name << nameQuery.value("userName").toString();
            }
        }else{
            Warning::setWarning(QStringLiteral("数据库查询学生姓名失败"));
            return;
        }
        ui->le_stuName->setText(name.at(0));
        ui->le_stuNumber->setText(stuNum);
        ui->le_stuName->setEnabled(false);
        ui->le_stuNumber->setEnabled(false);
    }else{
        ui->le_stuName->clear();
        ui->le_stuNumber->clear();
    }
}

void AddStudent::on_btn_submit_clicked()
{
    //账号判空提示
    if(dealWithLineEditIsNull() == false){
        QString stuNumber = ui->le_stuNumber->text();   //学生学号

        //提交前先判断数据库中是否存在该学生信息
        QSqlQuery queryStu(db);
        queryStu.prepare("select stuNumber from student where stuNumber=?");
        queryStu.bindValue(0,stuNumber);
        if(queryStu.exec()){
            QStringList record;
            while (queryStu.next()){
                record << queryStu.value("stuNumber").toString();
            }
            if(record.size()==0){
                //学生就业情况信息保存(就业/未就业)
                saveStudentToDB(db);
            }else{
                //该学生信息存在重复，再添加给予警告
                Warning::setWarning("已存在该学生记录了");
                return;
            }
        }else{
            Warning::setWarning(QStringLiteral("执行查询学生记录SQL语句失败！"));
            return;
        }
    }else{
        Warning::setInformation("有文本框为空");
        return;
    }
}

void AddStudent::on_btn_reset_clicked()
{
    //重置为空
    ui->le_post->clear();
    ui->le_stuClass->clear();
    ui->le_stuJiuYeDate->clear();
    ui->combox_stuMajor->setCurrentIndex(0);

    resetStuNameAndStuNumber();

    ui->le_stuPhone->clear();
    ui->le_company->clear();
    ui->rbtn_man->setChecked(true);
    ui->rbtn_woman->setChecked(false);
}

void AddStudent::on_combox_faculty_currentTextChanged(const QString &arg1)
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
        ui->combox_stuMajor->addItems(majors);
    }
}
