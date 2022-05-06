#include "login.h"
#include <QApplication>
#include <windows.h>

#include "../Database/databasemanagement.h"
#include "../Warning/warninghint.h"
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QSplashScreen>//显示程序所用到的QT类

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //禁止程序多开
    HANDLE m_hMutex = ::CreateMutex(Q_NULLPTR,true,L"SEMS");
    if(GetLastError() == ERROR_ALREADY_EXISTS)
    {
        QMessageBox waringBox(QMessageBox::Warning,QStringLiteral("警告"),QStringLiteral("程序正在运行!"));
        waringBox.setStandardButtons(QMessageBox::Ok);
        waringBox.setButtonText(QMessageBox::Ok,QStringLiteral("确定"));
        waringBox.exec();

        ::CloseHandle(m_hMutex);
        return 0;
    }

    //QApplication::addLibraryPath("./plugins");

    //数据库连接
    QSqlDatabase db;
    SEMSDatabase::DatabaseConnect(db,QStringLiteral("大学生就业管理系统数据库"));
    //SEMSDatabase::createDB(db,QStringLiteral("SEMS"));

    //Warning::setQuestion("数据库连接失败");

    //系统样式表设置
    QFile qssFile(QDir::currentPath()+"/Sheet/SEMS.qss");
    if(qssFile.open(QIODevice::ReadOnly)){
        qApp->setStyleSheet(qssFile.readAll());
        qssFile.close();
    }else{
        Warning::setWarning(QStringLiteral("读取样式表文件失败"));
    }

    Login w;
    w.show();

    return a.exec();
}
