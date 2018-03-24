#ifndef COMMANDDISPATCHER_H
#define COMMANDDISPATCHER_H

#include <QObject>
#include <QHash>
#include <QJsonObject>

#include "icommand.h"

class CommandDispatcher : public QObject
{
    Q_OBJECT
public:


signals:

public slots:
    static void RegisterCommand(ICommand* command);
    static void DispatchCommand(QJsonObject* command);

private:
    explicit CommandDispatcher(QObject *parent = nullptr);
    static QHash<QString, ICommand*> commands;
};

#endif // COMMANDDISPATCHER_H
