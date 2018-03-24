#ifndef COMMANDTHREAD_H
#define COMMANDTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDataStream>

#define TIMEOUT 10


class CommandThread : public QThread
{
    Q_OBJECT

public:
    CommandThread(int socketDescriptor, QObject* parent);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);
    void errorTimeout();

private:
    int socketDescriptor;

};

#endif // COMMANDTHREAD_H
