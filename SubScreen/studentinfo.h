#ifndef STUDENTINFO_H
#define STUDENTINFO_H

///@brief 学生信息界面

#include "./addstudent.h"
#include "../variableset.h"          //自定义的变量集合
#include "../Database/databasemanagement.h"     //数据库
#include "../Network/universal.h"
#include "../Thread/threadoperateexcel.h"

#include <QWidget>
#include <QModelIndex>
#include <QToolTip>
#include <QMenu>
#include <QContextMenuEvent>
#include <QPoint>
#include <QAction>

namespace Ui {
class StudentInfo;
}

class StudentInfo : public QWidget
{
    Q_OBJECT

public:
    explicit StudentInfo(QWidget *parent = nullptr);
    ~StudentInfo();

    //加载数据库学生数据到本地
    void loadDBStudentInfoToLocal();

    //设置QTableWidget表头
    void setTableWidgetHeader();

    //初始化QTableWidget的样式
    void initTableWidgetType();

    //插入数据到QTableWidget
    void insertDataToTableWidget();

    //鼠标右键添加菜单
    void initRightMenu();

    //刷新表格记录行数
    void flushTableRows(int curRow);

    //设置表格为不可编辑可被选择
    void setTableNotEdit(int &row);

private slots:
    //鼠标停留在表格的单元格时显示其单元格内容
    void slot_showTableItemToolTip(QModelIndex index);

    //从添加学生子界面传回的学生信息
    void slot_tableWidgetAddItem(VariableSet::Student &stu);

    //鼠标右键表格显示按钮菜单
    void slot_tableWidget_customContextMenuRequested(const QPoint &pos);

    //鼠标右键表格显示按钮菜单的添加删除记录
    void slot_delCurRowRecord();

    //鼠标右键表格显示按钮菜单的添加修改记录
    void slot_alterCurRowRecord();

    //鼠标右键表格显示按钮菜单的添加保存记录
    void slot_saveCurRowRecord();

    //鼠标右键表格显示按钮菜单的查询已就业学生槽函数
    void slot_queryEmploymentStu();

    //鼠标右键表格显示按钮菜单的查询未就业学生槽函数
    void slot_queryNotEmploymentStu();

    //鼠标右键表格显示按钮菜单的重置表格槽函数
    void slot_resetTable();

    void on_btn_addStu_clicked();

    void on_btn_saveToExcel_clicked();

    void on_tableWidget_studentInfo_clicked(const QModelIndex &index);


private:
    Ui::StudentInfo *ui;
    QSqlDatabase db;
    AddStudent *addStu;     //添加学生子界面

    QMenu *RMenu;
    QVector<int> recDyg;    //单元格的行列记录

    QVector<VariableSet::Student> stuInfo;      //学生信息(数据库加载到本地)
};

#endif // STUDENTINFO_H
