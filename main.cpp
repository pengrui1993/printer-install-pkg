#include "mainwindow.h"
#include<QSettings>
#include <QApplication>
//https://www.bytezonex.com/archives/mPvrYPwT.html



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
