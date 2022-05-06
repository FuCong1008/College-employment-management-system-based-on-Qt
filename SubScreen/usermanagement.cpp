#include "usermanagement.h"
#include "ui_usermanagement.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

UserManagement::UserManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));

    addUser = Q_NULLPTR;

    loadDBToLocal();
    setTableWidgetHeader();
    initTableWidgetType();
    insertDataToTableWidget();
}

UserManagement::~UserManagement()
{
    delete ui;
}

void UserManagement::loadDBToLocal()
{
    //加载用户信息到本地
    userInfo.clear();    //每次加载到本地时，对本地学生数据进行清零


    QSqlQuery queryUser(db);
    queryUser.prepare("select * from user");
    if(queryUser.exec())
    {
        while(queryUser.next())
        {
            VariableSet::User user;
            user.Account = queryUser.value("account").toString();
            user.Password = queryUser.value("pwd").toString();
            user.Identity = queryUser.value("identity").toString();
            user.userName = queryUser.value("userName").toString();
            userInfo.push_back(user);
        }
        //cout << userInfo.size();
    }else{
        cout << QStringLiteral("访问数据库失败");
    }
}

void UserManagement::setTableWidgetHeader()
{
    QTableWidgetItem *headerItem;
    QStringList headerList;
    headerList <<QStringLiteral("用户账号")<<QStringLiteral("用户姓名")<<QStringLiteral("用户身份")<<QStringLiteral("操作");
    ui->tableWidget_userInfo->setColumnCount(headerList.count());
    for(int i = 0;i<headerList.count();++i)
    {
        headerItem = new QTableWidgetItem(headerList.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
//        font.setPointSize(10);
//        headerItem->setTextColor(Qt::black);
        headerItem->setFont(font);
        ui->tableWidget_userInfo->setHorizontalHeaderItem(i,headerItem);
    }
}

void UserManagement::initTableWidgetType()
{
    //表格自适应
    ui->tableWidget_userInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //隐藏第一列表头
    ui->tableWidget_userInfo->verticalHeader()->setHidden(true);

    //自动调整所有列的宽度，以适应其内容
    ui->tableWidget_userInfo->resizeColumnsToContents();

    //隔行显示颜色
    ui->tableWidget_userInfo->setAlternatingRowColors(true);
    //ui->tableWidget_userInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置用户管理的表不可编辑

    //设置鼠标跟踪
    ui->tableWidget_userInfo->setMouseTracking(true);
    connect(ui->tableWidget_userInfo,SIGNAL(entered(QModelIndex)),this,SLOT(on_showTableItemToolTip(QModelIndex)));
}

void UserManagement::insertDataToTableWidget()
{
    ui->tableWidget_userInfo->clearContents();
    ui->tableWidget_userInfo->setRowCount(0);
    btnEditVec.clear();
    btnDelVec.clear();
//    ui->tableWidget_userInfo->setRowCount(userInfo.count());
//    int row = ui->tableWidget_userInfo->rowCount();

    //插入数据到表格中
    int row=0;
    for(int i=0;i<userInfo.count();++i){
        //插入用户信息
        VariableSet::User user = userInfo.at(i);
        if(!user.userName.isEmpty()){
            ui->tableWidget_userInfo->insertRow(row);
            //表格添加项
            ui->tableWidget_userInfo->setItem(row,0,new QTableWidgetItem(user.Account));
            ui->tableWidget_userInfo->setItem(row,1,new QTableWidgetItem(user.userName));
            ui->tableWidget_userInfo->setItem(row,2,new QTableWidgetItem(user.Identity));

            //表格插入(编辑/删除)按钮
            insertButtonToTable(row,3);

            //表格项对齐方式
            ui->tableWidget_userInfo->item(row,0)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_userInfo->item(row,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_userInfo->item(row,2)->setTextAlignment(Qt::AlignCenter);

            //设置表格不可编辑可被选择
            ui->tableWidget_userInfo->item(row,0)->setFlags(ui->tableWidget_userInfo->item(row,0)->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget_userInfo->item(row,1)->setFlags(ui->tableWidget_userInfo->item(row,1)->flags()&(~Qt::ItemIsEditable));
            ui->tableWidget_userInfo->item(row,2)->setFlags(ui->tableWidget_userInfo->item(row,2)->flags()&(~Qt::ItemIsEditable));

            ++row;
        }
    }
    ui->tableWidget_userInfo->resizeColumnsToContents();
}

void UserManagement::insertButtonToTable(int &row,int &&col)
{
    //在给定的行号row进行插入按钮
    //详情按钮
    QPushButton *btn_edit = new QPushButton(tr("编辑"));
    btn_edit->setMinimumHeight(ui->tableWidget_userInfo->rowHeight(btnEditVec.count()));
    btn_edit->setWhatsThis(QString::number(row));
    btn_edit->setObjectName("btn_detail");
    connect(btn_edit,SIGNAL(clicked()),this,SLOT(slot_clickTableEditBtn()));

    //删除按钮
    QPushButton *btn_delete = new QPushButton(tr("删除"));
    btn_delete->setMinimumHeight(ui->tableWidget_userInfo->rowHeight(btnDelVec.count()));
    btn_delete->setWhatsThis(QString::number(row));
    btn_delete->setObjectName("btn_delete");
    connect(btn_delete,SIGNAL(clicked()),this,SLOT(slot_clickTableDeleteBtn()));

    //给这两个按钮设置水平布局
    QHBoxLayout *hlay = new QHBoxLayout();
    hlay->addStretch(1);
    hlay->addWidget(btn_edit);
    hlay->addWidget(btn_delete);
    hlay->addStretch(1);
    hlay->setMargin(0);

    QWidget *tmp = new QWidget(this);
    tmp->setLayout(hlay);
    ui->tableWidget_userInfo->setCellWidget(row,col,tmp);

    //保存按钮的容器
    if(!btnEditVec.contains(btn_edit)){
        btnEditVec.push_back(btn_edit);
    }
    if(!btnDelVec.contains(btn_delete)){
        btnDelVec.push_back(btn_delete);
    }
}

void UserManagement::setTableIsEnabled()
{
    QString account = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/ACCOUNT").toString();
    int id = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/IDENTITY").toInt();
    //配置文件中：1-学生 2-教师 3-管理员
    if(id != 3){
        //教师和学生身份
        for (int i = 0; i < btnEditVec.count(); ++i){
            btnEditVec.at(i)->setEnabled(false);
            btnDelVec.at(i)->setEnabled(false);
        }
    }else{
        //管理员身份
        for (int i = 0; i < btnEditVec.count(); ++i){
            //当前登录账号不可对当前账号进行点击按钮操作
            if(ui->tableWidget_userInfo->item(i,0)->text() == account){
                btnEditVec.at(i)->setEnabled(true);
                btnDelVec.at(i)->setEnabled(false);
            }else{
                btnEditVec.at(i)->setEnabled(true);
                btnDelVec.at(i)->setEnabled(true);
            }
        }
    }
}

void UserManagement::clickDelToDealWithData(int &row)
{
    QString curRowAccount = ui->tableWidget_userInfo->item(row,0)->text();  //获取删除选中行的账号
    //删除本地用户信息
    for (int i = 0; i < userInfo.count(); ++i){
        if(userInfo.at(i).Account == curRowAccount){
            userInfo.removeAt(i);
            break;
        }
    }
    cout << QStringLiteral("删除本地用户信息成功") << userInfo.count()<< curRowAccount;

    QSqlQuery delUserQuery(db);
    delUserQuery.prepare("delete from user where account=?");
    delUserQuery.bindValue(0,curRowAccount);
    if(delUserQuery.exec()){
        cout << QStringLiteral("删除数据库用户信息成功") << curRowAccount; //主键约束删除不了数据，为什么
    }
}

void UserManagement::pressedEditBtnToUpdateDB(QString &account, QString &userName, QString &id)
{
    Q_UNUSED(id);
    QSqlQuery updateQuery(db);
    updateQuery.prepare("update user set userName=? where account=?");
    updateQuery.bindValue(0,userName);
    updateQuery.bindValue(1,account);
    if(updateQuery.exec())
    {
        cout << QStringLiteral("更新用户数据表的内容成功!");
    }else{
        cout << QStringLiteral("访问数据库失败");
    }
}

void UserManagement::on_showTableItemToolTip(QModelIndex index)
{
    QToolTip::showText(QCursor::pos(),index.data().toString());
}

void UserManagement::slot_clickTableEditBtn()
{
    //自定义编辑按钮的槽函数
    QPushButton *btn_edit = qobject_cast<QPushButton*>(sender());
    if(btn_edit == Q_NULLPTR){
        return;
    }

    int row = btn_edit->whatsThis().toInt();
    if(!rowVec.contains(row)){
        rowVec.push_back(row);
    }

    //设置表格为可编辑可选择
    //ui->tableWidget_userInfo->item(row,0)->setFlags(ui->tableWidget_userInfo->item(row,0)->flags()|(Qt::ItemIsEditable));
    ui->tableWidget_userInfo->item(row,1)->setFlags(ui->tableWidget_userInfo->item(row,1)->flags()|(Qt::ItemIsEditable));
    ui->tableWidget_userInfo->item(row,2)->setFlags(ui->tableWidget_userInfo->item(row,2)->flags()|(Qt::ItemIsEditable));

    cout << btnEditVec.count() << btn_edit->whatsThis() << QStringLiteral("编辑按钮被点击");
}

void UserManagement::slot_clickTableDeleteBtn()
{
    //点击删除按钮(进行慎重提示是否删除);
    QMessageBox::StandardButton result;
    result = Warning::setQuestion(QStringLiteral("是否删除当前行数据"));
    if(result == QMessageBox::Yes){
        //自定义删除按钮的槽函数
        QPushButton *btn_del = qobject_cast<QPushButton*>(sender());
        if(btn_del == Q_NULLPTR){
            return;
        }
        //cout << btnDelVec.count() << btn_del->whatsThis() <<QStringLiteral("删除按钮被点击");
        int rowNum = btn_del->whatsThis().toInt(); //获取当前行号

        if(rowVec.contains(rowNum)){
            //设置表格为可编辑可选择(删除前先设置为不可编辑可被选择---以下三行也许是多余的，凑代码量，哈哈)
            //ui->tableWidget_userInfo->item(rowNum,0)->setFlags(ui->tableWidget_userInfo->item(rowNum,0)->flags()|(Qt::ItemIsEditable));
            ui->tableWidget_userInfo->item(rowNum,1)->setFlags(ui->tableWidget_userInfo->item(rowNum,1)->flags()|(Qt::ItemIsEditable));
            ui->tableWidget_userInfo->item(rowNum,2)->setFlags(ui->tableWidget_userInfo->item(rowNum,2)->flags()|(Qt::ItemIsEditable));

            rowVec.removeOne(rowNum);
            //更新行号容器里的行号
            for (int i = 0; i < rowVec.count(); ++i){
                int tmp = rowVec.at(i);
                if(tmp>rowNum){
                    --tmp;
                    rowVec[i] = tmp;
                }
            }
        }

        //这里进行删除数据库和本地用户信息数据
        //clickDelToDealWithData(rowNum);

        QPushButton *btn_edit = btnEditVec.at(rowNum);  //获取同一行的编辑按钮句柄
        ui->tableWidget_userInfo->removeRow(rowNum);    //删除"删除按钮"所在行
        //同时去除掉编辑按钮和删除按钮在容器里的句柄
        btnEditVec.removeOne(btn_edit);
        btnDelVec.removeOne(btn_del);
        //释放按钮内存
        delete btn_edit;
        btn_edit = Q_NULLPTR;
        delete btn_del;
        btn_del = Q_NULLPTR;

        //更新按钮的行号标志
        for (int row = 0; row < btnDelVec.count(); ++row){
            btnEditVec.at(row)->setWhatsThis(QString::number(row));
            btnDelVec.at(row)->setWhatsThis(QString::number(row));
        }
    }else if (result == QMessageBox::No){
        return;
    }
}

void UserManagement::on_tableWidgetAddItem(VariableSet::User &userInfo)
{
    //自定义的槽函数，用于接受添加用户子界面传回的用户数据
    int row = ui->tableWidget_userInfo->rowCount();
    ui->tableWidget_userInfo->insertRow(row);
    //表格添加项
    ui->tableWidget_userInfo->setItem(row,0,new QTableWidgetItem(userInfo.Account));
    ui->tableWidget_userInfo->setItem(row,1,new QTableWidgetItem(userInfo.userName));
    ui->tableWidget_userInfo->setItem(row,2,new QTableWidgetItem(userInfo.Identity));
    insertButtonToTable(row,3);

    //表格项对齐方式
    ui->tableWidget_userInfo->item(row,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_userInfo->item(row,1)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_userInfo->item(row,2)->setTextAlignment(Qt::AlignCenter);
    cout << QStringLiteral("添加用户成功") << userInfo.Account<<userInfo.userName<<userInfo.Identity<<row;
}

void UserManagement::on_btn_reset_clicked()
{
    ui->le_account->clear();
    ui->le_userName->clear();
    ui->combox_identity->setCurrentIndex(0);
    for (int i = 0; i < ui->tableWidget_userInfo->rowCount(); ++i){
        ui->tableWidget_userInfo->setRowHidden(i,false);    //显示所有行
    }
}

void UserManagement::on_btn_query_clicked()
{
    QString account = ui->le_account->text();
    QString name = ui->le_userName->text();
    QString id= ui->combox_identity->currentText();
    int rows = ui->tableWidget_userInfo->rowCount();
    //先隐藏所有行
    for (int i = 0; i < rows; ++i){
        ui->tableWidget_userInfo->setRowHidden(i,true);
    }
    if(!account.isEmpty()){
        //用户账号不为空
        QList<QTableWidgetItem*> item = ui->tableWidget_userInfo->findItems(account,Qt::MatchExactly);
        if(!item.isEmpty()){
            for (int i = 0; i < item.count(); ++i){
                ui->tableWidget_userInfo->setRowHidden(item.at(i)->row(),false);
                cout << item.at(i)->row();
            }
        }
        return;
    }
    if (!name.isEmpty()){
        //用户姓名不为空
        QList<QTableWidgetItem*> item = ui->tableWidget_userInfo->findItems(name,Qt::MatchExactly);
        for (int i = 0; i < item.count(); ++i){
            ui->tableWidget_userInfo->setRowHidden(item.at(i)->row(),false);
            cout << item.at(i)->row();
        }
        return;
    }
    if (!id.isEmpty()){
        //用户身份不为空
        QList<QTableWidgetItem*> item = ui->tableWidget_userInfo->findItems(id,Qt::MatchExactly);
        for (int i = 0; i < item.count(); ++i){
            ui->tableWidget_userInfo->setRowHidden(item.at(i)->row(),false);
            cout << item.at(i)->row();
        }
        return;
    }

//    {
//        //账号，身份都为空  (显示所有行)
//        for (int i = 0; i < rows; ++i){
//            ui->tableWidget_userInfo->setRowHidden(i,true);
//        }
//    }
}

void UserManagement::on_btn_userInfo_clicked()
{
    if(addUser == Q_NULLPTR)
    {
        addUser = new AddUser;
    }
    int id = ConfigValue::getConfigValueWithKey("Config/userLogin.ini","USERLOGIN/IDENTITY").toInt();
    if(id == 3){
        connect(addUser,SIGNAL(sig_submitUserData(VariableSet::User&)),this,SLOT(on_tableWidgetAddItem(VariableSet::User&)));
        addUser->setWindowModality(Qt::WindowModal);
        addUser->move(this->width()/4,this->height()/3);
        addUser->showNormal();
    }else{
        if(id == 2){
            Warning::setInformation(QStringLiteral("教师身份不可添加用户哦"));
        }else{
            Warning::setInformation(QStringLiteral("学生身份不可添加用户哦"));
        }
    }
}

void UserManagement::on_btn_save_clicked()
{
    if(rowVec.count() == 0){
        //cout << QStringLiteral("行容器容量为0");
        Warning::setInformation(QStringLiteral("暂无内容需要保存"));
        return;
    }
    foreach (auto row,rowVec) {
        //设置表格不可编辑可被选择
        //ui->tableWidget_userInfo->item(row,0)->setFlags(ui->tableWidget_userInfo->item(row,0)->flags()&(~Qt::ItemIsEditable));
        ui->tableWidget_userInfo->item(row,1)->setFlags(ui->tableWidget_userInfo->item(row,1)->flags()&(~Qt::ItemIsEditable));
        ui->tableWidget_userInfo->item(row,2)->setFlags(ui->tableWidget_userInfo->item(row,2)->flags()&(~Qt::ItemIsEditable));

        QString account = ui->tableWidget_userInfo->item(row,0)->text();
        QString userName = ui->tableWidget_userInfo->item(row,1)->text();
        QString id = ui->tableWidget_userInfo->item(row,2)->text();
        //更新数据库的用户数据表内容
        pressedEditBtnToUpdateDB(account,userName,id);
        cout << ui->tableWidget_userInfo->item(row,0)->text() <<ui->tableWidget_userInfo->item(row,1)->text()<<ui->tableWidget_userInfo->item(row,2)->text();
    }
    //数据更新后同步到本地
    loadDBToLocal();

    rowVec.clear();
}
