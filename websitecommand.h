#ifndef WEBSITECOMMAND_H
#define WEBSITECOMMAND_H

#include "icommand.h"

#include <QJsonObject>

class WebsiteCommand : public ICommand
{
public:
    WebsiteCommand(QObject *parent = nullptr);

    QString GetCommandId() override;
    void ProcessCommand(QJsonObject* command) override;
};

#endif // WEBSITECOMMAND_H
