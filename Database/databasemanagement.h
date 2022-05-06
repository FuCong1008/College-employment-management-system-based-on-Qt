#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include "../Network/universal.h"
#include "../Warning/configvalue.h"
#include "../Warning/warninghint.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QThread>
#include <QSettings>

/********学生就业管理系统数据库********/
namespace SEMSDatabase {
    //连接数据库
    void DatabaseConnect(QSqlDatabase &db,QString connectName);

    //断开与数据库的连接
    bool DatabaseDisConnect(QString connectName);

    //创建数据库(SEMS)
    void createDB(QSqlDatabase &db,const QString &DbName);

} // namespace SEMSDatabase

#endif // DATABASEMANAGEMENT_H
