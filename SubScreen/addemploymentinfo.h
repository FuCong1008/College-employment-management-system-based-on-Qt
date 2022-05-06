#ifndef ADDEMPLOYMENTINFO_H
#define ADDEMPLOYMENTINFO_H

///@brief 添加就业信息子界面

#include "../variableset.h"
#include "../Database/databasemanagement.h"
#include "../Warning/warninghint.h"

#include <QWidget>
#include <QValidator>

namespace Ui {
class AddEmploymentInfo;
}

class AddEmploymentInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AddEmploymentInfo(QWidget *parent = nullptr);
    ~AddEmploymentInfo();

    //判断使用行编辑控件是否为空
    bool dealWithLineEditIsNull();

    //初始化combox的项
    void initComboxItem();

    //保存学生信息到学生信息表
    void saveStudentToDB(QSqlDatabase &db);

    //保存公司信息到公司信息表
    void saveCompanyToDB(QSqlDatabase &db);

signals:
    void sig_employmentInfo(VariableSet::Stu_Company &stuCom);

private slots:

    //重置界面槽函数
    void on_btn_reset_clicked();

    //提交学生-公司信息到DB中的槽函数
    void on_btn_submit_clicked();

    void on_combox_faculty_currentTextChanged(const QString &arg1);

    //通过“省”下拉框的当前文本改变来显示相应的“市”下拉框的内容(槽函数)
    void on_combox_subProvince_currentTextChanged(const QString &arg1);

private:
    Ui::AddEmploymentInfo *ui;
    QSqlDatabase db;
};

#endif // ADDEMPLOYMENTINFO_H
