#include "mainwindow.h"
#include<QSettings>
#include <QApplication>
#include<QBuffer>
//https://www.bytezonex.com/archives/mPvrYPwT.html

extern void xmlTest();

int main(int argc, char *argv[])
{

    xmlTest();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
