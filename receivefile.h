#ifndef RECEIVEFILE_H
#define RECEIVEFILE_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>

class ReceiveFile : public QObject
{
    Q_OBJECT
public:
    explicit ReceiveFile(QObject *parent = nullptr);

    ~ReceiveFile();

    void ListenPort(unsigned short tPort);

    void ReceiveFileTo();

signals:

private:
    QTcpServer * _tcpServer;
    QTcpSocket * _tcpSocket;
    QFile tFile;

};

#endif // RECEIVEFILE_H
