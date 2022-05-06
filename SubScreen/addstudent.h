#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

///@brief 添加学生信息子界面

#include "./variableset.h"
#include "../Warning/warninghint.h"
#include "../Database/databasemanagement.h"

#include <QWidget>

namespace Ui {
class AddStudent;
}

class AddStudent : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();

    //判断使用行编辑控件是否为空
    bool dealWithLineEditIsNull();

    //保存学生信息到学生信息表
    void saveStudentToDB(QSqlDatabase &db);

    //初始化combox的项
    void initComboxItem();

    //重置学生姓名和学号
    void resetStuNameAndStuNumber();

signals:
    void sig_studentInfo(VariableSet::Student &stu);

private slots:
    //提交学生信息到DB中的槽函数
    void on_btn_submit_clicked();

    void on_btn_reset_clicked();

    void on_combox_faculty_currentTextChanged(const QString &arg1);

private:
    Ui::AddStudent *ui;
    QSqlDatabase db;

};

#endif // ADDSTUDENT_H
