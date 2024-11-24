#include "receivefile.h"
#include <QHostAddress>

ReceiveFile::ReceiveFile(QObject *parent)
    : QObject{parent}
    , _tcpServer(new QTcpServer)
    , _tcpSocket(nullptr)
{
    connect(_tcpServer, &QTcpServer::newConnection, this, [=](){
        _tcpSocket = _tcpServer->nextPendingConnection();
        connect(_tcpSocket, &QTcpSocket::readyRead, this, &ReceiveFile::ReceiveFileTo);
    });
}

ReceiveFile::~ReceiveFile()
{
    _tcpServer->close();
    delete _tcpServer;
}

void ReceiveFile::ListenPort(unsigned short tPort)
{
    _tcpServer->listen(QHostAddress::Any, tPort);
}

void ReceiveFile::ReceiveFileTo()
{
    static int cunt = 0;
    static int total = 0;
    if(!tFile.isOpen()){
        tFile.setFileName("recv.txt");
        tFile.open(QFile::WriteOnly);
        cunt = 0;
        total = 0;
    }

    if(cunt == 0){
        _tcpSocket->read((char *)&total, 4);
    }
    QByteArray all = _tcpSocket->readAll();
    cunt += all.size();
    tFile.write(all);

    if(cunt == total){
        tFile.close();
    }
}
