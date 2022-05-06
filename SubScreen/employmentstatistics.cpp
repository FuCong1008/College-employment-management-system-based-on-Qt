#include "employmentstatistics.h"
#include "ui_employmentstatistics.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

EmploymentStatistics::EmploymentStatistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmploymentStatistics)
{
    ui->setupUi(this);
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    //数据库信息加载到本地
    loadDBToLocal();

    //设置表格表头
    QStringList headerList;
    headerList <<QStringLiteral("学生专业")<<QStringLiteral("就业人数");
    setTableWidgetHeader(headerList);

    //初始化表格样式
    initTableWidgetType();

    //默认按专业显示
    on_tbn_major_clicked();
}

EmploymentStatistics::~EmploymentStatistics()
{
    delete ui;
}

void EmploymentStatistics::loadDBToLocal()
{
    //加载学生就业公司信息到本地
    stuComInfo.clear();    //每次加载到本地时，对本地学生就业公司数据进行清零

    QSqlQuery stuComquery(db);
    stuComquery.prepare("select * from stu_company");
    if(stuComquery.exec())
    {
        while(stuComquery.next())
        {
            VariableSet::Stu_Company stuCom;
            stuCom.StuNumber = stuComquery.value("stuNumber").toString();
            stuCom.StuClass = stuComquery.value("stuClass").toString();
            stuCom.StuName = stuComquery.value("stuName").toString();
            stuCom.StuSex = stuComquery.value("stuSex").toString();
            stuCom.Major = stuComquery.value("stuMajor").toString();
            stuCom.StuPhone = stuComquery.value("stuPhone").toString();
            stuCom.JobTime = stuComquery.value("jobTime").toString();
            stuCom.CompanyName = stuComquery.value("companyName").toString();
            stuCom.CompanySide = stuComquery.value("companySide").toString();
            stuCom.Contacts = stuComquery.value("contacts").toString();
            stuCom.ContactsPhone = stuComquery.value("contactsPhone").toString();
            stuCom.JobPost = stuComquery.value("jobPost").toString();
            stuCom.Salary = stuComquery.value("salary").toString();
            stuCom.AbilityRecquire = stuComquery.value("abilityRecquire").toString();
            stuComInfo.push_back(stuCom);
        }
        //cout << stuComInfo.size();
    }else{
        cout << QStringLiteral("访问SEMS中的学生就业公司信息失败");
    }
}

