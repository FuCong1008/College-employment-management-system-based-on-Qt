#include "companyinfo.h"
#include "ui_companyinfo.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

CompanyInfo::CompanyInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompanyInfo)
{
    ui->setupUi(this);
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    addCompany = Q_NULLPTR;

    //loadDBCompanyInfoToLocal();

    setTableWidgetHeader();

    initTableWidgetType();

    //insertDataToTableWidget();

    initRightMenu();

    //flushTableRows(1);
}

CompanyInfo::~CompanyInfo()
{
    delete ui;
}

void CompanyInfo::loadDBCompanyInfoToLocal()
{
    //判断数据记录是否有更新,未更新直接退出
    flag = judgeDataIsChange();
    if(flag == true){
        cout << "数据未更新";
        return;
    }
    //加载学生公司信息到本地
    companyInfo.clear();    //每次加载到本地时，对本地学生公司数据进行清零

    QSqlDatabase db;
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));
    QSqlQuery queryStu(db);
    queryStu.prepare("select * from company");
    if(queryStu.exec())
    {
        while(queryStu.next())
        {
            VariableSet::Company Com;
            Com.CompanySide = queryStu.value("companySide").toString();
            Com.CompanyName = queryStu.value("companyName").toString();
            Com.Contacts = queryStu.value("contacts").toString();
            Com.ContactsPhone = queryStu.value("contactsPhone").toString();
            Com.JobPost = queryStu.value("jobPost").toString();
            Com.Salary = queryStu.value("salary").toString();
            Com.AbilityRecquire = queryStu.value("abilityRecquire").toString();
            companyInfo.push_back(Com);
        }
        //cout << stuInfo.size();
    }else{
        cout << QStringLiteral("访问SEMS中的公司信息表失败");
    }
}

