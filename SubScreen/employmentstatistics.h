#ifndef EMPLOYMENTSTATISTICS_H
#define EMPLOYMENTSTATISTICS_H

///@brief 就业统计界面

#include "../variableset.h"          //自定义的变量集合
#include "../Database/databasemanagement.h"     //数据库

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QModelIndex>
#include <QToolTip>

namespace Ui {
class EmploymentStatistics;
}

class EmploymentStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit EmploymentStatistics(QWidget *parent = nullptr);
    ~EmploymentStatistics();

    //加载数据库数据到本地
    void loadDBToLocal();

    //设置QTableWidget表头
    void setTableWidgetHeader(QStringList &headerList);

    //初始化QTableWidget的样式
    void initTableWidgetType();

    //插入数据到QTableWidget
    void insertDataToTableWidget();

    //就业情况统计
    QMap<QString,int> countEmploymentStatus(QStringList &strInfo);

    //表格里面插入按钮控件
    void insertButtonToTable(int &row);

private slots:
    //鼠标停留在表格的单元格时显示其单元格内容
    void slot_showTableItemToolTip(QModelIndex index);

    //自定义的槽函数
    void slot_btn_lookDetail_clicked();

    //按专业统计槽函数(默认显示)
    void on_tbn_major_clicked();

    //按班级统计槽函数
    void on_tbn_class_clicked();

    //按岗位统计槽函数
    void on_tbn_post_clicked();

    //按企业统计槽函数
    void on_tbn_company_clicked();

    //按城市统计槽函数
    void on_tbn_city_clicked();

private:
    Ui::EmploymentStatistics *ui;
    QSqlDatabase db;

    QVector<VariableSet::Stu_Company> stuComInfo;   //学生就业公司信息(数据库加载到本地)
    QVector<VariableSet::Student> stuInfo;      //学生信息(数据库加载到本地)
    QVector<VariableSet::Company> companyInfo;  //公司信息(数据库加载到本地)

};

#endif // EMPLOYMENTSTATISTICS_H
