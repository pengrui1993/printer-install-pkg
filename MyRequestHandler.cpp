#include "MyRequestHandler.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include<QtSerialPort/QSerialPortInfo>
#include<QtPrintSupport/QPrinterInfo>
#include<QPainter>
#include<algorithm>
MyRequestHandler::MyRequestHandler(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

static void handlePrinterRequest(MyRequestHandler& handler
                                 ,QJsonObject& root
                                 ,HttpResponse&rsp){


//    rsp.setHeader("Content-Type","application/json;charset=utf-8");
    rsp.setHeader("Content-Type","text/plain;charset=utf-8");
    rsp.setHeader("Access-Control-Allow-Origin","*");
    rsp.setHeader("Access-Control-Allow-Headers","*");
    rsp.setHeader("Access-Control-Allow-Methods","*");
    //
    rsp.setStatus(200);
    if(root["method"].isNull()){
        QJsonObject obj;
        obj["status"] = "error";
        obj["data"] = "method 不能为 null";
        QJsonDocument doc(obj);
        rsp.write(doc.toJson(),true);
        return;
    }

    const auto method = root["method"].toString();
    if(method=="getprinterlist"){
        //{status:'ok',data:[{name:''},{name:''}]}
        QJsonObject obj;
        auto data = QJsonArray();
        for(const auto& info:QPrinterInfo::availablePrinters()){
            auto item = QJsonObject();
            item["name"] = info.printerName();
            data << item;
        }
        obj["status"] = "ok";
        obj["data"] = data;
        QJsonDocument doc(obj);
        const auto bytes = doc.toJson(QJsonDocument::Compact);

        rsp.write( bytes,true);
    }else if(method=="printreport"){
        qDebug() << root;

        auto printerName = root["PrinterName"];//
        if(printerName.isNull()){
            QJsonObject obj;
            obj["status"] = "error";
            obj["data"] = "PrinterName 不能为 null";
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
            return;
        }

        auto infos = QPrinterInfo::availablePrinters();
        auto itr = std::find_if(infos.begin(),infos.end(),[=](QPrinterInfo& info){
            return info.printerName()==printerName.toString();
        });
        if(itr==infos.end()){
            QJsonObject obj;
            obj["status"] = "error";
            obj["data"] = "PrinterName 打印设备"+printerName.toString();
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
            return;
        }
        qDebug()<<"打印设备名：" <<printerName;

        auto& info = *itr;
        QPrinter printer(info,QPrinter::HighResolution);
        QPainter p;
        if(p.begin(&printer)){
            p.drawText(10,10,"测试");
            p.end();
        }
        auto templateName = root["ReportName"];//TODO
        QJsonObject obj;
        obj["status"] = "ok";
        obj["data"] = "测试完毕";
        QJsonDocument doc(obj);
        rsp.write(doc.toJson(),true);
    }else{
        //{"status":"error","taskid":"","data":"该method=不支持"}
        QJsonObject obj;
        obj["status"] = "error";
        obj["data"] = "该method=不支持";
        QJsonDocument doc(obj);
        rsp.write(doc.toJson(),true);
    }



}
void MyRequestHandler::service(HttpRequest &request, HttpResponse &response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());
    if (path==("/") ) {
        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(request.printerQuery, &parseError);
        if (parseError.error == QJsonParseError::NoError) {
           auto jsonObj = jsonDoc.object();
           handlePrinterRequest(*this,jsonObj,response);
        }
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong no such document.");
    }

    qDebug("RequestMapper: finished request");
}
