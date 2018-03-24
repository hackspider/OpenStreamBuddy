#include "multimediacommand.h"

#include "windows.h"

MultimediaCommand::MultimediaCommand(QObject *parent) : ICommand(parent)
{

}

QString MultimediaCommand::GetCommandId()
{
    return QString("multimediakey");
}

void MultimediaCommand::ProcessCommand(QJsonObject* command)
{
    QString multimediaKey;

    /* Check if json contains the needed key */
    if (!command->contains("multimediakey"))
    {
        return;
    }

    multimediaKey = (*command)["multimediakey"].toString();

    if (multimediaKey == "previoustrack")
    {
        ProcessKey(VK_MEDIA_PREV_TRACK);
    }
    else if (multimediaKey == "playpause")
    {
        ProcessKey(VK_MEDIA_PLAY_PAUSE);
    }
    else if (multimediaKey == "nexttrack")
    {
        ProcessKey(VK_MEDIA_NEXT_TRACK);
    }
    else if (multimediaKey == "stop")
    {
        ProcessKey(VK_MEDIA_STOP);
    }
    else if (multimediaKey == "mute")
    {
        ProcessKey(VK_VOLUME_MUTE);
    }
    else if (multimediaKey == "increasevolume")
    {
        ProcessKey(VK_VOLUME_UP);
    }
    else if (multimediaKey == "decreasevolume")
    {
        ProcessKey(VK_VOLUME_DOWN);
    }
    else
    {
        return;
    }

    return;
}

void MultimediaCommand::ProcessKey(uint16_t mediaKey)
{
    INPUT input;

    input.type= INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.dwFlags = 0;

    input.ki.wVk = mediaKey;

    SendInput(1,&input, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(1,&input, sizeof(INPUT));
}
