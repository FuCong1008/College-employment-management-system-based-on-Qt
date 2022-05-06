#include "threadoperateexcel.h"

ThreadOperateExcel* ThreadOperateExcel::TOE = Q_NULLPTR;
ThreadOperateExcel::ThreadOperateExcel(QObject *parent) : QObject(parent)
{
    tabSaveToExcelThread = Q_NULLPTR;
    tabObjThread = Q_NULLPTR;
}

ThreadOperateExcel::~ThreadOperateExcel()
{
    if(TOE != Q_NULLPTR){
        delete TOE;
        TOE = Q_NULLPTR;
    }
    if(tabSaveToExcelThread != Q_NULLPTR){
        delete tabSaveToExcelThread;
        tabSaveToExcelThread = Q_NULLPTR;
    }
    if(tabObjThread != Q_NULLPTR){
        delete tabObjThread;
        tabObjThread = Q_NULLPTR;
    }
}

void ThreadOperateExcel::tabSaveToExcel(QTableWidget *table,const QString &title)
{
    excelfileName = QFileDialog::getSaveFileName(table, "保存",
                QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                "Excel 文件(*.xls *.xlsx)");
    if(tabObjThread == Q_NULLPTR)
    {
        startExcelSubThread();
    }
    emit tableDataSaveToExcelThread(table,title,excelfileName);
}

ThreadOperateExcel *ThreadOperateExcel::getInstance()
{
    if(TOE == Q_NULLPTR){
        TOE = new ThreadOperateExcel;
    }
    return TOE;
}

void ThreadOperateExcel::startExcelSubThread()
{
    if(tabObjThread != Q_NULLPTR){
        return;
    }
    tabObjThread = new QThread;
    tabSaveToExcelThread = new TableSaveToExcel;
    tabSaveToExcelThread->moveToThread(tabObjThread);

    connect(tabObjThread,SIGNAL(finished()),tabObjThread,SLOT(deleteLater()));
    connect(tabObjThread,SIGNAL(finished()),tabSaveToExcelThread,SLOT(deleteLater()));

    connect(this,SIGNAL(tableDataSaveToExcelThread(QTableWidget*,QString,QString)),tabSaveToExcelThread,SLOT(tableSaveToExcel(QTableWidget*,QString,QString)));
    connect(tabSaveToExcelThread,SIGNAL(sig_openExcelFile()),this,SLOT(slot_openExcelFile()));
    tabObjThread->start();
}

void ThreadOperateExcel::slot_openExcelFile()
{
    if (Warning::setQuestion(QStringLiteral("文件已经导出，是否现在打开？")) == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(excelfileName)));
    }
}
