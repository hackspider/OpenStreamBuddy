#include "commandserver.h"

CommandServer::CommandServer(QObject *parent) : QTcpServer(parent)
{

}



CommandServer& CommandServer::GetInstance()
{
    static CommandServer* instance = 0;
    if ( instance == 0 )
    {
        instance = new CommandServer();
    }

    return *instance;
}

void CommandServer::incomingConnection(qintptr socketDescriptor)
{
    CommandThread* thread = new CommandThread(socketDescriptor,this);
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    thread->start();
}
