#include "mainwindow.h"
#include<QSettings>
#include <QApplication>
#include<QBuffer>
//https://www.bytezonex.com/archives/mPvrYPwT.html



extern void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
extern bool testEtc(QApplication& app);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qInstallMessageHandler(customMessageHandler);
    if(testEtc(a))return 0;
    MainWindow w;
    w.show();
    return a.exec();
}
