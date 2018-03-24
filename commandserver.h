#ifndef COMMANDSERVER_H
#define COMMANDSERVER_H

#include <QObject>
#include <QTcpServer>

#include "commandthread.h"

class CommandServer : public QTcpServer
{
    Q_OBJECT
private:
    CommandServer(QObject *parent = nullptr);

signals:

public slots:
    static CommandServer& GetInstance();

protected:
    void incomingConnection(qintptr socketDescriptor) override;
};

#endif // COMMANDSERVER_H
