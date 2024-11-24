#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _recvFile(new ReceiveFile)
{
    ui->setupUi(this);
    _recvFile->moveToThread(&_thread);
    _thread.start();

}

MainWindow::~MainWindow()
{
    delete ui;
    _thread.quit();
    _thread.wait();
    _recvFile->deleteLater();
}


void MainWindow::on_ListenPushButton_clicked()
{
    unsigned short tPort = ui->protLineEdit->text().toUShort();
    _recvFile->ListenPort(tPort);
}

