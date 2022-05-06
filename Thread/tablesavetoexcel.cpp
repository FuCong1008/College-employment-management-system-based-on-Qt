#include "tablesavetoexcel.h"

TableSaveToExcel::TableSaveToExcel(QObject *parent) : QObject(parent)
{

}

void TableSaveToExcel::tableSaveToExcel(QTableWidget *table,const QString &title, const QString  &fileName)
{
    QMutexLocker locker(&m_stopMutex);
    if(fileName.isNull())
        return;
    QAxObject *excel = new QAxObject;
    if (excel->setControl("Excel.Application")) //连接Excel控件
    {
        excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
        excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
        QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
        workbooks->dynamicCall("Add");//新建一个工作簿
        QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
        QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
        int i,j,colcount=table->columnCount();
        QAxObject *cell,*col;
        //标题行
        cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
        cell->dynamicCall("SetValue(const QString&)", title);
        cell->querySubObject("Font")->setProperty("Size", 18);
        //调整行高
        worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
        //合并标题行
        QString cellTitle;
        cellTitle.append("A1:");
        cellTitle.append(QChar(colcount - 1 + 'A'));
        cellTitle.append(QString::number(1));
        QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
        range->setProperty("WrapText", true);
        range->setProperty("MergeCells", true);
        range->setProperty("HorizontalAlignment", -4108);//xlCenter
        range->setProperty("VerticalAlignment", -4108);//xlCenter
        //列标题
        for(i=0;i<colcount;i++)
        {
            QString columnName;
            columnName.append(QChar(i  + 'A'));
            columnName.append(":");
            columnName.append(QChar(i + 'A'));
            col = worksheet->querySubObject("Columns(const QString&)", columnName);
            col->setProperty("ColumnWidth", table->columnWidth(i)/6);
            cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
            columnName=table->horizontalHeaderItem(i)->text();
            cell->dynamicCall("SetValue(const QString&)", columnName);
            cell->querySubObject("Font")->setProperty("Bold", true);
            cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
            cell->setProperty("HorizontalAlignment", -4108);//xlCenter
            cell->setProperty("VerticalAlignment", -4108);//xlCenter
        }
        //数据区
        for(i=0;i<table->rowCount();i++){
            for (j=0;j<colcount;j++)
            {
                worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", table->item(i,j)?table->item(i,j)->text():"");
            }
        }
        //画框线
        QString lrange;
        lrange.append("A2:");
        lrange.append(colcount - 1 + 'A');
        lrange.append(QString::number(table->rowCount() + 2));
        range = worksheet->querySubObject("Range(const QString&)", lrange);
        range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
        range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
        //调整数据区行高
        QString rowsName;
        rowsName.append("2:");
        rowsName.append(QString::number(table->rowCount() + 2));
        range = worksheet->querySubObject("Range(const QString&)", rowsName);
        range->setProperty("RowHeight", 20);
        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
        workbook->dynamicCall("Close()");//关闭工作簿
        excel->dynamicCall("Quit()");//关闭excel
        delete excel;
        excel=Q_NULLPTR;
        emit sig_openExcelFile();
    }
    else
    {
        Warning::setWarning(QStringLiteral("未能创建 Excel 对象，请安装 Microsoft Excel"));
    }
}
