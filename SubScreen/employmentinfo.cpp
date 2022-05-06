#include "employmentinfo.h"
#include "ui_employmentinfo.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

EmploymentInfo::EmploymentInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmploymentInfo)
{
    ui->setupUi(this);
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    addEmInfo = Q_NULLPTR;

    //加载数据库的数据到本地
    //loadDBToLocal();

    //设置表头
    setTableWidgetHeader();

    //初始化表格的样式
    initTableWidgetType();

    //先把本地已有的数据加载到表格中
    //insertDataToTableWidget();

    initComboxItem();

    //flushTableRows(1);

    QRegExp regx("[0-9]+$");    //限制只能输入数字
    QValidator *validator = new QRegExpValidator(regx,ui->le_class);
    ui->le_class->setValidator(validator);
    ui->le_class->setMaxLength(8); //班级长度最长为8
}

EmploymentInfo::~EmploymentInfo()
{
    delete ui;
}

void EmploymentInfo::loadDBToLocal()
{
    //判断数据记录是否有更新,未更新直接退出
    flag = judgeDataIsChange();
    if(flag == true){
        cout << "数据未更新";
        return;
    }

    //加载学生公司信息到本地
    stuComInfo.clear();    //每次加载到本地时，对本地学生公司数据进行清零

    QSqlQuery queryStu(db);
    queryStu.prepare("select * from stu_company");
    if(queryStu.exec())
    {
        while(queryStu.next())
        {
            VariableSet::Stu_Company stuCom;
            stuCom.StuNumber = queryStu.value("stuNumber").toString();
            stuCom.StuClass = queryStu.value("stuClass").toString();
            stuCom.StuName = queryStu.value("stuName").toString();
            stuCom.StuSex = queryStu.value("stuSex").toString();
            stuCom.Major = queryStu.value("stuMajor").toString();
            stuCom.StuPhone = queryStu.value("stuPhone").toString();
            stuCom.JobTime = queryStu.value("jobTime").toString();
            stuCom.CompanyName = queryStu.value("companyName").toString();
            stuCom.CompanySide = queryStu.value("companySide").toString();
            stuCom.Contacts = queryStu.value("contacts").toString();
            stuCom.ContactsPhone = queryStu.value("contactsPhone").toString();
            stuCom.JobPost = queryStu.value("jobPost").toString();
            stuCom.Salary = queryStu.value("salary").toString();
            stuCom.AbilityRecquire = queryStu.value("abilityRecquire").toString();
            stuComInfo.push_back(stuCom);
        }
        //cout << stuInfo.size();
    }else{
        Warning::setWarning(QStringLiteral("访问SEMS中的学生公司信息表失败"));
        cout << QStringLiteral("访问SEMS中的学生公司信息表失败");
    }
}

