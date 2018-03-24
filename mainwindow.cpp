#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commandserver.h"
#include "commanddispatcher.h"
#include "multimediacommand.h"
#include "websitecommand.h"
#include "programcommand.h"
#include "clipboardcommand.h"


MainWindow::MainWindow(QClipboard* clipboard, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MultimediaCommand* multimediaCommand = new MultimediaCommand(parent);
    WebsiteCommand* websiteCommand = new WebsiteCommand(parent);
    ProgramCommand* programCommand = new ProgramCommand(parent);
    ClipboardCommand* clipboardCommand = new ClipboardCommand(clipboard,parent);

    CommandDispatcher::RegisterCommand(clipboardCommand);
    CommandDispatcher::RegisterCommand(multimediaCommand);
    CommandDispatcher::RegisterCommand(websiteCommand);
    CommandDispatcher::RegisterCommand(programCommand);

    CommandServer& commandServer = CommandServer::GetInstance();

    commandServer.listen(QHostAddress::Any,3333);

}

MainWindow::~MainWindow()
{
    delete ui;
}
