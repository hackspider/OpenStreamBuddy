#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <QObject>
#include <QString>
#include <QJsonObject>

class ICommand : public QObject
{
    Q_OBJECT
public:
    ICommand(QObject *parent = nullptr);

    virtual QString GetCommandId() = 0;
    virtual void ProcessCommand(QJsonObject* command) = 0;

signals:

public slots:
};

#endif // ICOMMAND_H
