#ifndef SWITCHSCREEN_H
#define SWITCHSCREEN_H

///@brief 子界面切换界面

#include "../SubScreen/employmentinfo.h"            //就业信息界面
#include "../SubScreen/studentinfo.h"               //学生信息界面
#include "../SubScreen/companyinfo.h"               //公司信息界面
#include "../SubScreen/employmentstatistics.h"      //就业统计界面
#include "../SubScreen/usermanagement.h"            //用户管理界面
#include "../Database/databasemanagement.h"         //数据库管理

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QMouseEvent>


namespace Ui {
class SwitchScreen;
}

class SwitchScreen : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchScreen(QWidget *parent = nullptr);
    ~SwitchScreen();

    //设置当前界面的子界面显示
    void setSubScreen();

    //加载记录登录信息表的当前登录账号的身份
    void getUserIdOnDBLoginFlag();

    //从数据库中获取当前登录账号的身份
    QString getCurLoginUserIdentity();

    //设置当前登录账号的身份
    void setCurLoginUserIdentity();

    //登录后显示的主界面
    void setLoginMainScreen();

private:
    //拖拽窗口移动事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void sig_close();

private slots:

    //给左上角设置成为时间显示
    void setLabelShowTime();

    void on_tbn_info_clicked();

    void on_tbn_count_clicked();

    void on_tbn_userManagement_clicked();

    void on_tbn_stuInfo_clicked();

    void on_tbn_company_clicked();

    void on_tbn_exit_clicked();

    void on_tbn_userId_clicked();

private:
    Ui::SwitchScreen *ui;
    QSqlDatabase db;

    QString userAccount;
    QString userId;
    //子界面
    EmploymentInfo *employInfo;
    StudentInfo *stuInfo;
    CompanyInfo *companyInfo;
    EmploymentStatistics *employStatis;
    UserManagement *userManagement;

    QTimer *currentTime;    //定时器

    //窗口移动所需变量
    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;

    //QVector<VariableSet::RecordLoginInfo> recLoginInfo;  //记录登录信息
};

#endif // SWITCHSCREEN_H
