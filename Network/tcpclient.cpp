#include "tcpclient.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    tcpClient=new QTcpSocket(this); //创建socket变量
    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    //connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}

void TcpClient::connectServer()
{
    QString     IP=Universal::getLocalIP();//获取IP地址
    quint16     port=56560;//端口
    QHostAddress    addr(IP);
    tcpClient->connectToHost(addr,port);
    cout << QStringLiteral("客户端正在连接服务器端");
}

void TcpClient::disConnectServer()
{
    if (tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
    cout << QStringLiteral("客户端断开服务武器接端");
}

void TcpClient::sendMsg(QByteArray &msg)
{
    msg.append('\n');
    tcpClient->write(msg);
}

void TcpClient::onConnected()
{
    cout <<QStringLiteral("客户端连接成功");
}

void TcpClient::onDisconnected()
{
    cout <<QStringLiteral("客户端断开连接成功");
}

void TcpClient::onSocketReadyRead()
{
    //客户端读取数据
//    while(tcpClient->canReadLine())
//        ui->plainTextEdit->appendPlainText("[in] "+tcpClient->readLine());
}
