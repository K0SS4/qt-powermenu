#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font = ui->labelTitle->font();
    font.setPointSize(20);
    font.setBold(true);
    font.setFamily("Ubuntu Mono");
    ui->labelTitle->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonPower_clicked()
{
    QProcess process;
    process.startDetached("systemctl", {"poweroff"});
    QApplication::quit();
}


void MainWindow::on_buttonReboot_clicked()
{
    QProcess process;
    process.startDetached("systemctl", {"reboot"});
    QApplication::quit();
}


void MainWindow::on_buttonLogout_clicked()
{
    QProcess process;
    process.startDetached("pkill", {"-u" + qgetenv("USER")});
    QApplication::quit();
}


void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}

