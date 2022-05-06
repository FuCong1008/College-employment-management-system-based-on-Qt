#ifndef LOGIN_H
#define LOGIN_H

///@brief 登录界面

#include "../Network/tcpserver.h"
#include "../Network/tcpclient.h"
#include "./Warning/warninghint.h"
#include "./switchscreen.h"
#include "./registeruser.h"

#include <QWidget>
#include <QString>
#include <QMouseEvent>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    //加载记录登录信息表数据到本地
    void loadDBofRecordLoginToLocal();

    //初始化combox账号的项
    void ComboxAddItem();

private:
    //拖拽窗口移动事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //键盘事件（按回车确定登入）
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

    //登入操作函数
    void loginOperate();

    //加载用户数据库数据到本地
    void loadDBToLocal();

private slots:
    void on_btn_login_clicked();

    void on_btn_register_clicked();

    void on_btn_exit_clicked();

    void on_combox_account_currentTextChanged(const QString &arg1);

    void slot_resetkeyPressTime();

private:
    Ui::Login *ui;
    QSqlDatabase db;
    SwitchScreen *switchScreen;
    RegisterUser *regUser;      //注册用户界面
    TcpServer *tcpServerr;
    TcpClient *tcpClient;

    QVector<VariableSet::User> userInfo;    //用户信息
    QVector<VariableSet::RecordLoginInfo> recLoginInfo;  //记录登录信息（这更点击了登录按钮关联，和其它无关）

    //窗口移动所需变量
    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;

    int keyPressTime;   //键盘按下的次数，正常为1就执行相应操作
};

#endif // LOGIN_H
