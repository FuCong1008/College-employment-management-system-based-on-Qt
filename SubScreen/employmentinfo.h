#ifndef EMPLOYMENTINFO_H
#define EMPLOYMENTINFO_H

///@brief 就业信息界面

#include "./addemploymentinfo.h"    //添加就业信息子界面
#include "../variableset.h"          //自定义的变量集合
#include "../Database/databasemanagement.h"     //数据库
#include "../Thread/threadoperateexcel.h"

#include <QWidget>
#include <QSqlQuery>
#include <QStringList>
#include <QModelIndex>
#include <QToolTip>

namespace Ui {
class EmploymentInfo;
}

class EmploymentInfo : public QWidget
{
    Q_OBJECT

public:
    explicit EmploymentInfo(QWidget *parent = nullptr);
    ~EmploymentInfo();

    //加载数据库数据到本地
    void loadDBToLocal();

    //设置QTableWidget表头
    void setTableWidgetHeader();

    //初始化combox的项
    void initComboxItem();

    //初始化QTableWidget的样式
    void initTableWidgetType();

    //插入数据到QTableWidget
    void insertDataToTableWidget();

    //刷新表格记录行数
    void flushTableRows(int curRow);

    //判断数据记录是否有更新
    bool judgeDataIsChange();

private slots:
    //鼠标停留在表格的单元格时显示其单元格内容
    void slot_showTableItemToolTip(QModelIndex index);

    //从添加用户子界面传回的学生公司信息
    void slot_tableWidgetAddItem(VariableSet::Stu_Company &stuCom);

    void on_btn_addEmploymentInfo_clicked();

    //重置按钮
    void on_btn_reset_clicked();

    void on_combox_province_currentTextChanged(const QString &arg1);

    //查询按钮
    void on_btn_query_clicked();

    void on_combox_faculty_currentTextChanged(const QString &arg1);

    //数据保存到excel按钮
    void on_btn_saveToExcel_clicked();

    void on_tableWidget_workInfo_clicked(const QModelIndex &index);

private:
    Ui::EmploymentInfo *ui;
    QSqlDatabase db;

    AddEmploymentInfo *addEmInfo;   //添加就业信息子对象界面

    QVector<VariableSet::Stu_Company> stuComInfo;   //学生公司信息(数据库加载到本地)

    bool flag;

//    QVector<VariableSet::Student> stuInfo;      //学生信息(数据库加载到本地)
//    QVector<VariableSet::Company> companyInfo;  //公司信息(数据库加载到本地)

//    QVector<VariableSet::City> cityInfo;        //城市信息(数据库加载到本地)
//    QVector<VariableSet::StuMajor> majorInfo;   //专业信息(数据库加载到本地)
};

#endif // EMPLOYMENTINFO_H