void CompanyInfo::setTableWidgetHeader()
{
    //设置表头
    QTableWidgetItem *headerItem;
    QStringList headerList;
    headerList <<QStringLiteral("公司名称")<<QStringLiteral("公司地点")<<QStringLiteral("公司联系人")
              <<QStringLiteral("公司联系人电话")<<QStringLiteral("就业岗位")<<QStringLiteral("新资")<<QStringLiteral("能力需求");
    ui->tableWidget_companyInfo->setColumnCount(headerList.count());
    QStringList headerWhats;
    headerWhats << QStringLiteral("companyName") << QStringLiteral("companySide")  << QStringLiteral("contacts")
                <<QStringLiteral("contactsPhone") << QStringLiteral("jobPost")  << QStringLiteral("salary")
                  << QStringLiteral("abilityRecquire");
    for(int i = 0;i<headerList.count();++i)
    {
        headerItem = new QTableWidgetItem(headerList.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
        headerItem->setFont(font);
        ui->tableWidget_companyInfo->setHorizontalHeaderItem(i,headerItem);
        ui->tableWidget_companyInfo->horizontalHeaderItem(i)->setWhatsThis(headerWhats.at(i));
    }
}

void CompanyInfo::initTableWidgetType()
{
    //表格自适应
    //ui->tableWidget_companyInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_companyInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //隐藏第一列表头
    ui->tableWidget_companyInfo->verticalHeader()->setHidden(true);

    //自动调整所有列的宽度，以适应其内容
    ui->tableWidget_companyInfo->resizeColumnsToContents();

    //表格不可编辑
    //ui->tableWidget_companyInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //隔行显示颜色
    ui->tableWidget_companyInfo->setAlternatingRowColors(true);

    //设置鼠标跟踪
    ui->tableWidget_companyInfo->setMouseTracking(true);
    connect(ui->tableWidget_companyInfo,SIGNAL(entered(QModelIndex)),this,SLOT(slot_showTableItemToolTip(QModelIndex)));
}

void CompanyInfo::insertDataToTableWidget()
{
    if(flag == true){
        cout << "数据未更新";
        return;
    }

    //先清除表内容，并设置行为0行
    ui->tableWidget_companyInfo->clearContents();
    ui->tableWidget_companyInfo->setRowCount(0);

    ui->tableWidget_companyInfo->setRowCount(companyInfo.count());
    int row = ui->tableWidget_companyInfo->rowCount();

    //插入数据到表格中
    for(int i=0;i<row;++i){
        //插入学生-公司信息
        VariableSet::Company Com = companyInfo.at(i);

        //表格添加项
        ui->tableWidget_companyInfo->setItem(i,0,new QTableWidgetItem(Com.CompanyName));
        ui->tableWidget_companyInfo->setItem(i,1,new QTableWidgetItem(Com.CompanySide));
        ui->tableWidget_companyInfo->setItem(i,2,new QTableWidgetItem(Com.Contacts));
        ui->tableWidget_companyInfo->setItem(i,3,new QTableWidgetItem(Com.ContactsPhone));
        ui->tableWidget_companyInfo->setItem(i,4,new QTableWidgetItem(Com.JobPost));
        ui->tableWidget_companyInfo->setItem(i,5,new QTableWidgetItem(Com.Salary));
        ui->tableWidget_companyInfo->setItem(i,6,new QTableWidgetItem(Com.AbilityRecquire));

        //表格项对齐方式
        ui->tableWidget_companyInfo->item(i,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_companyInfo->item(i,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_companyInfo->item(i,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_companyInfo->item(i,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_companyInfo->item(i,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_companyInfo->item(i,5)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_companyInfo->item(i,6)->setTextAlignment(Qt::AlignCenter);      //能力需求描述太长，所以居左对齐

        //设置表格为不可编辑可被选择
        setTableNotEdit(i);
    }
    flushTableRows(1);
    //ui->tableWidget_companyInfo->resizeColumnsToContents();
}

void CompanyInfo::initRightMenu()
{
    ui->tableWidget_companyInfo->setContextMenuPolicy(Qt::CustomContextMenu);

    RMenu = new QMenu(ui->tableWidget_companyInfo);
    RMenu->setStyleSheet("");
    QAction *action1 = new QAction(QStringLiteral("确认就业公司"), this);
    QAction *action2 = new QAction(QStringLiteral("删除记录"), this);
    QAction *action3 = new QAction(QStringLiteral("修改记录"), this);
    QAction *action4 = new QAction(QStringLiteral("保存记录"), this);
    RMenu->addAction(action1);
    RMenu->addSeparator();
    RMenu->addAction(action2);
    RMenu->addAction(action3);
    RMenu->addAction(action4);

    connect(action1, SIGNAL(triggered()), this, SLOT(slot_ActionDeliverResume()));
    connect(action2,SIGNAL(triggered()),this,SLOT(slot_delCurRowRecord()));
    connect(action3,SIGNAL(triggered()),this,SLOT(slot_alterCurRowRecord()));
    connect(action4,SIGNAL(triggered()),this,SLOT(slot_saveCurRowRecord()));

    connect(ui->tableWidget_companyInfo,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(slot_tableWidget_customContextMenuRequested(QPoint)));
}

void CompanyInfo::flushTableRows(int curRow)
{
    int n = ui->tableWidget_companyInfo->rowCount();
    int cur;
    if(n>0){
        cur = curRow;
    }else{
        cur = 0;
    }

    QString str = QString("记录数共 %1 行，当前第 %2 行").arg(n).arg(cur);
    ui->label->setText(str);
}

void CompanyInfo::setTableNotEdit(int &row)
{
    //设置表格不可编辑可被选择

    ui->tableWidget_companyInfo->item(row,0)->setFlags(ui->tableWidget_companyInfo->item(row,0)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_companyInfo->item(row,1)->setFlags(ui->tableWidget_companyInfo->item(row,1)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_companyInfo->item(row,2)->setFlags(ui->tableWidget_companyInfo->item(row,2)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_companyInfo->item(row,3)->setFlags(ui->tableWidget_companyInfo->item(row,3)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_companyInfo->item(row,4)->setFlags(ui->tableWidget_companyInfo->item(row,4)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_companyInfo->item(row,5)->setFlags(ui->tableWidget_companyInfo->item(row,5)->flags()&(~Qt::ItemIsEditable));
    ui->tableWidget_companyInfo->item(row,6)->setFlags(ui->tableWidget_companyInfo->item(row,6)->flags()&(~Qt::ItemIsEditable));
}

bool CompanyInfo::judgeDataIsChange()
{
    QSqlQuery curSizeQuery(db);
    curSizeQuery.prepare("select companyName from company");
    if(curSizeQuery.exec()){
        QStringList curSize;
        while (curSizeQuery.next()){
            curSize << curSizeQuery.value("companyName").toString();
        }
        if(companyInfo.size() == curSize.size()){
            //数据库学生公司就业信息没有更新，不用加载到本地，因为这次记录和上次一样(省时操作,以免每次读取数据库)
            return true;
        }
    }
    return false;
}

void CompanyInfo::slot_showTableItemToolTip(QModelIndex index)
{
    QToolTip::showText(QCursor::pos(),index.data().toString());
}

void CompanyInfo::slot_tableWidgetAddItem(VariableSet::Company &com)
{
    //同时把该公司记录保存到本地（这里不用保存公司信息到数据库,因为在添加公司子界面已经作了保存操作）
    companyInfo.push_front(com);

    //从添加学生子界面传回的学生信息
    int row = ui->tableWidget_companyInfo->rowCount();
    ui->tableWidget_companyInfo->insertRow(row);

    //表格添加项
    ui->tableWidget_companyInfo->setItem(row,0,new QTableWidgetItem(com.CompanyName));
    ui->tableWidget_companyInfo->setItem(row,1,new QTableWidgetItem(com.CompanySide));
    ui->tableWidget_companyInfo->setItem(row,2,new QTableWidgetItem(com.Contacts));
    ui->tableWidget_companyInfo->setItem(row,3,new QTableWidgetItem(com.ContactsPhone));
    ui->tableWidget_companyInfo->setItem(row,4,new QTableWidgetItem(com.JobPost));
    ui->tableWidget_companyInfo->setItem(row,5,new QTableWidgetItem(com.Salary));
    ui->tableWidget_companyInfo->setItem(row,6,new QTableWidgetItem(com.AbilityRecquire));

    //表格项对齐方式
    ui->tableWidget_companyInfo->item(row,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_companyInfo->item(row,1)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_companyInfo->item(row,2)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_companyInfo->item(row,3)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_companyInfo->item(row,4)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_companyInfo->item(row,5)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_companyInfo->item(row,6)->setTextAlignment(Qt::AlignCenter);

    //设置表格为不可编辑可被选择
    setTableNotEdit(row);

    flushTableRows(ui->tableWidget_companyInfo->currentRow());
}

void CompanyInfo::on_btn_addCompany_clicked()
{
    if(addCompany == Q_NULLPTR){
        addCompany = new AddCompany;
    }
    connect(addCompany,SIGNAL(sig_companyInfo(VariableSet::Company&)),this,SLOT(slot_tableWidgetAddItem(VariableSet::Company&)));
    addCompany->setWindowModality(Qt::WindowModal);  //模态显示
    addCompany->move(this->width()/4,this->height()/3);
    addCompany->show();
}

void CompanyInfo::on_btn_saveToExcel_clicked()
{
    ThreadOperateExcel::getInstance()->tabSaveToExcel(ui->tableWidget_companyInfo,QStringLiteral("公司信息表"));
}

void CompanyInfo::slot_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    RMenu->exec(QCursor::pos());
}

void CompanyInfo::slot_ActionDeliverResume()
{//鼠标右键表格添加投递简历
    quint8 identity = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/IDENTITY").toInt();
    if(identity == 1){
        //学生身份
        QString stuNum = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/ACCOUNT").toString();

        //1.先确定学生信息中是否有该学生信息，根据当前登入账号进行确定（所以学生信息的学号为登入账号的必要条件）
        QSqlQuery stuInfo(db);
        stuInfo.prepare("select stuNumber from student where stuNumber=?");
        stuInfo.bindValue(0,stuNum);
        if(stuInfo.exec()){
            QStringList stu;
            while (stuInfo.next()){
                stu << stuInfo.value("stuNumber").toString();
            }
            if(stu.size()==0){
                Warning::setInformation(QStringLiteral("请在学生信息中添加本人学生信息哈"));
                return;
            }
        }else{
            Warning::setWarning(QStringLiteral("数据库查询学生信息语句执行失败！"));
            return;
        }

        //2.确定该学生是否已就业
        QSqlQuery ackQuery(db);
        ackQuery.prepare("select stuNumber from stu_company where stuNumber=?");
        ackQuery.bindValue(0,stuNum);
        if(ackQuery.exec()){
            QStringList stuAck;
            while (ackQuery.next()){
                stuAck << ackQuery.value("stuNumber").toString();
            }
            if(stuAck.size() != 0){
                //说明该学生已确认就业了
                Warning::setInformation(QStringLiteral("你已经就业了哈,不用确认就业公司啦"));
                return;
            }else{
                //说明该学生未确认就业信息，然后对该选择进行确认
                if(Warning::setQuestion(QStringLiteral("确定是在该公司就业了?"))==QMessageBox::Yes){
                    cout << QStringLiteral("说明该学生未确认就业信息，");
                    //待解决
    //                VariableSet::Student stu;
                    QSqlQuery stuQuery(db);
                    stuQuery.prepare("select stuNumber,stuClass,stuName,stuSex,stuMajor,stuPhone from student where stuNumber=?");
                    stuQuery.bindValue(0,stuNum);
                    QStringList stuTmp;
                    if(stuQuery.exec()){
                        while (stuQuery.next()){
                            stuTmp << stuQuery.value("stuNumber").toString();
                            stuTmp << stuQuery.value("stuClass").toString();
                            stuTmp << stuQuery.value("stuName").toString();
                            stuTmp << stuQuery.value("stuSex").toString();
                            stuTmp << stuQuery.value("stuMajor").toString();
                            stuTmp << stuQuery.value("stuPhone").toString();
                        }
                    }

                    VariableSet::Company comTmp;
                    quint8 row = ui->tableWidget_companyInfo->currentRow();
                    comTmp.CompanyName = ui->tableWidget_companyInfo->item(row,0)->text();
                    comTmp.CompanySide = ui->tableWidget_companyInfo->item(row,1)->text();
                    comTmp.Contacts = ui->tableWidget_companyInfo->item(row,2)->text();
                    comTmp.ContactsPhone = ui->tableWidget_companyInfo->item(row,3)->text();
                    comTmp.JobPost = ui->tableWidget_companyInfo->item(row,4)->text();
                    comTmp.Salary = ui->tableWidget_companyInfo->item(row,5)->text();
                    comTmp.AbilityRecquire = ui->tableWidget_companyInfo->item(row,6)->text();

                    //输入就业时间
                    QLineEdit::EchoMode echoMode=QLineEdit::Normal;
                    QString jobTime = QInputDialog::getText(this,QStringLiteral("就业时间"),QStringLiteral("请输入就业时间")
                                                            ,echoMode);
                    QSqlQuery ackJob(db);
                    ackJob.prepare("insert into stu_company (stuNumber,stuClass,stuName,stuSex,stuMajor,stuPhone,jobTime"
                                   ",companyName,companySide,contacts,contactsPhone,jobPost,salary,abilityRecquire) "
                                   "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
                    ackJob.bindValue(0,stuTmp.at(0));
                    ackJob.bindValue(1,stuTmp.at(1));
                    ackJob.bindValue(2,stuTmp.at(2));
                    ackJob.bindValue(3,stuTmp.at(3));
                    ackJob.bindValue(4,stuTmp.at(4));
                    ackJob.bindValue(5,stuTmp.at(5));
                    ackJob.bindValue(6,jobTime);
                    ackJob.bindValue(7,comTmp.CompanyName);
                    ackJob.bindValue(8,comTmp.CompanySide);
                    ackJob.bindValue(9,comTmp.Contacts);
                    ackJob.bindValue(10,comTmp.ContactsPhone);
                    ackJob.bindValue(11,comTmp.JobPost);
                    ackJob.bindValue(12,comTmp.Salary);
                    ackJob.bindValue(13,comTmp.AbilityRecquire);
                    if(ackJob.exec()){
                        Warning::setInformation(QStringLiteral("就业公司确认成功"));
                        return;
                    }
                }
            }
        }else{
            Warning::setWarning(QStringLiteral("数据库语句查询学生就业信息执行失败！"));
            return;
        }

    }else{
        if(identity == 2){
            Warning::setInformation(QStringLiteral("教师身份不可确认就业公司哦"));
            return;
        }else{
            Warning::setInformation(QStringLiteral("管理员身份不可确认就业公司哦"));
            return;
        }
    }
}

void CompanyInfo::slot_delCurRowRecord()
{
    quint8 id = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/IDENTITY").toInt();
    if(id == 3){
        int row = ui->tableWidget_companyInfo->currentRow();
        QString comName = ui->tableWidget_companyInfo->item(row,0)->text();
        QString jobPost = ui->tableWidget_companyInfo->item(row,4)->text();
        cout << comName << jobPost;
        //删除公司记录
        for (int i = 0; i < companyInfo.size(); ++i){
            VariableSet::Company com = companyInfo.at(i);
            if(com.CompanyName.contains(comName)&&com.JobPost.contains(jobPost)){
                if(Warning::setQuestion(QStringLiteral("确定删除当前行吗")) == QMessageBox::Yes){
                    //删除数据库的该条公司记录
                    QSqlQuery delRec(db);
                    delRec.prepare("delete from company where companyName=? and jobPost=?");
                    delRec.bindValue(0,com.CompanyName);
                    delRec.bindValue(1,com.JobPost);

                    //同时删除本地公司记录
                    companyInfo.removeAt(i);
                    //表格同时删除当前行
                    ui->tableWidget_companyInfo->removeRow(row);
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

void CompanyInfo::slot_alterCurRowRecord()
{
    int row = ui->tableWidget_companyInfo->currentRow();
    int column  = ui->tableWidget_companyInfo->currentColumn();
    recDyg.push_back(row);
    recDyg.push_back(column);
    //设置表格的当前单元格为可编辑可选择
    ui->tableWidget_companyInfo->item(row,column)->setFlags(ui->tableWidget_companyInfo->item(row,column)->flags()|(Qt::ItemIsEditable));
}

void CompanyInfo::slot_saveCurRowRecord()
{
    //保存记录时，顺便设置已修改的单元格为不可编辑可被选择
    //ui->tableWidget_companyInfo->item(row,0)->setFlags(ui->tableWidget_companyInfo->item(row,0)->flags()&(~Qt::ItemIsEditable));
    for (int  i= 0;  i< recDyg.size(); i+=2) {
        int row = recDyg.at(i);
        int col = recDyg.at(i+1);
        QString comName = ui->tableWidget_companyInfo->item(row,0)->text();
        QString alterText = ui->tableWidget_companyInfo->item(row,col)->text();

        //判断修改的单元格内容是否已变化
        bool flag = false;
        for (int j = 0; j < companyInfo.size(); ++j){
            VariableSet::Company com = companyInfo.at(j);
            if(com.CompanyName.contains(comName)){
                //该修改的公司记录不在本地公司信息中，则设置flag为true(说明已修改)
                if(!com.CompanySide.contains(alterText)){
                    flag = true;
                    break;
                }
                if(!com.Contacts.contains(alterText)){
                    flag = true;
                    break;
                }
                if(!com.ContactsPhone.contains(alterText)){
                    flag = true;
                    break;
                }
                if(!com.JobPost.contains(alterText)){
                    flag = true;
                    break;
                }
                if(!com.Salary.contains(alterText)){
                    flag = true;
                    break;
                }
                if(!com.AbilityRecquire.contains(alterText)){
                    flag = true;
                    break;
                }
                flag = false;
            }
        }
        //如果flag为true,说明已修改表格记录，然后修改数据库相应的数据
        if(flag == true){
            QSqlQuery saveCom(db);
            QString header  = ui->tableWidget_companyInfo->horizontalHeaderItem(col)->whatsThis();
            QString sql1 = QString("update company set %1=? where companyName=?").arg(header);
            saveCom.prepare(sql1);
            saveCom.bindValue(0,alterText);
            saveCom.bindValue(1,comName);
            if(saveCom.exec()){
                if(i+2 == recDyg.size()){
                    Warning::setInformation(QStringLiteral("公司信息修改成功!"));
                }
            }
            QSqlQuery saveJY(db);
            //注意，以下sql语句必须这样执行，不要问为什么，因为我也不知道
            QString sql2 = QString("update stu_company set %1=? where companyName=?").arg(header);
            saveJY.prepare(sql2);
            saveJY.bindValue(0,alterText);
            saveJY.bindValue(1,comName);
            cout <<sql2;
            if(saveJY.exec()){
                if(i+2 == recDyg.size()){
                    Warning::setInformation(QStringLiteral("就业信息同步修改成功!"));
                }
            }
        }
        //最后设置当前单元格为不可编辑可被选择状态
        ui->tableWidget_companyInfo->item(row,i)->setFlags(ui->tableWidget_companyInfo->item(row,i)->flags()&(~Qt::ItemIsEditable));
    }
    //备注：这里有个小bug,就是公司信息表没有主键哈，想明白了没，这里就不透漏了哈，不过日常几乎不会遇到
}

void CompanyInfo::on_tableWidget_companyInfo_clicked(const QModelIndex &index)
{
    int cur = index.row()+1;
    flushTableRows(cur);
}
