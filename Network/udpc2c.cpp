#include "udpc2c.h"

#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<"]["<<__LINE__<<"]"

UdpC2C::UdpC2C(QObject *parent) : QObject(parent)
{
    //用于与连接的客户端通讯的QTcpSocket
    udpSocket=new QUdpSocket(this);

    //Multicast路由层次，1表示只在同一局域网内
        //组播TTL: 生存时间，每跨1个路由会减1，多播无法跨过大多数路由所以为1
        //默认值是1，表示数据包只能在本地的子网中传送。
    udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption,1);

    connect(udpSocket,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));
}

void UdpC2C::startConnect()
{
    qint8 port = ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDPGROUP/ADMINPORT").toInt(); //端口
    if(udpSocket->localPort()!=port){
        if(!udpSocket->bind(port)){
            cout << QStringLiteral("绑定端口失败");
        }
    }
}

void UdpC2C::stopConnect()
{//解除绑定
    udpSocket->abort();
}

void UdpC2C::joinGroupcast()
{
    QString IP=ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDPGROUP/GROUPCASTIP").toString(); //组播IP
    groupAddress=QHostAddress(IP);//多播组地址
    quint16 groupPort=ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDPGROUP/GROUPCASTPORT").toInt(); //端口
    if (udpSocket->bind(QHostAddress::AnyIPv4, groupPort, QUdpSocket::ShareAddress))//先绑定端口
    {
        udpSocket->joinMulticastGroup(groupAddress); //加入多播组
    }
    else
        cout << QStringLiteral("绑定组播端口失败");
}

void UdpC2C::stopGroupcast()
{//退出组播
    udpSocket->leaveMulticastGroup(groupAddress);//退出组播
    //udpSocket->abort(); //解除绑定
}

void UdpC2C::unicast(VariableSet::Student &stu)
{
    QString     targetIP=ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDP_ADMIN/ADMINTIP").toString(); //目标IP
    QHostAddress    targetAddr(targetIP);
    quint16     targetPort=ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDP_ADMIN/ADMINPORT ").toInt(); //目标port
    QByteArray msg = Universal::packStudentInfo(stu);
    udpSocket->writeDatagram(msg,targetAddr,targetPort); //发出数据报
}

void UdpC2C::unicast(VariableSet::Company &com)
{
    QString     targetIP=ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDP_ADMIN/ADMINTIP").toString(); //目标IP
    QHostAddress    targetAddr(targetIP);
    quint16     targetPort=ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDP_ADMIN/ADMINPORT ").toInt(); //目标port
    QByteArray msg = Universal::packCompanyInfo(com);
    udpSocket->writeDatagram(msg,targetAddr,targetPort); //发出数据报
}

void UdpC2C::broadcast(VariableSet::Company &com)
{
    //广播消息
    quint16     targetPort=ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDP_ADMIN/ADMINPORT ").toInt(); //目标port
    QByteArray msg = Universal::packCompanyInfo(com);
    udpSocket->writeDatagram(msg,QHostAddress::Broadcast,targetPort);

}

void UdpC2C::multicast(VariableSet::Company &com)
{//发送组播消息
    quint16 groupPort = ConfigValue::getConfigValueWithKey("Config/netConfig.ini","UDPGROUP/GROUPCASTPORT").toInt(); //端口
    QByteArray msg = Universal::packCompanyInfo(com);
    udpSocket->writeDatagram(msg,groupAddress,groupPort);
}

void UdpC2C::onSocketReadyRead()
{//读取收到的数据报
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray   datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        QHostAddress    peerAddr;
        quint16 peerPort;
        udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
        msg=datagram.data();
    }
}
