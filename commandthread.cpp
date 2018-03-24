#include "commandthread.h"
#include "commanddispatcher.h"

#include <QJsonDocument>
#include <QJsonObject>

CommandThread::CommandThread(int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{

}

void CommandThread::run()
{
    QTcpSocket tcpSocket;
    uint8_t timeoutCounter = TIMEOUT;

    bool result;

    /* Set socket descriptor */
    if (!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        return;
    }

    /* Read data from tcp socket including timeout handling */
    do {
        result = tcpSocket.waitForReadyRead();
        timeoutCounter--;
    }
    while (result || timeoutCounter == 0);

    QByteArray data = tcpSocket.readAll();

    /* Check if data received successfully or timeout occured */
    if (timeoutCounter == 0)
    {
        return;
    }

    QJsonParseError parseError;

    QJsonDocument receivedJsonDoc(QJsonDocument::fromJson(data, &parseError));

    if (parseError.error != QJsonParseError::NoError)
    {
        return;
    }

    QJsonObject receivedJsonObject = receivedJsonDoc.object();

    if (!receivedJsonObject.contains("commandId"))
    {
        return;
    }

    CommandDispatcher::DispatchCommand(&receivedJsonObject);
}
