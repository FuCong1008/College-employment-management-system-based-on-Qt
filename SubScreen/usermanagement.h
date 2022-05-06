#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

///@brief 用户管理界面

#include "../Database/databasemanagement.h"
#include "../variableset.h" //自定义的变量集合
#include "./adduser.h"      //添加用户

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QModelIndex>
#include <QToolTip>

namespace Ui {
class UserManagement;
}

class UserManagement : public QWidget
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = nullptr);
    ~UserManagement();

    //加载数据库数据到本地
    void loadDBToLocal();

    //设置QTableWidget表头
    void setTableWidgetHeader();

    //初始化QTableWidget的样式
    void initTableWidgetType();

    //插入数据到QTableWidget
    void insertDataToTableWidget();

    //表格里面插入按钮控件
    void insertButtonToTable(int &row,int &&col);

    //工具当前登录账号的身份设置表格的(编辑和删除按钮)是否可编辑
    void setTableIsEnabled();

    //点击表格里的删除按钮后进行相应的数据处理
    void clickDelToDealWithData(int &row);

    //工具编辑按钮按下来更新数据库对应的数据
    void pressedEditBtnToUpdateDB(QString &account, QString &userName, QString &id);

private slots:
    //鼠标停留在表格的单元格时显示其单元格内容
    void on_showTableItemToolTip(QModelIndex index);

    //自定义表格里按钮的槽函数
    void slot_clickTableEditBtn();
    void slot_clickTableDeleteBtn();

    //接收添加用户子界面传递过来的用户信息，然后添加到表格中
    void on_tableWidgetAddItem(VariableSet::User &userInfo);

    void on_btn_reset_clicked();

    void on_btn_query_clicked();

    void on_btn_userInfo_clicked();

    void on_btn_save_clicked();

private:
    Ui::UserManagement *ui;
    QSqlDatabase db;
    AddUser *addUser;       //添加用户界面
    QVector<int> rowVec;    //记录按下编辑按钮所在的行

    QVector<VariableSet::User> userInfo;

    QVector<QPushButton*> btnEditVec;
    QVector<QPushButton*> btnDelVec;
};

#endif // USERMANAGEMENT_H
