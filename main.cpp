#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QClipboard* clipboard = QApplication::clipboard();

    MainWindow w(clipboard);
    w.show();

    return a.exec();
}
