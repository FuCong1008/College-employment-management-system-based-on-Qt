#ifndef ADDUSER_H
#define ADDUSER_H

///@brief 添加用户界面

#include "../Database/databasemanagement.h"
#include "../variableset.h"
#include "../Warning/warninghint.h"

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class AddUser;
}

class AddUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = nullptr);
    ~AddUser();

protected:
    void    closeEvent(QCloseEvent *event);

signals:
    void sig_submitUserData(VariableSet::User &userinfo);

private slots:
    void on_btn_reset_clicked();

    void on_btn_submit_clicked();

private:
    Ui::AddUser *ui;
    QSqlDatabase db;
};

#endif // ADDUSER_H
