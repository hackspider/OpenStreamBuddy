#ifndef CLIPBOARDCOMMAND_H
#define CLIPBOARDCOMMAND_H

#include "icommand.h"
#include <QClipboard>

class ClipboardCommand : public ICommand
{
public:
    ClipboardCommand(QClipboard* clipboard,  QObject* parent = nullptr);

    QString GetCommandId() override;
    void ProcessCommand(QJsonObject* command) override;

private:
    QClipboard* mClipboard;
};

#endif // CLIPBOARDCOMMAND_H
