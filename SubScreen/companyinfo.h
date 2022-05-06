#ifndef COMPANYINFO_H
#define COMPANYINFO_H

///@brief 公司信息界面

#include "../variableset.h"          //自定义的变量集合
#include "../Database/databasemanagement.h"     //数据库
#include "./addcompany.h"       //添加公司信息子界面
#include "./Thread/threadoperateexcel.h"

#include <QWidget>
#include <QModelIndex>
#include <QToolTip>
#include <QMenu>
#include <QContextMenuEvent>
#include <QPoint>
#include <QAction>
#include <QInputDialog>

namespace Ui {
class CompanyInfo;
}

class CompanyInfo : public QWidget
{
    Q_OBJECT

public:
    explicit CompanyInfo(QWidget *parent = nullptr);
    ~CompanyInfo();

    //加载数据库公司数据到本地
    void loadDBCompanyInfoToLocal();

    //设置QTableWidget表头
    void setTableWidgetHeader();

    //初始化QTableWidget的样式
    void initTableWidgetType();

    //插入数据到QTableWidget
    void insertDataToTableWidget();

    //事件
    //void contextMenuEvent(QContextMenuEvent *event);

    //鼠标右键添加菜单
    void initRightMenu();

    //刷新表格记录行数
    void flushTableRows(int curRow);

    //设置表格为不可编辑可被选择
    void setTableNotEdit(int &row);

    //判断数据记录是否有更新
    bool judgeDataIsChange();

private slots:
    //鼠标停留在表格的单元格时显示其单元格内容
    void slot_showTableItemToolTip(QModelIndex index);

    //从添加公司子界面传回的公司信息
    void slot_tableWidgetAddItem(VariableSet::Company &com);

    //添加菜单
    void slot_tableWidget_customContextMenuRequested(const QPoint &pos);

    //鼠标右键表格添加投递简历
    void slot_ActionDeliverResume();

    //鼠标右键表格添加删除记录
    void slot_delCurRowRecord();

    //鼠标右键表格添加修改记录
    void slot_alterCurRowRecord();

    //鼠标右键表格添加保存记录
    void slot_saveCurRowRecord();

    void on_btn_addCompany_clicked();

    void on_btn_saveToExcel_clicked();

    void on_tableWidget_companyInfo_clicked(const QModelIndex &index);

private:
    Ui::CompanyInfo *ui;
    QSqlDatabase db;
    AddCompany *addCompany;     //添加公司信息子对象界面

    QMenu *RMenu;
    QVector<int> recDyg;        //单元格的行列记录

    QVector<VariableSet::Company> companyInfo;  //公司信息(数据库加载到本地)

    bool flag;
};

#endif // COMPANYINFO_H
