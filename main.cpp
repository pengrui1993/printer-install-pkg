#include "mainwindow.h"
#include<QSettings>
#include <QApplication>
#include<QBuffer>
//https://www.bytezonex.com/archives/mPvrYPwT.html

extern bool testEtc();

extern void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
extern void testPaint(QApplication& app);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //testPaint(a);
    //qInstallMessageHandler(customMessageHandler);
    //if(testEtc())return 0;
    MainWindow w;
    w.show();
    return a.exec();
}
