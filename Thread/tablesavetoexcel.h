#ifndef TABLESAVETOEXCEL_H
#define TABLESAVETOEXCEL_H

#include "../Warning/warninghint.h"

#include <QObject>

#include <QMutex>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QAxObject>

class TableSaveToExcel : public QObject
{
    Q_OBJECT
public:
    explicit TableSaveToExcel(QObject *parent = nullptr);

signals:
    //给主线程发射信号(QTableWidget数据保存到Excel成功后是否打开该excel文件)
    void sig_openExcelFile();

public slots:
    void tableSaveToExcel(QTableWidget *table,const QString &title, const QString  &fileName);

private:
    //互斥量(用于线程同步)
    QMutex m_stopMutex;
};

#endif // TABLESAVETOEXCEL_H
