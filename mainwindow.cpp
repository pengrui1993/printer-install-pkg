#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSerialPort/QSerialPortInfo>
#include<QtPrintSupport/QPrinterInfo>
#include<QPainter>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),setting("cfg.ini")
    ,handler(nullptr),listener(nullptr)
{

    ui->setupUi(this);
    setting.beginGroup("listener");
    const auto initPort = setting.value("port");
    setting.endGroup();
    if(initPort.isNull()||""==initPort.toString().trimmed()){
        setting.setValue("listener/port","12345");
    }
    setting.setValue("listener/minThreads","1");
    setting.setValue("listener/maxThreads","5");
    setting.setValue("listener/cleanupInterval","60000");
    setting.setValue("listener/readTimeout","6000");
    setting.setValue("listener/maxRequestSize","16000");
    setting.setValue("listener/maxMultiPartSize","10000000");
    setting.sync();
    //initDoc(setting);


}

MainWindow::~MainWindow()
{
    delete ui;

    if(listener){
        listener->close();
        delete listener;
    }
    if(handler)delete handler;
}
static void testPrint(){

    for(auto& info :QPrinterInfo::availablePrinters() ){
        if(info.printerName().startsWith("POS58 Printe")){
             QPrinter printer(info);
            QPainter p;
            if(p.begin(&printer)){
                p.drawText(10,10,"门店");
                p.end();
            }
        }

    }



}

void MainWindow::on_pushButton_clicked()
{
    for(const auto& info:QSerialPortInfo::QSerialPortInfo::availablePorts()){
        qDebug()<< "port name:" << info.portName()
                <<"description:" << info.description()
                << "manufacturer:" << info.manufacturer()
                << "serial number:" << info.serialNumber()
                << "system location:" << info.systemLocation()
                << "vendor Id:" << info.vendorIdentifier()
                << "product Id:" << info.productIdentifier()
                   ;
    }
    if(!started){
        bool isInt;
        ui->lineEdit->text().toInt(&isInt);
        if(isInt){

            started = true;
            ui->lineEdit->setDisabled(true);
            ui->pushButton->setText("关闭");
            setting.setValue("listener/port",ui->lineEdit->text());
            setting.sync();
            setting.beginGroup("listener");
            handler = new MyRequestHandler(QMainWindow::parent());
            listener = new stefanfrings::HttpListener(&setting,handler);

        }
    }else if(started){
        started = false;
        ui->lineEdit->setDisabled(false);
        ui->pushButton->setText("启动");
        listener->close();
        delete listener;
        delete handler;
    }
}
static void initDoc(QSettings& setting){
    setting.setValue("document/path","document");
    setting.setValue("document/encoding","UTF-8");
    setting.setValue("document/maxAge","90000");
    setting.setValue("document/cacheTime","60000");
    setting.setValue("document/cacheSize","1000000");
    setting.setValue("document/maxCachedFileSize","65536");
}
static int testSettings(){
    QSettings setting("cfg.ini");
    setting.setValue("listener/port","12345");
    setting.sync();
    setting.beginGroup("listener");
    qDebug() << setting.value("port").toString();
    return 0;
}
