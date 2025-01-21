#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QSettings>
#include <QMainWindow>
#include <MyRequestHandler.h>
#include "httpserver/httplistener.h"
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    MyRequestHandler* handler;
    stefanfrings::HttpListener* listener;
    QSettings setting;
    bool started{false};
};
#endif // MAINWINDOW_H
