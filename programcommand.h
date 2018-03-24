#ifndef PROGRAMCOMMAND_H
#define PROGRAMCOMMAND_H

#include <QObject>

#include "icommand.h"

class ProgramCommand : public ICommand
{
public:
    ProgramCommand(QObject* parent = nullptr);

    QString GetCommandId() override;
    void ProcessCommand(QJsonObject* command) override;
};

#endif // PROGRAMCOMMAND_H