void EmploymentInfo::setTableWidgetHeader()
{
    //设置表头
    QTableWidgetItem *headerItem;
    QStringList headerList;
    headerList <<QStringLiteral("学号")<<QStringLiteral("班级")
                   <<QStringLiteral("姓名")<<QStringLiteral("性别")
                   <<QStringLiteral("专业")<<QStringLiteral("联系电话")
                   <<QStringLiteral("就业时间")<<QStringLiteral("公司名称")
                   <<QStringLiteral("公司地点")<<QStringLiteral("公司联系人")
                   <<QStringLiteral("公司联系人电话")<<QStringLiteral("就业岗位")
                   <<QStringLiteral("新资")<<QStringLiteral("能力需求");
    ui->tableWidget_workInfo->setColumnCount(headerList.count());
    for(int i = 0;i<headerList.count();++i)
    {
        headerItem = new QTableWidgetItem(headerList.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
        //font.setPointSize(10);
        //headerItem->setTextColor(Qt::black);
        headerItem->setFont(font);
        ui->tableWidget_workInfo->setHorizontalHeaderItem(i,headerItem);
    }
}

void EmploymentInfo::initComboxItem()
{
//    cityInfo.clear();
    //一，省信息
    ui->combox_province->clear();
    ui->combox_city->clear();

    QSqlQuery cityQuery(db);
    cityQuery.prepare("select distinct province from city");
    if(cityQuery.exec()){
        QStringList provinces;
        while (cityQuery.next()){
            provinces << cityQuery.value("province").toString();
        }
        ui->combox_province->addItems(provinces);
    }

    //二，院系信息
    ui->combox_faculty->clear();
    ui->combox_major->clear();

    QSqlQuery facultyQuery(db);
    facultyQuery.prepare("select distinct faculty from major");
    if(facultyQuery.exec()){
        QStringList facultys;
        while (facultyQuery.next()){
            facultys << facultyQuery.value("faculty").toString();
        }
        //cout <<facultys.count();
        ui->combox_faculty->addItems(facultys); //添加院系
    }
}

void EmploymentInfo::initTableWidgetType()
{
    //表格自适应
    //ui->tableWidget_workInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_workInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //隐藏第一列表头
    ui->tableWidget_workInfo->verticalHeader()->setHidden(true);

    //自动调整所有列的宽度，以适应其内容
    ui->tableWidget_workInfo->resizeColumnsToContents();

    //表格不可编辑
    ui->tableWidget_workInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //隔行显示颜色
    ui->tableWidget_workInfo->setAlternatingRowColors(true);

    //设置鼠标跟踪
    ui->tableWidget_workInfo->setMouseTracking(true);
    connect(ui->tableWidget_workInfo,SIGNAL(entered(QModelIndex)),this,SLOT(slot_showTableItemToolTip(QModelIndex)));
}

void EmploymentInfo::insertDataToTableWidget()
{
    //判断数据记录是否有更新,
    if(flag == true){
        cout << "数据未更新";
        return;
    }

    //先清除表内容，并设置行为0行
    ui->tableWidget_workInfo->clearContents();
    ui->tableWidget_workInfo->setRowCount(0);

    ui->tableWidget_workInfo->setRowCount(stuComInfo.count());
    int row = ui->tableWidget_workInfo->rowCount();

    //插入数据到表格中
    for(int i=0;i<row;++i){
        //插入学生-公司信息
        VariableSet::Stu_Company stuCom = stuComInfo.at(i);

        //表格添加项
        ui->tableWidget_workInfo->setItem(i,0,new QTableWidgetItem(stuCom.StuNumber));
        ui->tableWidget_workInfo->setItem(i,1,new QTableWidgetItem(stuCom.StuClass));
        ui->tableWidget_workInfo->setItem(i,2,new QTableWidgetItem(stuCom.StuName));
        ui->tableWidget_workInfo->setItem(i,3,new QTableWidgetItem(stuCom.StuSex));
        ui->tableWidget_workInfo->setItem(i,4,new QTableWidgetItem(stuCom.Major));
        ui->tableWidget_workInfo->setItem(i,5,new QTableWidgetItem(stuCom.StuPhone));
        ui->tableWidget_workInfo->setItem(i,6,new QTableWidgetItem(stuCom.JobTime));
        ui->tableWidget_workInfo->setItem(i,7,new QTableWidgetItem(stuCom.CompanyName));
        ui->tableWidget_workInfo->setItem(i,8,new QTableWidgetItem(stuCom.CompanySide));
        ui->tableWidget_workInfo->setItem(i,9,new QTableWidgetItem(stuCom.Contacts));
        ui->tableWidget_workInfo->setItem(i,10,new QTableWidgetItem(stuCom.ContactsPhone));
        ui->tableWidget_workInfo->setItem(i,11,new QTableWidgetItem(stuCom.JobPost));
        ui->tableWidget_workInfo->setItem(i,12,new QTableWidgetItem(stuCom.Salary));
        ui->tableWidget_workInfo->setItem(i,13,new QTableWidgetItem(stuCom.AbilityRecquire));

        //表格项对齐方式
        ui->tableWidget_workInfo->item(i,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,5)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,6)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,7)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,8)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,9)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,10)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,11)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,12)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_workInfo->item(i,13)->setTextAlignment(Qt::AlignCenter);      //能力需求描述太长，所以居左对齐
    }

    flushTableRows(1);
    //ui->tableWidget_workInfo->resizeColumnsToContents();
}

void EmploymentInfo::flushTableRows(int curRow)
{
    int n = ui->tableWidget_workInfo->rowCount();
    int cur;
    if(n>0){
        cur = curRow;
    }else{
        cur = 0;
    }

    QString str = QString("记录数共 %1 行，当前第 %2 行").arg(n).arg(cur);
    ui->label_showRow->setText(str);
}

