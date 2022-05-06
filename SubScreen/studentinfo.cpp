#include "studentinfo.h"
#include "ui_studentinfo.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

StudentInfo::StudentInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    addStu = Q_NULLPTR;

    loadDBStudentInfoToLocal();

    setTableWidgetHeader();

    initTableWidgetType();

    insertDataToTableWidget();

    flushTableRows(1);

    initRightMenu();
}

StudentInfo::~StudentInfo()
{
    delete ui;
}

void StudentInfo::loadDBStudentInfoToLocal()
{
    //加载学生信息到本地
    stuInfo.clear();    //每次加载到本地时，对本地学生数据进行清零

    QSqlQuery studentQuery(db);
    studentQuery.prepare("select * from student");
    if(studentQuery.exec())
    {
        while(studentQuery.next())
        {
            VariableSet::Student stu;
            stu.StuNumber = studentQuery.value("stuNumber").toString();
            stu.StuClass = studentQuery.value("stuClass").toString();
            stu.StuName = studentQuery.value("stuName").toString();
            stu.StuSex = studentQuery.value("stuSex").toString();
            stu.Major = studentQuery.value("stuMajor").toString();
            stu.StuPhone = studentQuery.value("stuPhone").toString();
            stu.JobTime = studentQuery.value("jobTime").toString();
            stu.CompanyName = studentQuery.value("companyName").toString();
            stu.JobPost = studentQuery.value("jobPost").toString();
            stuInfo.push_back(stu);
        }
        //cout << stuInfo.size();
    }else{
        cout << QStringLiteral("访问SEMS中的学生信息表失败");
    }
}

