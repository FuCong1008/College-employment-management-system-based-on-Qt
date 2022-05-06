#ifndef REGISTERUSER_H
#define REGISTERUSER_H

///@brief 注册界面

#include "./Warning/warninghint.h"
#include "../Database/databasemanagement.h"

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QMouseEvent>

namespace Ui {
class RegisterUser;
}

class RegisterUser : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterUser(QWidget *parent = nullptr);
    ~RegisterUser();

private:
    //拖拽窗口移动事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void sig_close();

private slots:

    void on_btn_ack_clicked();

    void on_btn_back_clicked();

private:
    Ui::RegisterUser *ui;

    QSqlDatabase db;

    //窗口移动所需变量
    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
};

#endif // REGISTERUSER_H
