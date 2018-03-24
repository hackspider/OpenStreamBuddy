#include "websitecommand.h"

#include <QUrl>
#include <QDesktopServices>

WebsiteCommand::WebsiteCommand(QObject* parent) : ICommand(parent)
{

}

QString WebsiteCommand::GetCommandId()
{
    return QString("website");
}

void WebsiteCommand::ProcessCommand(QJsonObject *command)
{
    QString website;

    /* Check if json contains the needed key */
    if (!command->contains("website"))
    {
        return;
    }

    website = (*command)["website"].toString();

    QUrl websiteUrl(website);

    if (!websiteUrl.isValid())
    {
        return;
    }

    QDesktopServices::openUrl(websiteUrl);

    return;
}
