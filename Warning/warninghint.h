#ifndef WARNINGHINT_H
#define WARNINGHINT_H

#include <QString>
#include <QMessageBox>

/********系统警告框********/
namespace Warning {
    //警告框
    void setWarning(const QString &warning);

    //提示框
    void setInformation(const QString &info);

    //提问
    QMessageBox::StandardButton setQuestion(const QString &ques);
} // namespace Warning

#endif // WARNINGHINT_H
