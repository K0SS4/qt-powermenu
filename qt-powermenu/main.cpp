#include "mainwindow.h"

#include <QApplication>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
    QProcess* process = new QProcess();
    process->start("pgrep", {"qt-powermenu"});
    process->waitForFinished();

    if(process->readAllStandardOutput().split('\n').length() > 2) //Check if application is already running
    {
        delete process;
        return 0;
    }

    delete process;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
