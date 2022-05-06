#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "./universal.h"

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);

    //连接服务器端(这里可能有问题,客户端登录成功调用这个函数)
    void connectServer();

    //断开与服务器的连接(这里可能有问题,客户端退出登录调用这个函数)
    void disConnectServer();

    //发送数据
    void sendMsg(QByteArray &msg);

private:
    QTcpSocket  *tcpClient;  //socket

signals:

private slots:
//自定义槽函数
    void    onConnected();
    void    onDisconnected();
    void    onSocketReadyRead();//读取socket传入的数据
};

#endif // TCPCLIENT_H
