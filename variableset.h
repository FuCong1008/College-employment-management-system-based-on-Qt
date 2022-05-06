#ifndef VARIABLESET_H
#define VARIABLESET_H

#include <QObject>
#include <QString>

namespace VariableSet {
    //学生信息表
    struct Student
    {
        QString StuNumber;      //学号
        QString StuClass;       //班级
        QString StuName;        //学生姓名
        QString StuSex;         //性别
        QString Major;          //专业
        QString StuPhone;       //学生电话
        //备注:若学生已就业,以下三个都不为空.若未就业,则以下三个都为空
        QString JobTime;        //就业时间
        QString CompanyName;    //就业的公司名称(与就业时间同存在)
        QString JobPost;        //就业岗位
        Student() {}
    };

    //公司信息表
    struct Company
    {
        QString CompanySide;        //公司地点
        QString CompanyName;        //公司名称
        QString Contacts;           //联系人
        QString ContactsPhone;      //联系人电话
        QString JobPost;            //就业岗位
        QString Salary;             //工资
        QString AbilityRecquire;    //能力需求
        Company() {}
    };

    //学生-公司信息联合表
    struct Stu_Company
    {
        QString StuNumber;      //学号
        QString StuClass;       //班级
        QString StuName;        //学生姓名
        QString StuSex;         //性别
        QString Major;          //专业
        QString StuPhone;       //学生电话
        QString JobTime;        //就业时间
        QString CompanyName;    //就业的公司名称(与就业时间同存在)
        QString CompanySide;        //公司地点
        QString Contacts;           //联系人
        QString ContactsPhone;      //联系人电话
        QString JobPost;            //就业岗位
        QString Salary;             //工资
        QString AbilityRecquire;    //能力需求
        Stu_Company() {}
    };

    //用户信息表
    struct User
    {
        QString Account;        //账号
        QString Password;       //密码
        QString Identity;       //用户身份
        QString userName;       //用户姓名
        User() {}
    };

    //登录信息记录表
    struct RecordLoginInfo
    {
        QString Account;        //记录账号
        QString Password;       //记录密码
        QString LoginFlag;      //登录标志(空表示当前号未登录)(注意，一次只能登录一个账号，所以只有一个登录标志为yes,其它都为no)
        RecordLoginInfo() {}
    };

    struct City
    {
        QString Province;       //省
        QString Town;           //市
        City() {}
    };

} // namespace Variable

//Q_DECLEARE_METATYPE(VariableSet::Student);
//Q_DECLEARE_METATYPE(VariableSet::Company);
//Q_DECLEARE_METATYPE(VariableSet::User);
#endif // VARIABLESET_H