bool EmploymentInfo::judgeDataIsChange()
{
    QSqlQuery curSizeQuery(db);
    curSizeQuery.prepare("select stuNumber from stu_company");
    if(curSizeQuery.exec()){
        QStringList curSize;
        while (curSizeQuery.next()){
            curSize << curSizeQuery.value("stuNumber").toString();
        }
        if(stuComInfo.size() == curSize.size()){
            //数据库学生公司就业信息没有更新，不用加载到本地，因为这次记录和上次一样(省时操作,以免每次读取数据库)
            return true;
        }
    }
    return false;
}

void EmploymentInfo::slot_showTableItemToolTip(QModelIndex index)
{
    QToolTip::showText(QCursor::pos(),index.data().toString());
}

void EmploymentInfo::slot_tableWidgetAddItem(VariableSet::Stu_Company &stuCom)
{
    //从添加用户子界面传回的学生公司信息
    int row = ui->tableWidget_workInfo->rowCount();
    ui->tableWidget_workInfo->insertRow(row);

    //表格添加项
    ui->tableWidget_workInfo->setItem(row,0,new QTableWidgetItem(stuCom.StuNumber));
    ui->tableWidget_workInfo->setItem(row,1,new QTableWidgetItem(stuCom.StuClass));
    ui->tableWidget_workInfo->setItem(row,2,new QTableWidgetItem(stuCom.StuName));
    ui->tableWidget_workInfo->setItem(row,3,new QTableWidgetItem(stuCom.StuSex));
    ui->tableWidget_workInfo->setItem(row,4,new QTableWidgetItem(stuCom.Major));
    ui->tableWidget_workInfo->setItem(row,5,new QTableWidgetItem(stuCom.StuPhone));
    ui->tableWidget_workInfo->setItem(row,6,new QTableWidgetItem(stuCom.JobTime));
    ui->tableWidget_workInfo->setItem(row,7,new QTableWidgetItem(stuCom.CompanyName));
    ui->tableWidget_workInfo->setItem(row,8,new QTableWidgetItem(stuCom.CompanySide));
    ui->tableWidget_workInfo->setItem(row,9,new QTableWidgetItem(stuCom.Contacts));
    ui->tableWidget_workInfo->setItem(row,10,new QTableWidgetItem(stuCom.ContactsPhone));
    ui->tableWidget_workInfo->setItem(row,11,new QTableWidgetItem(stuCom.JobPost));
    ui->tableWidget_workInfo->setItem(row,12,new QTableWidgetItem(stuCom.Salary));
    ui->tableWidget_workInfo->setItem(row,13,new QTableWidgetItem(stuCom.AbilityRecquire));

    //表格项对齐方式
    ui->tableWidget_workInfo->item(row,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,1)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,2)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,3)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,4)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,5)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,6)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,7)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,8)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,9)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,10)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,11)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,12)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_workInfo->item(row,13)->setTextAlignment(Qt::AlignLeft);      //能力需求描述太长，所以居左对齐

    //flushTableRows(ui->tableWidget_workInfo->currentRow());
}

void EmploymentInfo::on_btn_addEmploymentInfo_clicked()
{
    if(addEmInfo == Q_NULLPTR)
    {
        addEmInfo = new AddEmploymentInfo;
    }
    connect(addEmInfo,SIGNAL(sig_employmentInfo(VariableSet::Stu_Company &))
            ,this,SLOT(slot_tableWidgetAddItem(VariableSet::Stu_Company &)));
    addEmInfo->setWindowModality(Qt::WindowModal);
    addEmInfo->move(this->width()/10,this->height()/3);
    addEmInfo->show();
}

void EmploymentInfo::on_btn_reset_clicked()
{
    ui->combox_province->setCurrentIndex(0);
//    ui->combox_city->setCurrentIndex(0);
    ui->combox_faculty->setCurrentIndex(0);
    ui->le_class->clear();
    ui->le_company->clear();
    ui->combox_major->setCurrentIndex(0);
    ui->le_post->clear();
    ui->rbtn_male->setChecked(true);
    for (int i = 0; i < ui->tableWidget_workInfo->rowCount(); ++i){
        ui->tableWidget_workInfo->setRowHidden(i,false);
    }
}

void EmploymentInfo::on_combox_province_currentTextChanged(const QString &arg1)
{
    ui->combox_city->clear();

    QSqlQuery majorQuery(db);
    majorQuery.prepare("select town from city where province=?");
    majorQuery.bindValue(0,arg1);
    if(majorQuery.exec()){
        QStringList towns;
        while (majorQuery.next()){
            towns << majorQuery.value("town").toString();
        }
        ui->combox_city->addItems(towns);
    }
}

