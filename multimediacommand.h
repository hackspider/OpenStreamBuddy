#ifndef MULTIMEDIACOMMAND_H
#define MULTIMEDIACOMMAND_H

#include "icommand.h"

#include <QJsonObject>

class MultimediaCommand : public ICommand
{
public:
    MultimediaCommand(QObject *parent = nullptr);

    QString GetCommandId() override;
    void ProcessCommand(QJsonObject* command) override;

private:
    void ProcessKey(uint16_t mediaKey);
};

#endif // MULTIMEDIACOMMAND_H
