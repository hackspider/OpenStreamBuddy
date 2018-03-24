#include "programcommand.h"

#include <QFileInfo>
#include <QProcess>
#include <QDir>

ProgramCommand::ProgramCommand(QObject* parent) : ICommand(parent)
{

}

QString ProgramCommand::GetCommandId()
{
    return QString("program");
}

void ProgramCommand::ProcessCommand(QJsonObject *command)
{
    QString program;
    QString arguments;
    QString workingDir;

    /* Check if json contains the needed key */
    if (!command->contains("program") || !command->contains("arguments"))
    {
        return;
    }

    program = (*command)["program"].toString();
    arguments = (*command)["arguments"].toString();

    QFileInfo checkFile(program);

    if (!checkFile.exists() || !checkFile.isFile() || !checkFile.isExecutable())
    {
        return;
    }

    workingDir = checkFile.absoluteDir().absolutePath();

    QProcess exec;
    QStringList args =  arguments.split(" ");

    exec.startDetached(program,args,workingDir);

    return;
}


