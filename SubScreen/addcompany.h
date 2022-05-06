#ifndef ADDCOMPANY_H
#define ADDCOMPANY_H

///@brief 添加公司信息子界面

#include "./variableset.h"
#include "../Warning/warninghint.h"
#include "../Database/databasemanagement.h"

#include <QWidget>

namespace Ui {
class AddCompany;
}

class AddCompany : public QWidget
{
    Q_OBJECT

public:
    explicit AddCompany(QWidget *parent = nullptr);
    ~AddCompany();

    //判断使用行编辑控件是否为空
    bool dealWithLineEditIsNull();

    //保存公司信息到公司信息表
    void saveCompanyToDB(QSqlDatabase &db);

    //初始化combox的项
    void initComboxItem();

signals:
    void sig_companyInfo(VariableSet::Company &com);

private slots:
    void on_btn_submit_clicked();

    void on_btn_reset_clicked();

    //通过“省”下拉框的当前文本改变来显示相应的“市”下拉框的内容(槽函数)
    void on_combox_showProvince_currentTextChanged(const QString &arg1);

private:
    Ui::AddCompany *ui;
    QSqlDatabase db;
};

#endif // ADDCOMPANY_H
