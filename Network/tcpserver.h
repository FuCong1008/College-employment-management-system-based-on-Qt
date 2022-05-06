#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "./universal.h"
#include "../Warning/configvalue.h"

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

    //服务器进行监听(这里可能有问题,管理员登录成功调用这个函数)
    void startListen();

    //服务器停止监听(这里可能有问题,管理员退出登录调用这个函数，也可保持24小时登录，因为它是服务器)
    void stopListen();

    //服务器发送消息(管理员发送)
    void sendMsg(QByteArray &msg);
private:
    QTcpServer *tcpServer; //TCP服务器

    QTcpSocket *tcpSocket;//TCP通讯的Socket

private slots:
    //自定义槽函数
    void    onNewConnection();//QTcpServer的newConnection()信号

    void    onClientConnected(); //Client Socket connected
    void    onClientDisconnected();//Client Socket disconnected

    //读取socket传入的数据（读取用户发送的消息）
    void    onSocketReadyRead();

signals:

public slots:
};

#endif // TCPSERVER_H