void EmploymentInfo::on_btn_query_clicked()
{
    QString major = ui->combox_major->currentText();
    QString city = ui->combox_province->currentText()+ui->combox_city->currentText();
    QString sex;
    if(ui->rbtn_male->isChecked()){
        sex = ui->rbtn_male->text();
    }
    if(ui->rbtn_female->isChecked()){
        sex = ui->rbtn_female->text();
    }
    QString stuClass = ui->le_class->text();
    QString company = ui->le_company->text();
    QString post = ui->le_post->text();

    //先隐藏所有行
    int rows = ui->tableWidget_workInfo->rowCount();
    for (int i = 0; i < rows; ++i){
        ui->tableWidget_workInfo->setRowHidden(i,true);
    }

    if(major != QStringLiteral("请选择")){
        //专业不为空
        QList<QTableWidgetItem*> item = ui->tableWidget_workInfo->findItems(major,Qt::MatchExactly);
        if(!item.isEmpty()){
            for (int i = 0; i < item.count(); ++i){
                ui->tableWidget_workInfo->setRowHidden(item.at(i)->row(),false);
                cout << item.at(i)->row();
            }
        }
        return;
    }

    if(city != QStringLiteral("请选择请选择")){
        //中了城市
        QList<QTableWidgetItem*> item = ui->tableWidget_workInfo->findItems(city,Qt::MatchExactly);
        if(!item.isEmpty()){
            for (int i = 0; i < item.count(); ++i){
                ui->tableWidget_workInfo->setRowHidden(item.at(i)->row(),false);
                cout << item.at(i)->row();
            }
        }
        return;
    }

    if(!stuClass.isEmpty()){
        //班级不为空
        QList<QTableWidgetItem*> item = ui->tableWidget_workInfo->findItems(stuClass,Qt::MatchExactly);
        cout << item.count();
        if(!item.isEmpty()){
            for (int i = 0; i < item.count(); ++i){
                ui->tableWidget_workInfo->setRowHidden(item.at(i)->row(),false);
                cout << item.at(i)->row();
            }
        }
        return;
    }

    if(!company.isEmpty()){
        //公司名称不为空
        QList<QTableWidgetItem*> item = ui->tableWidget_workInfo->findItems(company,Qt::MatchExactly);
        if(!item.isEmpty()){
            for (int i = 0; i < item.count(); ++i){
                ui->tableWidget_workInfo->setRowHidden(item.at(i)->row(),false);
                cout << item.at(i)->row();
            }
        }
        return;
    }

    if(!post.isEmpty()){
        //就业岗位不为空
        QList<QTableWidgetItem*> item = ui->tableWidget_workInfo->findItems(post,Qt::MatchExactly);
        if(!item.isEmpty()){
            for (int i = 0; i < item.count(); ++i){
                ui->tableWidget_workInfo->setRowHidden(item.at(i)->row(),false);
                cout << item.at(i)->row();
            }
        }
        return;
    }

    {
        //选中了性别
        QList<QTableWidgetItem*> item = ui->tableWidget_workInfo->findItems(sex,Qt::MatchExactly);
        if(!item.isEmpty()){
            for (int i = 0; i < item.count(); ++i){
                ui->tableWidget_workInfo->setRowHidden(item.at(i)->row(),false);
                cout << item.at(i)->row();
            }
        }
        return;
    }
}

void EmploymentInfo::on_combox_faculty_currentTextChanged(const QString &arg1)
{
    ui->combox_major->clear();

    QSqlQuery majorQuery(db);
    majorQuery.prepare("select stuMajor from major where faculty=?");
    majorQuery.bindValue(0,arg1);
    if(majorQuery.exec()){
        QStringList majors;
        while (majorQuery.next()){
            majors << majorQuery.value("stuMajor").toString();
        }
        ui->combox_major->addItems(majors);
    }
}

void EmploymentInfo::on_btn_saveToExcel_clicked()
{
    ThreadOperateExcel::getInstance()->tabSaveToExcel(ui->tableWidget_workInfo,QStringLiteral("就业信息表"));
}

void EmploymentInfo::on_tableWidget_workInfo_clicked(const QModelIndex &index)
{
    int cur = index.row()+1;
    flushTableRows(cur);
}
