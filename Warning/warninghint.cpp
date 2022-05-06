#include "warninghint.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

void Warning::setWarning(const QString &warning)
{
    QMessageBox::warning(Q_NULLPTR,QStringLiteral("警告"),(warning),QMessageBox::Ok);
//    QMessageBox::setWindowFlags(Qt::FramelessWindowHint);
}

void Warning::setInformation(const QString &info)
{
    QMessageBox::information(Q_NULLPTR,QStringLiteral("提示"),(info));
}

QMessageBox::StandardButton Warning::setQuestion(const QString &ques)
{
    return QMessageBox::question(Q_NULLPTR,QStringLiteral("提示"),(ques),QMessageBox::Yes | QMessageBox::No);
}
