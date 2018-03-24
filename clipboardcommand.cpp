#include "clipboardcommand.h"

#include "windows.h"
#include <string>
#include <QDebug>

using namespace std;

ClipboardCommand::ClipboardCommand(QClipboard* mClipboard,  QObject* parent) : ICommand(parent), mClipboard(mClipboard)
{

}

QString ClipboardCommand::GetCommandId()
{
    return QString("pasteText");
}

void ClipboardCommand::ProcessCommand(QJsonObject *command)
{
    QString text;
    bool enter = false;
    QString returntext;

    /* Check if json contains the needed key */
    if (!command->contains("text") || !command->contains("enter"))
    {
        return;
    }

    text = (*command)["text"].toString();
    enter = (*command)["enter"].toBool();

    //mClipboard->clear();

    //mClipboard->setText(text);

    //returntext = mClipboard->text();

    bool clipopen = OpenClipboard( GetActiveWindow() );

    if (!clipopen)
    {
        qDebug() << "clipboard not open!";
        return;
    }

    bool emptyclip = EmptyClipboard();

    if (!emptyclip)
    {
        qDebug() << "clipboard not empty!";
        return;
    }

    HGLOBAL hGlob = GlobalAlloc(GMEM_FIXED,255);

    QByteArray ba = text.toLocal8Bit();

    strcpy_s((char*)hGlob, 255, ba.data());

    SetClipboardData(CF_TEXT,hGlob);

    bool closeclip = CloseClipboard();

    if (!closeclip)
    {
        qDebug() << "clipboard not closed!";
        return;
    }

    INPUT input, input2;
    uint16_t vkey = VK_CONTROL;
    uint16_t vkey2 = 0x56;

    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = vkey;
    input.ki.dwFlags = 0;

    input2.type = INPUT_KEYBOARD;
    input2.ki.wScan = MapVirtualKey(vkey2, MAPVK_VK_TO_VSC);
    input2.ki.time = 0;
    input2.ki.dwExtraInfo = 0;
    input2.ki.wVk = vkey2;
    input2.ki.dwFlags = 0;

    SendInput(1, &input, sizeof(INPUT));
    SendInput(1, &input2, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    input2.ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(1, &input, sizeof(INPUT));
    SendInput(1, &input2, sizeof(INPUT));


}
