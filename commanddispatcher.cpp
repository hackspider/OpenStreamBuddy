#include "commanddispatcher.h"

QHash<QString, ICommand*> CommandDispatcher::commands;

CommandDispatcher::CommandDispatcher(QObject* parent) : QObject(parent)
{

}

void CommandDispatcher::RegisterCommand(ICommand* command)
{
    QString commandId;

    /* Check for valid command */
    if (command == nullptr)
    {
        return;
    }

    commandId = command->GetCommandId();

    commands.insert(commandId,command);

    return;
}

void CommandDispatcher::DispatchCommand(QJsonObject* command)
{
    QString commandId = (*command)["commandId"].toString();

    /* Try to find the command ID in registered commands */
    QHash<QString, ICommand*>::const_iterator commandIterator = commands.find(commandId);

    if (commandIterator == commands.end())
    {
        /* Command ID not in the list */
        return;
    }

    ICommand* foundCommand = commandIterator.value();

    foundCommand->ProcessCommand(command);

    return;

}
