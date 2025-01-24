#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSerialPort/QSerialPortInfo>
#include<QtPrintSupport/QPrinterInfo>
#include<QPainter>
#include<QFont>
#include<QLineF>
#include<QDebug>
#include<QRect>
#include<QBrush>
#include<QPen>
#include<QImage>
#include<QPoint>
#include<QByteArray>
#include<QBuffer>
#include<QDir>
#include<QMessageBox>
#include <QTcpSocket>
#include<QAbstractSocket>
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
    QFile prepare = QFile("template/AAAPosTicket.fr3");
    if(!prepare.exists()){
        QDir dir;
        if(!dir.exists("template")){
            dir.mkdir("template");
        }
        QFile file(":/template/AAAPosTicket.fr3");
        const auto res = file.open(QIODevice::ReadOnly);
        if(res){
            prepare.open(QFile::WriteOnly);
            prepare.write(file.readAll());
            prepare.close();
        }
        file.close();
    }

    on_pushButton_clicked();
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
static void testFont(){
    QFont font;
    font.setFamily("微软雅黑"); // 设置字体
    font.setPixelSize(25); // 设置字体像素大小
    font.setPointSize(20); // 设置字体大小
    font.setUnderline(true); // 设置下划线
    font.setStrikeOut(true); // 设置中划线
    font.setOverline(true); // 设置上划线
    font.setItalic(true); // 设置斜体
    font.setBold(true); // 设置粗体

    QPen pen;
    QBrush b;
}

static void testBase64(){
    auto msg = QString("abcd");
    auto ba = QByteArray::fromBase64(msg.toUtf8().toBase64());
    msg = QString::fromUtf8(ba);
    qDebug() << msg;//abcd
}
static bool appdend = false;


