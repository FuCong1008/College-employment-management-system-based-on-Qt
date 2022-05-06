#include "databasemanagement.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

void SEMSDatabase::DatabaseConnect(QSqlDatabase &db, QString connectName)
{
    //数据库初始化
    if(true == QSqlDatabase::contains(connectName))
    {
        db = QSqlDatabase::database(connectName);
        //cout << QStringLiteral("已存在的连接名称");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QMYSQL",connectName);
        //cout << QStringLiteral("新添加的连接名称");
    }


    QString hostIp = ConfigValue::getConfigValueWithKey("Config/sqlConfig.ini","CONNECTMYSQL/SERVER").toString();
    quint32 Port = 3306;
    QString DbName = "sems";
    QString UID = "sa";
    QString PWD = "1008";

    //先修改数据库配置文件的ip
    //QString hostIp = Universal::getLocalIP();
    //ConfigValue::setConfigValueWithKey("Config/sqlConfig.ini","CONNECTMYSQL/SERVER",hostIp);

    //读取数据库的配置文件
    QSettings settings("Config/sqlConfig.ini",QSettings::IniFormat);
    hostIp = settings.value("CONNECTMYSQL/SERVER").toString();
    Port = settings.value("CONNECTMYSQL/PORT").toInt();
    DbName = settings.value("CONNECTMYSQL/DbName").toString();
    UID = settings.value("CONNECTMYSQL/UID").toString();
    PWD = settings.value("CONNECTMYSQL/PWD").toString();
    //cout << QStringLiteral("数据库连接信息:")<<hostIp<<Port<<DbName<<UID<<PWD;

//    //以下为sqlserver的连接方式
//    QString connectInfo = QString("DRIVER={QMYSQL};SERVER=%1;DbName=%2;UID=%3;PWD=%4;")
//            .arg(hostIp).arg(DbName).arg(UID).arg(PWD);
//    db.setDatabaseName(connectInfo);

    db.setHostName(hostIp);
    db.setPort(Port);
    db.setDatabaseName(DbName);
    db.setUserName(UID);
    db.setPassword(PWD);

    int i=0;
    do{
        db.open();  //打开数据库
        i++;
        if(db.isOpen() == false)
        {
            QThread::msleep(300);
            cout << QStringLiteral("数据库重连...") << connectName;
        }
        else {
            break;
        }
    }while(i<10);

    if(db.isOpen() == false)
    {
        Warning::setWarning("connect database defeat");
        cout << QStringLiteral("connect database defeat：") << connectName;
    }
    else {
        //cout <<QStringLiteral("connect database success：") << connectName;
    }
}

bool SEMSDatabase::DatabaseDisConnect(QString connectName)
{
    if(QSqlDatabase::contains(connectName))
    {
        QSqlDatabase::removeDatabase(connectName);
    }
    return true;
}

void SEMSDatabase::createDB(QSqlDatabase &db,const QString &DbName)
{
    //创建数据库
    QSqlQuery query(db);
    query.prepare("create database if not exists ?");
    query.bindValue(0,DbName);
    query.exec();
    if(query.lastError().isValid() == false)
    {
        cout << "create database fail info:" <<query.lastError();
    }
    else
    {
        cout << "create database success";
    }
}
