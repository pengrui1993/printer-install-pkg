#include "mainwindow.h"
#include<QSettings>
#include <QApplication>
//https://www.bytezonex.com/archives/mPvrYPwT.html
#include "MyRequestHandler.h"
#include "httpserver/httplistener.h"

static void initDoc(QSettings& setting){
    setting.setValue("document/path","document");
    setting.setValue("document/encoding","UTF-8");
    setting.setValue("document/maxAge","90000");
    setting.setValue("document/cacheTime","60000");
    setting.setValue("document/cacheSize","1000000");
    setting.setValue("document/maxCachedFileSize","65536");
}
int testSettings(){
    QSettings setting("cfg.ini");
    setting.setValue("listener/port","12345");
    setting.sync();
    setting.beginGroup("listener");
    qDebug() << setting.value("port").toString();
    return 0;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSettings setting("cfg.ini");
    setting.setValue("listener/port","12345");
    setting.setValue("listener/minThreads","1");
    setting.setValue("listener/maxThreads","5");
    setting.setValue("listener/cleanupInterval","60000");
    setting.setValue("listener/readTimeout","6000");
    setting.setValue("listener/maxRequestSize","16000");
    setting.setValue("listener/maxMultiPartSize","10000000");
    //initDoc(setting);

    setting.beginGroup("listener");
    MyRequestHandler handler(&a);
    stefanfrings::HttpListener listener(&setting,&handler);
    return a.exec();
}
