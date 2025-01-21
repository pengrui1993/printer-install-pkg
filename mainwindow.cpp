#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSerialPort/QSerialPortInfo>
#include<QtPrintSupport/QPrinterInfo>
#include<QPainter>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
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



}

MainWindow::~MainWindow()
{
    delete ui;
}

void printTest(){
    for(const auto& info:QPrinterInfo::availablePrinters()){
        qDebug() << "info" << info.printerName()
                    ;
        if(info.printerName().startsWith("POS58 Printe")){
            QPrinter printer(info);
            QPainter p;
            if(p.begin(&printer)){

                p.drawText(10,10,"123");
                p.end();
            }


        }
    }
}

void MainWindow::on_pushButton_clicked()
{


}
