#ifndef UDPC2C_H
#define UDPC2C_H

#include "./universal.h"
#include "../variableset.h"
#include "../Warning/configvalue.h"

#include <QObject>
#include <QUdpSocket>
#include <QString>

class UdpC2C : public QObject
{
    Q_OBJECT
public:
    explicit UdpC2C(QObject *parent = nullptr);

    void startConnect();
    void stopConnect();

    //加入组播
    void joinGroupcast();
    //退出组播
    void stopGroupcast();

    //单播消息
    void unicast(VariableSet::Student &stu);
    void unicast(VariableSet::Company &com);

    //广播消息
    void broadcast(VariableSet::Company &com);

    //组播消息
    void multicast(VariableSet::Company &com);

signals:

public slots:
    //读取socket传入的数据
    void onSocketReadyRead();

private:
    QUdpSocket  *udpSocket;//
    QHostAddress groupAddress;//组播地址
    QString msg;
};

#endif // UDPC2C_H