static void testPrint(){
    QString base64OnlyImageData = "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uleeNXnOyiMgXjuHdPJwruYJICA1n2IChAAEIFAOAQSkHK5YhQAEIFDzBBCQmk8xAUIAAhAohwACUg5XrEIAAhCoeQIISM2nmAAhAAEIlEMAASmHK1YhAAEI1DwBBKTmU0yAEIAABMohgICUwxWrEIAABGqeAAJS8ykmQAhAAALlEEBAyuGKVQhAAAI1TwABqfkUEyAEIACBcgggIOVwxSoEIACBmieAgNR8igkQAhCAQDkEEJByuGIVAhCAQM0TQEBqPsUECAEIQKAcAghIOVyxCgEIQKDmCSAgNZ9iAoQABCBQDgEEpByuWIUABCBQ8wQQkJpPce0FmOefua29qIkIAoceAQTk0MsJHgkCCAglAoFDgwACcmjkAS8cBMoQkP79+9u6deuaeNHS+w53WQqBmiWAgNRsams3sDIEpCWbZZxVu5khsvZGAAFpbxmvgXjDTX3nzp02e/Zse/311+3333+3M844w+bMmWOXX355gwg//PBDmz9/voU///77b+vbt6/NnTvXJkyYUL8u2Gv82r9/v7X0flib1+769evtpptuso0bN9rAgQPthRdesB07dthtt91mW7dutXPOOccWL15sp5xySg1khhDaGwEEpL1lvAbiDTf2AQMG2Pnnn28XXnihHXnkkbZmzRp76KGH7LnnnrMrrrgii/KDDz6w0aNHZzfwsK5jx462evVqe/jhh+3ll1+28ePHZ+vCTb7xqKpfv34tvp/XbvBz2LBhdscdd9jRRx9t9913n+3evTv7L4hajx49bMGCBdatWzdbtmxZDWSGENobAQSkvWW8BuINN+Znn33WrrvuugbRLFmyxB599NH67zJGjhxp48aNy27gla9FixZlQhOEoO7lGWHltRtsBmELQhdemzdvtt69e9uKFStszJgx2XtbtmzJROann36qgcwQQnsjgIC0t4zXQLwdOnTIforv3Llzg2h+++03O/74423v3r3Z++En+y+//DJ7r/L1888/20knnWR79uwpJCB57QYB+euvv+yII47Iztm3b58dfvjhDd77999/rVOnThZGZrwgUG0EEJBqyxj+Zjfhf/75x4KQVL62b9+ejaJ27dqVvR0EJnzf0L179yYCEr5z+OOPPwoJSF67zXU1ed8jzRCoBgIISDVkCR8bEAg34ZUrV9qoUaMavD9v3rzsy+q67xOGDx9uV155pU2fPr3BumeeecaWLl1qq1atqn8/iFHoXOq6hboLzb2f125eseBJLwq8WgkgINWauXbsd7jhnnzyyXbzzTdn3x+Ecdarr75qL730kr3//vvWp0+fjM4777yTPW1166232tixY7Mv0cN3EgsXLrQ333zTBg8eXE+xZ8+eNnHixExwwlip7lpz7+e1i4C04yJtJ6EjIO0k0bUUZrgxf/rppzZjxozszzBSGjFihN1///314lEXb7jZh85k7dq12WO5Q4cOzdYNGTKkAZLwdNa0adOyL7rDiKzue5SW3s9jFwGppaojluYIICDUBQQgAAEIFCKAgBTCxiYIQAACEEBAqAEIQAACEChEAAEphI1NEIAABCCAgFADEIAABCBQiAACUggbmyAAAQhAAAGhBiAAAQhAoBABBKQQNjZBAAIQgAACQg1AAAIQgEAhAghIIWxsggAEIAABBIQagAAEIACBQgQQkELY2AQBCEAAAggINQABCEAAAoUIICCFsLEJAhCAAAQQEGoAAhCAAAQKEUBACmFjEwQgAAEIICDUAAQgAAEIFCKAgBTCxiYIQAACEEBAqAEIQAACEChEAAEphI1NEIAABCCAgFADEIAABCBQiAACUggbmyAAAQhAAAGhBiAAAQhAoBABBKQQNjZBAAIQgAACQg1AAAIQgEAhAv8HngGtjRjOLWIAAAAASUVORK5CYII=";
    QString base64Image = "data:image/png;base64,"+base64OnlyImageData;
    for(auto& info :QPrinterInfo::availablePrinters() ){
        if(info.printerName().startsWith("POS58 Printe")){
            QPrinter printer(info,QPrinter::HighResolution);
            QPainter p;
            p.setRenderHint(QPainter::Antialiasing);

            if(p.begin(&printer)){
                //p.drawLine(QLineF(0,0,100,100));
                //p.drawText(QRect{0,0,100,40},"门店");
                p.drawText(0,40,"XXXX门店 http://localhost:8080");
                //p.drawRect(QRect(0,0,380,40));
                //p.drawText(QRect{40,0,100,40},"门店");
                //p.drawImage(QPoint(0,0),QImage(":/images/img1.png"));

                p.end();
            }
            if(appdend){
                if(p.begin(&printer)){
                    p.drawImage(QPoint(0,0),QImage(":/images/img1.png"));
                    p.end();
                }
                if(p.begin(&printer)){
                    QPixmap image;
                    image.loadFromData(QByteArray::fromBase64(base64OnlyImageData.toLocal8Bit()));
                    p.drawImage(QPoint(0,0),image.toImage());
                    p.end();
                }
                if(p.begin(&printer)){
                    QPixmap image;
                    QFile f(":/images/img1.png");
                    f.open(QFile::ReadOnly);
                    image.loadFromData(f.readAll());
                    f.close();
                    p.drawImage(QPoint(0,0),image.toImage());
                }
                if(p.begin(&printer)){
                    QFile file(":/images/img1.png");
                    file.open(QFile::ReadOnly);
                    QPixmap image;
                    image.loadFromData(QByteArray::fromBase64(file.readAll().toBase64()));
                    file.close();
                    p.drawImage(QPoint(0,0),image.toImage());
                }
            }
            if(appdend){
                if(p.begin(&printer)){
                    p.drawText(0,20,"abcdefghijklmnopqrstuvwxyz");
                    p.end();
                }
                if(p.begin(&printer)){
                    p.drawText(0,20,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
                    p.end();
                }
                if(p.begin(&printer)){
                    p.drawText(0,20,",.?-_!@#$%^&*()");
                    p.end();
                }
            }

        }

    }



}
void MainWindow::on_pushButton_2_clicked()
{
    testPrint();
}
static bool isPortInUse(int port) {
    QTcpSocket socket;
    bool bounded = socket.bind(QHostAddress::Any,port);

    socket.close();
    return !bounded;
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
        started = true;
        bool isInt;
        auto port = ui->lineEdit->text().toInt(&isInt);
        if(isInt){
            setting.setValue("listener/port",ui->lineEdit->text());
            setting.sync();
            setting.beginGroup("listener");
            if(!isPortInUse(port)){
                handler = new MyRequestHandler(QMainWindow::parent());
                listener = new stefanfrings::HttpListener(&setting,handler);
                if(listener->isListening()){
                    started = true;
                    ui->lineEdit->setDisabled(true);
                    ui->pushButton->setText("关闭");
                }else{
                    started = false;
                    delete handler;
                    delete listener;
                    QMessageBox::information(this,"title","端口已占用1");
                }
            }else{
                 started = false;
                QMessageBox::information(this,"title","端口已占用2");
            }
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


