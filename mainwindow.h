#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "receivefile.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ListenPushButton_clicked();

private:
    Ui::MainWindow *ui;

    ReceiveFile * _recvFile;
    QThread       _thread;

};
#endif // MAINWINDOW_H
