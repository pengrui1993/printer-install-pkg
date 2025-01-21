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
#include<fr3xml.h>
MyRequestHandler::MyRequestHandler(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

static void doUsePrinter(){
    QPrinterInfo info;
    QMap<QString,QJsonArray> DataSetNameToFieldArray;// A -> [{}]   B ->[{ }]
    QMap<QString,QJsonArray> DataSetNameToDataArray;
    PagePrintDesc desc;

    QPainter p;
    QList<QList<Item>> lists;
    //TODO
    lists<<desc.sortedTitles<<desc.sortedHeaders<<desc.sortedDatas<<desc.sortedFooters;
    QImage img;
    for(auto& sorted:lists){
        QPoint leftTop;
        for(auto item :sorted){
            auto dsn = item.DataSetName;// A B
            bool use = false;
            for (auto field:DataSetNameToFieldArray[dsn]){
                if(!field.isObject()){
                    qDebug()<< "error on title.field";
                    return;
                }
                auto obj = field.toObject();
                auto refField = obj["name"];
                if(refField.isNull()){
                    continue;
                }
                if(item.DataField==refField.toString()){
                    use= true;
                    break;
                }
            }
            QRect place(item.left,item.top,item.width,item.height);

            for(auto data: DataSetNameToDataArray[dsn]){
                if(!data.isObject()){
                    qDebug()<< "error on title.data";
                    return;
                }
                auto obj = data.toObject();
                for(auto& key:obj.keys()){
                    auto val = obj[key];
                    if(item.tagName=="TfrxMasterData"){
                        leftTop.setY(100);
                    }
                    if(key==item.DataField&&val.isString()){
                        p.drawText(place,val.toString());
                    }
                }
            }
        }
    }
    QPrinter printer(info,QPrinter::HighResolution);
    if(p.begin(&printer)){
        p.drawImage(0,0,img);
        p.end();
    }
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
        bool test = true;
        if(test){
            QPrinter printer(info,QPrinter::HighResolution);
            QPainter p;
            if(p.begin(&printer)){
                p.drawText(10,10,"测试");
                p.end();
            }
            QJsonObject obj;
            obj["status"] = "ok";
            obj["data"] = "测试完毕";
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
            return;
        }

        auto templateName = root["ReportName"];//TODO
        QFile file("template/"+templateName.toString());
        if(!file.exists()){
            QJsonObject obj;
            obj["status"] = "error";
            obj["data"] = "文件不存在："+templateName.toString();
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
            return;
        }
        const auto res = file.open(QIODevice::ReadOnly);
        if(!res){
            QJsonObject obj;
            obj["status"] = "ok";
            obj["data"] = "error on read open file:"+file.fileName();
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
            return;
        }
        auto parseXmlFailPost = [&](){
            file.close();
            QJsonObject obj;
            obj["status"] = "ok";
            obj["data"] = "error on  parse xml:"+file.fileName();
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
        };
        PagePrintDesc desc;
        try{
            QXmlStreamReader xmlReader(&file);
            if(!readFr3(xmlReader,desc)){
                qDebug()<<"";
                parseXmlFailPost();
                return;
            }
        }catch(...){
            parseXmlFailPost();
            return;
        }
        QMap<QString,QJsonArray> DataSetNameToFieldArray;
        QMap<QString,QJsonArray> DataSetNameToDataArray;
        try{

            for(auto itr = root.begin();itr!=root.end();++itr){
                auto key = itr.key();
                if(key.endsWith("Field")){
                    auto DataSetName = key.split("Field")[0];
                    auto val = itr.value();
                    auto fields = val.toArray();
                    DataSetNameToFieldArray[DataSetName] = fields;
                }
                if(key.endsWith("Data")){
                    auto DataSetName = key.split("Data")[0];
                    DataSetNameToDataArray[DataSetName]=itr.value().toArray();
                }
            }
        }catch(...){
            qDebug()<<"parse json error" << root;
            QJsonObject obj;
            obj["status"] = "ok";
            obj["data"] = "error on  parse json";
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
            return;
        }
        try{
            doUsePrinter();//TODO
        }catch(...){
            qDebug()<<"call printer error" << root;
            QJsonObject obj;
            obj["status"] = "ok";
            obj["data"] = "error on call printer";
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
            return;
        }
        QJsonObject obj;
        obj["status"] = "ok";
        obj["data"] = "printer done";
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