void EmploymentStatistics::setTableWidgetHeader(QStringList &headerList)
{
    QTableWidgetItem *headerItem;
    ui->tableWidget_stastics->setColumnCount(headerList.count());
    for(int i = 0;i<headerList.count();++i)
    {
        headerItem = new QTableWidgetItem(headerList.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
//        font.setPointSize(10);
//        headerItem->setTextColor(Qt::black);
        headerItem->setFont(font);
        ui->tableWidget_stastics->setHorizontalHeaderItem(i,headerItem);
    }
}

void EmploymentStatistics::initTableWidgetType()
{
    //表格自适应
    ui->tableWidget_stastics->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //隐藏第一列表头
    ui->tableWidget_stastics->verticalHeader()->setHidden(true);

    //自动调整所有列的宽度，以适应其内容
    ui->tableWidget_stastics->resizeColumnsToContents();

    //表格不可编辑
    ui->tableWidget_stastics->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //隔行显示颜色
    ui->tableWidget_stastics->setAlternatingRowColors(true);

    //设置鼠标跟踪
    ui->tableWidget_stastics->setMouseTracking(true);
    connect(ui->tableWidget_stastics,SIGNAL(entered(QModelIndex)),this,SLOT(slot_showTableItemToolTip(QModelIndex)));
}

QMap<QString, int> EmploymentStatistics::countEmploymentStatus(QStringList &strInfo)
{
    QMap<QString,int> map;
    for (int i = 0; i < strInfo.count(); ++i){
        if(map.keys().contains(strInfo.at(i))){
            int k = map.value(strInfo.at(i));
            ++k;
            map.remove(strInfo.at(i));
            map.insert(strInfo.at(i),k);
        }else{
            //不包含
            map.insert(strInfo.at(i),1);
        }
    }
    return map;
}

void EmploymentStatistics::insertButtonToTable(int &row)
{
    QPushButton *lookBtn = new QPushButton(tr("查看详情"));
    lookBtn->setMinimumHeight(ui->tableWidget_stastics->rowHeight(0));
    lookBtn->setWhatsThis(QString::number(row));
    connect(lookBtn,SIGNAL(clicked()),this,SLOT(slot_btn_lookDetail_clicked()));
    QHBoxLayout *hlay = new QHBoxLayout();
    hlay->addStretch(1);
    hlay->addWidget(lookBtn);
    hlay->addStretch(1);
    hlay->setMargin(0);

    QWidget *tmp = new QWidget(this);
    tmp->setLayout(hlay);
    ui->tableWidget_stastics->setCellWidget(row,2,tmp);
}

void EmploymentStatistics::slot_showTableItemToolTip(QModelIndex index)
{
    QToolTip::showText(QCursor::pos(),index.data().toString());
}

void EmploymentStatistics::slot_btn_lookDetail_clicked()
{
    QPushButton *pSenderBtn = qobject_cast<QPushButton*>(sender());
    if(pSenderBtn == Q_NULLPTR){
        cout << QStringLiteral("失败！");
        return;
    }
    //cout << pSenderBtn->whatsThis() <<QStringLiteral("查看详情按钮被点击");
    int curRow = pSenderBtn->whatsThis().toInt();
    cout << ui->tableWidget_stastics->item(curRow,0)->text();
}

void EmploymentStatistics::on_tbn_major_clicked()
{
    //按专业统计
    QStringList headerList;
    headerList <<QStringLiteral("学生专业")<<QStringLiteral("就业人数")<<QStringLiteral("操作");
    setTableWidgetHeader(headerList);

    QStringList stuMajors;
    for (int i = 0; i < stuComInfo.count(); ++i){
        stuMajors <<stuComInfo.at(i).Major;
    }

    ui->tableWidget_stastics->setRowCount(0);
    QMap<QString,int> map = countEmploymentStatus(stuMajors);
    for (int row = 0; row < map.count(); row++){
        QString str = map.keys().at(row);
        int count = map.value(str);
        ui->tableWidget_stastics->insertRow(row);
        ui->tableWidget_stastics->setItem(row,0,new QTableWidgetItem(str));
        ui->tableWidget_stastics->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_stastics->setItem(row,1,new QTableWidgetItem(QString::number(count)));
        ui->tableWidget_stastics->item(row,1)->setTextAlignment(Qt::AlignCenter);
        insertButtonToTable(row);
    }
}

void EmploymentStatistics::on_tbn_class_clicked()
{
    //按班级统计
    QStringList headerList;
    headerList <<QStringLiteral("学生班级")<<QStringLiteral("就业人数")<<QStringLiteral("操作");
    setTableWidgetHeader(headerList);

    QStringList stuClasses;
    for (int i = 0; i < stuComInfo.count(); ++i){
        stuClasses <<stuComInfo.at(i).StuClass;
    }

    ui->tableWidget_stastics->setRowCount(0);
    QMap<QString,int> map = countEmploymentStatus(stuClasses);
    for (int row = 0; row < map.count(); ++row){
        QString str = map.keys().at(row);
        int count = map.value(str);
        ui->tableWidget_stastics->insertRow(row);
        ui->tableWidget_stastics->setItem(row,0,new QTableWidgetItem(str));
        ui->tableWidget_stastics->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_stastics->setItem(row,1,new QTableWidgetItem(QString::number(count)));
        ui->tableWidget_stastics->item(row,1)->setTextAlignment(Qt::AlignCenter);
        insertButtonToTable(row);
    }
}

void EmploymentStatistics::on_tbn_post_clicked()
{
    //按岗位统计
    QStringList headerList;
    headerList <<QStringLiteral("就业岗位")<<QStringLiteral("就业人数")<<QStringLiteral("操作");
    setTableWidgetHeader(headerList);

    QStringList jobPostes;
    for (int i = 0; i < stuComInfo.count(); ++i){
        jobPostes <<stuComInfo.at(i).JobPost;
    }

    ui->tableWidget_stastics->setRowCount(0);
    QMap<QString,int> map = countEmploymentStatus(jobPostes);
    for (int row = 0; row < map.count(); ++row){
        QString str = map.keys().at(row);
        int count = map.value(str);
        ui->tableWidget_stastics->insertRow(row);
        ui->tableWidget_stastics->setItem(row,0,new QTableWidgetItem(str));
        ui->tableWidget_stastics->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_stastics->setItem(row,1,new QTableWidgetItem(QString::number(count)));
        ui->tableWidget_stastics->item(row,1)->setTextAlignment(Qt::AlignCenter);
        insertButtonToTable(row);
    }
}

void EmploymentStatistics::on_tbn_company_clicked()
{
    //按企业统计
    QStringList headerList;
    headerList <<QStringLiteral("就业单位")<<QStringLiteral("就业人数")<<QStringLiteral("操作");
    setTableWidgetHeader(headerList);
    QStringList cpmpanyes;
    for (int i = 0; i < stuComInfo.count(); ++i){
        cpmpanyes <<stuComInfo.at(i).CompanyName;
    }

    ui->tableWidget_stastics->setRowCount(0);
    QMap<QString,int> map = countEmploymentStatus(cpmpanyes);
    for (int row = 0; row < map.count(); ++row){
        QString str = map.keys().at(row);
        int count = map.value(str);
        ui->tableWidget_stastics->insertRow(row);
        ui->tableWidget_stastics->setItem(row,0,new QTableWidgetItem(str));
        ui->tableWidget_stastics->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_stastics->setItem(row,1,new QTableWidgetItem(QString::number(count)));
        ui->tableWidget_stastics->item(row,1)->setTextAlignment(Qt::AlignCenter);
        insertButtonToTable(row);
    }
}

void EmploymentStatistics::on_tbn_city_clicked()
{
    //按城市统计
    QStringList headerList;
    headerList <<QStringLiteral("就业城市")<<QStringLiteral("就业人数")<<QStringLiteral("操作");
    setTableWidgetHeader(headerList);
    QStringList cpmpanyes;
    for (int i = 0; i < stuComInfo.count(); ++i){
        cpmpanyes <<stuComInfo.at(i).CompanySide;
    }

    ui->tableWidget_stastics->setRowCount(0);
    QMap<QString,int> map = countEmploymentStatus(cpmpanyes);
    for (int row = 0; row < map.count(); ++row){
        QString str = map.keys().at(row);
        int count = map.value(str);
        ui->tableWidget_stastics->insertRow(row);
        ui->tableWidget_stastics->setItem(row,0,new QTableWidgetItem(str));
        ui->tableWidget_stastics->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_stastics->setItem(row,1,new QTableWidgetItem(QString::number(count)));
        ui->tableWidget_stastics->item(row,1)->setTextAlignment(Qt::AlignCenter);
        insertButtonToTable(row);
    }
}
