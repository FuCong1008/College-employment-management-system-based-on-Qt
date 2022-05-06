#ifndef UNIVERSAL_H
#define UNIVERSAL_H

#include "../variableset.h"
#include "../Warning/warninghint.h"

#include <QString>
#include <QHostInfo>
#include <QString>


namespace Universal {
    //获取本地电脑的IP地址
    QString getLocalIP();

    /**封包信息**/
    //学生信息封包
    QByteArray packStudentInfo(VariableSet::Student &stu);

    //公司信息封包
    QByteArray packCompanyInfo(VariableSet::Company &com);

    //用户注册信息封包
    QByteArray packUserInfo(VariableSet::User &user);

    /**解包信息**/
    //学生信息解包
    VariableSet::Student unPackStudentInfo(QByteArray &qbStu);

    //公司信息解包
    VariableSet::Company unPackCompanyInfo(QByteArray &qbCom);

    //用户注册信息解包
    VariableSet::User unPackUserInfo(QByteArray &qbUser);

} // namespace Network


#endif // UNIVERSAL_H
