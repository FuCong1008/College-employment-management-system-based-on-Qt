#include "universal.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

QString Universal::getLocalIP()
{
    QString ip = Q_NULLPTR;
    QHostInfo hostInfo = QHostInfo::fromName(QHostInfo::localHostName());   //从本地主机名称获取主机信息
    QList<QHostAddress> listAddr = hostInfo.addresses();    //本地主机ip地址列表(IPV4/IPV6)
    for (int i = 0; i < listAddr.size(); ++i)
    {
       if((listAddr.at(i).isNull() == false) && (listAddr.at(i).protocol() == QAbstractSocket::IPv4Protocol)
               && (listAddr.at(i) != QHostAddress::LocalHost))
       {
           ip = listAddr.at(i).toString();
           break;
       }
    }
    return ip;
}

QByteArray Universal::packStudentInfo(VariableSet::Student &stu)
{
    //学生信息打包
    QByteArray stuB;
    stuB.append((char*)&stu,sizeof(stu));
    cout << QStringLiteral("学生信息打包") << stuB.length();
    return stuB;
}

QByteArray Universal::packCompanyInfo(VariableSet::Company &com)
{
    //公司信息打包
    QByteArray comB;
    comB.append((char*)&com,sizeof(com));
    cout << QStringLiteral("公司信息打包") << comB.length();
    return comB;
}

QByteArray Universal::packUserInfo(VariableSet::User &user)
{
    //用户信息打包
    QByteArray userB;
    userB.append((char*)&user,sizeof(user));
    cout << QStringLiteral("用户信息打包") << userB.length();
    return userB;
}

VariableSet::Student Universal::unPackStudentInfo(QByteArray &qbStu)
{
    QByteArray *tmp = new QByteArray;
    tmp = &qbStu;
    VariableSet::Student stu;
    memset(&stu.StuNumber,0,sizeof(stu.StuNumber));//学号
    memcpy(&stu.StuNumber,&tmp,sizeof(stu.StuNumber));
    tmp += sizeof(stu.StuNumber);
    memset(&stu.StuClass,0,sizeof(stu.StuClass));//班级
    memcpy(&stu.StuClass,&tmp,sizeof(stu.StuClass));
    tmp += sizeof(stu.StuClass);
    memset(&stu.StuName,0,sizeof(stu.StuName));//学生姓名
    memcpy(&stu.StuName,&tmp,sizeof(stu.StuName));
    tmp += sizeof(stu.StuName);
    memset(&stu.StuSex,0,sizeof(stu.StuSex));//性别
    memcpy(&stu.StuSex,&tmp,sizeof(stu.StuSex));
    tmp += sizeof(stu.StuSex);
    memset(&stu.Major,0,sizeof(stu.Major));//专业
    memcpy(&stu.Major,&tmp,sizeof(stu.Major));
    tmp += sizeof(stu.Major);
    memset(&stu.StuPhone,0,sizeof(stu.StuPhone));//学生电话
    memcpy(&stu.StuPhone,&tmp,sizeof(stu.StuPhone));
    tmp += sizeof(stu.StuPhone);
    memset(&stu.JobTime,0,sizeof(stu.JobTime));//就业时间
    memcpy(&stu.JobTime,&tmp,sizeof(stu.JobTime));
    tmp += sizeof(stu.JobTime);
    memset(&stu.CompanyName,0,sizeof(stu.CompanyName));//就业的公司名称(与就业时间同存在)
    memcpy(&stu.CompanyName,&tmp,sizeof(stu.CompanyName));
    tmp += sizeof(stu.CompanyName);
    memset(&stu.JobPost,0,sizeof(stu.JobPost));//就业岗位
    memcpy(&stu.JobPost,&tmp,sizeof(stu.JobPost));
    tmp += sizeof(stu.JobPost);
    delete tmp;
    tmp = Q_NULLPTR;
    return stu;
}

VariableSet::Company Universal::unPackCompanyInfo(QByteArray &qbCom)
{
    QByteArray *tmp = new QByteArray;
    tmp = &qbCom;
    VariableSet::Company com;
    memset(&com.CompanySide,0,sizeof(com.CompanySide));//公司地点
    memcpy(&com.CompanySide,&tmp,sizeof(com.CompanySide));
    tmp += sizeof(com.CompanySide);
    memset(&com.CompanyName,0,sizeof(com.CompanyName));//公司名称
    memcpy(&com.CompanyName,&tmp,sizeof(com.CompanyName));
    tmp += sizeof(com.CompanyName);
    memset(&com.Contacts,0,sizeof(com.Contacts));//联系人
    memcpy(&com.Contacts,&tmp,sizeof(com.Contacts));
    tmp += sizeof(com.Contacts);
    memset(&com.ContactsPhone,0,sizeof(com.ContactsPhone));//联系人电话
    memcpy(&com.ContactsPhone,&tmp,sizeof(com.ContactsPhone));
    tmp += sizeof(com.ContactsPhone);
    memset(&com.JobPost,0,sizeof(com.JobPost));//就业岗位
    memcpy(&com.JobPost,&tmp,sizeof(com.JobPost));
    tmp += sizeof(com.JobPost);
    memset(&com.Salary,0,sizeof(com.Salary));//工资
    memcpy(&com.Salary,&tmp,sizeof(com.Salary));
    tmp += sizeof(com.Salary);
    memset(&com.AbilityRecquire,0,sizeof(com.AbilityRecquire));//能力需求
    memcpy(&com.AbilityRecquire,&tmp,sizeof(com.AbilityRecquire));
    tmp += sizeof(com.AbilityRecquire);
    delete tmp;
    tmp = Q_NULLPTR;
    return com;
}

VariableSet::User Universal::unPackUserInfo(QByteArray &qbUser)
{
    QByteArray *tmp = new QByteArray;
    tmp = &qbUser;
    VariableSet::User user;
    memset(&user.Account,0,sizeof(user.Account));//账号
    memcpy(&user.Account,&tmp,sizeof(user.Account));
    tmp += sizeof(user.Account);
    memset(&user.Password,0,sizeof(user.Password));//密码
    memcpy(&user.Password,&tmp,sizeof(user.Password));
    tmp += sizeof(user.Password);
    memset(&user.Identity,0,sizeof(user.Identity));//用户身份
    memcpy(&user.Identity,&tmp,sizeof(user.Identity));
    tmp += sizeof(user.Identity);
    memset(&user.userName,0,sizeof(user.userName));//用户姓名
    memcpy(&user.userName,&tmp,sizeof(user.userName));
    tmp += sizeof(user.userName);
    delete tmp;
    tmp = Q_NULLPTR;
    return user;
}
