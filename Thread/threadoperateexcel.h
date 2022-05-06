#ifndef THREADOPERATEEXCEL_H
#define THREADOPERATEEXCEL_H

#include "../Thread/tablesavetoexcel.h"

#include <QObject>
#include <QThread>

class ThreadOperateExcel : public QObject
{
    Q_OBJECT
public:
    explicit ThreadOperateExcel(QObject *parent = nullptr);
    ~ThreadOperateExcel();

    //对外提供数据保存到exel的接口
    void tabSaveToExcel(QTableWidget *table,const QString &title);

    //单列模式
    static ThreadOperateExcel* getInstance();

signals:
    //给子线程发射信号去执行Excel保存操作
    void tableDataSaveToExcelThread(QTableWidget *table,const QString &title, const QString  &fileName);

private:
    //子线程执行Excel操作
    void startExcelSubThread();

private slots:
    //QTableWidget数据保存到Excel成功后是否打开该excel文件
    void slot_openExcelFile();

private:
    //继承QObject,然后用继承QObject::moveToThread()方法实现多线程
    TableSaveToExcel *tabSaveToExcelThread;
    QThread *tabObjThread;
    QString excelfileName;  //打开QFileDialog保存的excel文件名称

    static ThreadOperateExcel *TOE;
};

#endif // THREADOPERATEEXCEL_H