void StudentInfo::setTableWidgetHeader()
{
    //设置表头
    QTableWidgetItem *headerItem;
    QStringList headerList;
    headerList <<QStringLiteral("学号")<<QStringLiteral("班级")
                <<QStringLiteral("姓名")<<QStringLiteral("性别")
                <<QStringLiteral("专业")<<QStringLiteral("联系电话")
                <<QStringLiteral("就业时间")<<QStringLiteral("就业公司")
                <<QStringLiteral("就业岗位");
    ui->tableWidget_studentInfo->setColumnCount(headerList.count());
    QStringList headerWhats;
    headerWhats << QStringLiteral("stuNumber") << QStringLiteral("stuClass")  << QStringLiteral("stuName")
                <<QStringLiteral("stuSex") << QStringLiteral("stuMajor")  << QStringLiteral("stuPhone")
                  << QStringLiteral("jobTime")<< QStringLiteral("companyName")<< QStringLiteral("jobPost");
    for(int i = 0;i<headerList.count();++i)
    {
        headerItem = new QTableWidgetItem(headerList.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
        //font.setPointSize(10);
        //headerItem->setTextColor(Qt::black);
        headerItem->setFont(font);
        ui->tableWidget_studentInfo->setHorizontalHeaderItem(i,headerItem);
        ui->tableWidget_studentInfo->horizontalHeaderItem(i)->setWhatsThis(headerWhats.at(i));
    }
}

void StudentInfo::initTableWidgetType()
{
    //表格自适应
    //ui->tableWidget_studentInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_studentInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //隐藏第一列表头
    ui->tableWidget_studentInfo->verticalHeader()->setHidden(true);

    //自动调整所有列的宽度，以适应其内容
    ui->tableWidget_studentInfo->resizeColumnsToContents();

    //表格不可编辑
    //ui->tableWidget_studentInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //隔行显示颜色
    ui->tableWidget_studentInfo->setAlternatingRowColors(true);

    //设置鼠标跟踪
    ui->tableWidget_studentInfo->setMouseTracking(true);
    connect(ui->tableWidget_studentInfo,SIGNAL(entered(QModelIndex)),this,SLOT(slot_showTableItemToolTip(QModelIndex)));
}

void StudentInfo::insertDataToTableWidget()
{
    //先清除表内容，并设置行为0行
    ui->tableWidget_studentInfo->clearContents();
    ui->tableWidget_studentInfo->setRowCount(0);

    ui->tableWidget_studentInfo->setRowCount(stuInfo.count());
    int row = ui->tableWidget_studentInfo->rowCount();
    //cout <<row;
    //插入数据到表格中
    for(int i=0;i<row;++i){
        //插入学生-公司信息
        VariableSet::Student stu = stuInfo.at(i);

        //表格添加项
        ui->tableWidget_studentInfo->setItem(i,0,new QTableWidgetItem(stu.StuNumber));
        ui->tableWidget_studentInfo->setItem(i,1,new QTableWidgetItem(stu.StuClass));
        ui->tableWidget_studentInfo->setItem(i,2,new QTableWidgetItem(stu.StuName));
        ui->tableWidget_studentInfo->setItem(i,3,new QTableWidgetItem(stu.StuSex));
        ui->tableWidget_studentInfo->setItem(i,4,new QTableWidgetItem(stu.Major));
        ui->tableWidget_studentInfo->setItem(i,5,new QTableWidgetItem(stu.StuPhone));
        ui->tableWidget_studentInfo->setItem(i,6,new QTableWidgetItem(stu.JobTime));
        ui->tableWidget_studentInfo->setItem(i,7,new QTableWidgetItem(stu.CompanyName));
        ui->tableWidget_studentInfo->setItem(i,8,new QTableWidgetItem(stu.JobPost));

        //表格项对齐方式
        ui->tableWidget_studentInfo->item(i,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_studentInfo->item(i,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_studentInfo->item(i,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_studentInfo->item(i,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_studentInfo->item(i,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_studentInfo->item(i,5)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_studentInfo->item(i,6)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_studentInfo->item(i,7)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_studentInfo->item(i,8)->setTextAlignment(Qt::AlignCenter);

        //设置表格为不可编辑可被选择
        setTableNotEdit(i);
    }
}

void StudentInfo::initRightMenu()
{
    ui->tableWidget_studentInfo->setContextMenuPolicy(Qt::CustomContextMenu);

    RMenu = new QMenu(ui->tableWidget_studentInfo);
    RMenu->setStyleSheet("");
    QAction *action1 = new QAction(QStringLiteral("删除记录"), this);
    QAction *action2 = new QAction(QStringLiteral("修改记录"), this);
    QAction *action3 = new QAction(QStringLiteral("保存记录"), this);
    QMenu *subMenu1 = new QMenu(QStringLiteral("查询"));
    QAction *action4 = new QAction(QStringLiteral("已就业学生"), subMenu1);
    QAction *action5 = new QAction(QStringLiteral("未就业学生"), subMenu1);
    QAction *action6 = new QAction(QStringLiteral("重置"),this);
    RMenu->addAction(action1);
    RMenu->addAction(action2);
    RMenu->addAction(action3);
    RMenu->addSeparator();
    RMenu->addMenu(subMenu1);
    subMenu1->addAction(action4);
    subMenu1->addAction(action5);
    RMenu->addAction(action6);

    connect(action1,SIGNAL(triggered()),this,SLOT(slot_delCurRowRecord()));
    connect(action2,SIGNAL(triggered()),this,SLOT(slot_alterCurRowRecord()));
    connect(action3,SIGNAL(triggered()),this,SLOT(slot_saveCurRowRecord()));
    connect(action4,SIGNAL(triggered()),this,SLOT(slot_queryEmploymentStu()));
    connect(action5,SIGNAL(triggered()),this,SLOT(slot_queryNotEmploymentStu()));
    connect(action6,SIGNAL(triggered()),this,SLOT(slot_resetTable()));

    connect(ui->tableWidget_studentInfo,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(slot_tableWidget_customContextMenuRequested(QPoint)));
}

void StudentInfo::flushTableRows(int curRow)
{
    int n = ui->tableWidget_studentInfo->rowCount();
    int cur;
    if(n>0){
        cur = curRow;
    }else{
        cur = 0;
    }

    QString str = QString("记录数共 %1 行，当前第 %2 行").arg(n).arg(cur);
    ui->label->setText(str);
}

void StudentInfo::setTableNotEdit(int &row)
{
    //设置表格不可编辑可被选择
    ui->tableWidget_studentInfo->item(row,0)->setFlags(ui->tableWidget_studentInfo->item(row,0)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_studentInfo->item(row,1)->setFlags(ui->tableWidget_studentInfo->item(row,1)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_studentInfo->item(row,2)->setFlags(ui->tableWidget_studentInfo->item(row,2)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_studentInfo->item(row,3)->setFlags(ui->tableWidget_studentInfo->item(row,3)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_studentInfo->item(row,4)->setFlags(ui->tableWidget_studentInfo->item(row,4)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_studentInfo->item(row,5)->setFlags(ui->tableWidget_studentInfo->item(row,5)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_studentInfo->item(row,6)->setFlags(ui->tableWidget_studentInfo->item(row,6)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_studentInfo->item(row,7)->setFlags(ui->tableWidget_studentInfo->item(row,7)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_studentInfo->item(row,8)->setFlags(ui->tableWidget_studentInfo->item(row,8)->flags()&(~Qt::ItemIsEditable));
}

void StudentInfo::slot_showTableItemToolTip(QModelIndex index)
{
    QToolTip::showText(QCursor::pos(),index.data().toString());
}

void StudentInfo::slot_tableWidgetAddItem(VariableSet::Student &stu)
{
    //同时把该学生记录保存到本地（这里不用保存学生信息到数据库,因为在添加学生子界面已经作了保存操作）
    stuInfo.push_front(stu);

    //从添加学生子界面传回的学生信息
    int row = ui->tableWidget_studentInfo->rowCount();
    ui->tableWidget_studentInfo->insertRow(row);

    //表格添加项
    ui->tableWidget_studentInfo->setItem(row,0,new QTableWidgetItem(stu.StuNumber));
    ui->tableWidget_studentInfo->setItem(row,1,new QTableWidgetItem(stu.StuClass));
    ui->tableWidget_studentInfo->setItem(row,2,new QTableWidgetItem(stu.StuName));
    ui->tableWidget_studentInfo->setItem(row,3,new QTableWidgetItem(stu.StuSex));
    ui->tableWidget_studentInfo->setItem(row,4,new QTableWidgetItem(stu.Major));
    ui->tableWidget_studentInfo->setItem(row,5,new QTableWidgetItem(stu.StuPhone));
    ui->tableWidget_studentInfo->setItem(row,6,new QTableWidgetItem(stu.JobTime));
    ui->tableWidget_studentInfo->setItem(row,7,new QTableWidgetItem(stu.CompanyName));
    ui->tableWidget_studentInfo->setItem(row,8,new QTableWidgetItem(stu.JobPost));

    //表格项对齐方式
    ui->tableWidget_studentInfo->item(row,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_studentInfo->item(row,1)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_studentInfo->item(row,2)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_studentInfo->item(row,3)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_studentInfo->item(row,4)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_studentInfo->item(row,5)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_studentInfo->item(row,6)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_studentInfo->item(row,7)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_studentInfo->item(row,8)->setTextAlignment(Qt::AlignCenter);

    //设置表格为不可编辑可被选择
    setTableNotEdit(row);

    flushTableRows(ui->tableWidget_studentInfo->currentRow());
}

void StudentInfo::on_btn_addStu_clicked()
{
    if(addStu == Q_NULLPTR){
        addStu = new AddStudent;
    }
    connect(addStu,SIGNAL(sig_studentInfo(VariableSet::Student&)),this,SLOT(slot_tableWidgetAddItem(VariableSet::Student&)));
    addStu->setWindowModality(Qt::WindowModal);//模态显示添加学生子界面
    addStu->move(this->width()/5,this->height()/3);
    addStu->resetStuNameAndStuNumber();
    addStu->show();
}

void StudentInfo::on_btn_saveToExcel_clicked()
{
    ThreadOperateExcel::getInstance()->tabSaveToExcel(ui->tableWidget_studentInfo,QStringLiteral("学生信息表"));
}

void StudentInfo::on_tableWidget_studentInfo_clicked(const QModelIndex &index)
{
    int cur = index.row()+1;
    flushTableRows(cur);
}

void StudentInfo::slot_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    RMenu->exec(QCursor::pos());
}

void StudentInfo::slot_delCurRowRecord()
{
    quint8 id = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/IDENTITY").toInt();
    if(id == 3){
        int row = ui->tableWidget_studentInfo->currentRow();
        QString stuNumber = ui->tableWidget_studentInfo->item(row,0)->text();
        //删除学生记录
        for (int i = 0; i < stuInfo.size(); ++i){
            VariableSet::Student stu = stuInfo.at(i);
            if(stu.StuNumber.contains(stuNumber)){
                if(Warning::setQuestion(QStringLiteral("确定删除当前行吗")) == QMessageBox::Yes){
                    //删除数据库的该条学生记录
                    QSqlQuery delRec(db);
                    delRec.prepare("delete from student where stuNumber=?");
                    delRec.bindValue(0,stu.StuNumber);

                    //同时删除本地学生记录
                    stuInfo.removeAt(i);
                    //表格同时删除当前行
                    ui->tableWidget_studentInfo->removeRow(row);
                    //刷新表格底部状态栏并设置当前显示行为第1行
                    flushTableRows(1);

                    if(delRec.exec()){
                        Warning::setInformation(QStringLiteral("当前行删除成功哈！"));
                    }
                }
                break;
            }
        }
    }else{
        if(id == 1){
            Warning::setWarning(QStringLiteral("学生身份没有删除权限哦"));
        }else{
            Warning::setWarning(QStringLiteral("教师身份没有删除权限哦"));
        }
    }
}

void StudentInfo::slot_alterCurRowRecord()
{
    int row = ui->tableWidget_studentInfo->currentRow();
    int column  = ui->tableWidget_studentInfo->currentColumn();
    recDyg.push_back(row);
    recDyg.push_back(column);
    //设置表格的当前单元格为可编辑可选择
    ui->tableWidget_studentInfo->item(row,column)->setFlags(ui->tableWidget_studentInfo->item(row,column)->flags()|(Qt::ItemIsEditable));
}

void StudentInfo::slot_saveCurRowRecord()
{
    //保存记录时，顺便设置已修改的单元格为不可编辑可被选择
    //ui->tableWidget_studentInfo->item(row,0)->setFlags(ui->tableWidget_studentInfo->item(row,0)->flags()&(~Qt::ItemIsEditable));
    for (int  i= 0;  i< recDyg.size(); i+=2) {
        int row = recDyg.at(i);
        int col = recDyg.at(i+1);
        QString stuNum = ui->tableWidget_studentInfo->item(row,0)->text();
        QString alterText = ui->tableWidget_studentInfo->item(row,col)->text();

        //判断修改的单元格内容是否已变化
        bool flag = false;
        for (int j = 0; j < stuInfo.size(); ++j){
            VariableSet::Student stu = stuInfo.at(j);
            if(stu.StuNumber.contains(stuNum)){
                //该行修改的学生记录不在本地学生信息中，则设置flag为true(说明未修改)
                if(stu.StuClass.contains(alterText)){
                    flag = true;
                    break;
                }
                if(stu.StuName.contains(alterText)){
                    flag = true;
                    break;
                }
                if(stu.StuSex.contains(alterText)){
                    flag = true;
                    break;
                }
                if(stu.Major.contains(alterText)){
                    flag = true;
                    break;
                }
                if(stu.StuPhone.contains(alterText)){
                    flag = true;
                    break;
                }
                if(stu.JobTime.contains(alterText)){
                    flag = true;
                    break;
                }
                if(stu.CompanyName.contains(alterText)){
                    flag = true;
                    break;
                }
                if(stu.JobPost.contains(alterText)){
                    flag = true;
                    break;
                }
                //否则已修改
                flag = false;
            }
        }
        //如果flag为true,说明已修改表格记录，然后修改数据库相应的数据
        if(flag == false){
            QSqlQuery saveStu(db);
            QString header  = ui->tableWidget_studentInfo->horizontalHeaderItem(col)->whatsThis();
            QString sql1 = QString("update student set %1=? where stuNumber=?").arg(header);
            saveStu.prepare(sql1);
            saveStu.bindValue(0,alterText);
            saveStu.bindValue(1,stuNum);
            if(saveStu.exec()){
                if(i+2==recDyg.size()){
                    Warning::setInformation(QStringLiteral("学生信息修改成功!"));
                }
            }
            QSqlQuery saveJY(db);
            //注意，这里sql语句必须这样执行，不要问为什么，因为我也不知道
            QString sql2 = QString("update stu_company set %1=? where stuNumber=?").arg(header);
            saveJY.prepare(sql2);
            saveJY.bindValue(0,alterText);
            saveJY.bindValue(1,stuNum);
            cout <<sql2;
            if(saveJY.exec()){
                if(i+2==recDyg.size()){
                    Warning::setInformation(QStringLiteral("就业信息同步修改成功!"));
                }
            }
        }else{
            cout << QStringLiteral("不存在修改信息");
        }
        //最后设置当前单元格为不可编辑可被选择状态
        ui->tableWidget_studentInfo->item(row,i)->setFlags(ui->tableWidget_studentInfo->item(row,i)->flags()&(~Qt::ItemIsEditable));
    }
    //备注：这里有个小bug,就是公司信息表没有主键哈，想明白了没，这里就不透漏了哈，不过日常几乎不会遇到
}

void StudentInfo::slot_queryEmploymentStu()
{
    //先隐藏所有行
    int rows = ui->tableWidget_studentInfo->rowCount();
    for (int i = 0; i < rows; ++i){
        ui->tableWidget_studentInfo->setRowHidden(i,true);
    }
    for (int i = 0; i < rows; ++i){
        QString jobTime = ui->tableWidget_studentInfo->item(i,6)->text();
        if(!jobTime.isEmpty()){
            //就业时间不为空
            ui->tableWidget_studentInfo->setRowHidden(i,false);//满足条件设置为可见
        }
    }
}

void StudentInfo::slot_queryNotEmploymentStu()
{
    //先隐藏所有行
    int rows = ui->tableWidget_studentInfo->rowCount();
    for (int i = 0; i < rows; ++i){
        ui->tableWidget_studentInfo->setRowHidden(i,true);
    }
    for (int i = 0; i < rows; ++i){
        QString jobTime = ui->tableWidget_studentInfo->item(i,6)->text();
        if(jobTime.isEmpty()){
            //就业时间为空
            ui->tableWidget_studentInfo->setRowHidden(i,false);//满足条件设置为可见
        }
    }
}

void StudentInfo::slot_resetTable()
{
    for (int i = 0; i < ui->tableWidget_studentInfo->rowCount(); ++i){
        ui->tableWidget_studentInfo->setRowHidden(i,false);    //显示所有行
    }
}
