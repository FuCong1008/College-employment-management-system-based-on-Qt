#include "tcpserver.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    tcpServer=new QTcpServer(this);
    //startListen();
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

void TcpServer::startListen()
{
    QString     IP=Universal::getLocalIP();//获取IP地址
    quint16     port=56560;//端口
    QHostAddress    addr(IP);
    tcpServer->listen(addr,port);//自动监听
    cout <<QStringLiteral("服务器端正在监听");
}

void TcpServer::stopListen()
{
    if (tcpServer->isListening()) //tcpServer正在监听
    {
        tcpServer->close();//停止监听
    }
}

void TcpServer::sendMsg(QByteArray &msg)
{
    //发送一行字符串，以换行符结束
//    QByteArray  str=msg.toUtf8();
    msg.append('\n');//添加一个换行符
    tcpSocket->write(msg);
}

void TcpServer::onNewConnection()
{
    tcpSocket = tcpServer->nextPendingConnection(); //创建socket

    connect(tcpSocket, SIGNAL(connected()),
            this, SLOT(onClientConnected()));
    connect(tcpSocket, SIGNAL(disconnected()),
            this, SLOT(onClientDisconnected()));

    connect(tcpSocket,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));
}

void TcpServer::onClientConnected()
{
    //客户端接入时
    cout << QStringLiteral("客户端接入时");
}

void TcpServer::onClientDisconnected()
{
    //客户端断开连接时
    cout << QStringLiteral("客户端断开连接时");
    tcpSocket->deleteLater();
}

void TcpServer::onSocketReadyRead()
{
    //读取缓冲区行文本
//        QStringList   lines;
//        while(tcpSocket->canReadLine())
//            ui->plainTextEdit->appendPlainText("[in] "+tcpSocket->readLine());
//            lines.append(clientConnection->readLine());

}
