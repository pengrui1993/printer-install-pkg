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

static void doUsePrinter(QPrinterInfo& info
                         , QMap<QString,QJsonArray>& DataSetNameToFieldArray
                         ,QMap<QString,QJsonArray>& DataSetNameToDataArray
                         ,XmlNode& desc
                         ){


    //QMap<QString,QJsonArray> DataSetNameToFieldArray;// A -> [{}]   B ->[{ }]
    //QMap<QString,QJsonArray> DataSetNameToDataArray;
    //XmlNode desc;


    auto reportPage = findFirstChildNodeByTag(desc,"TfrxReportPage");
    if(!reportPage){
        qDebug()<<"no found TfrxReportPage tag";
        throw 1;
    }
    auto datasets = findFirstChildNodeByTag(desc,"Datasets");
    auto title = findFirstChildNodeByTag(*reportPage,"TfrxReportTitle");
    auto data = findFirstChildNodeByTag(*reportPage,"TfrxMasterData");
    auto header = findFirstChildNodeByTag(*reportPage,"TfrxHeader");
    auto footer = findFirstChildNodeByTag(*reportPage,"TfrxFooter");
    if(!title||!data||!header||!footer||!datasets){
        qDebug()<<"no found Datasets|TfrxReportTitle|TfrxMasterData|TfrxHeader|TfrxFooter tag";
        throw 2;
    }

    auto items = findChildrenByTag(*datasets,"item");
    QSet<QString> DataSetNames;
    for(auto& item:items){
        if(item){
            auto val = item->attris["DataSetName"];
            if(!val.isEmpty()){
                DataSetNames<<val;
            }
        }
    }

    auto memo0 = findChildrenByTag(*title,"TfrxMemoView");
    try{
        std::sort(memo0.begin(),memo0.end(),[](XmlNode* l,XmlNode* r){
            if(!l->attris.contains("Top")
                    ||!r->attris.contains("Top"))
                throw 1;
            bool f,g;
            auto ln = l->attris["Top"].toDouble(&f);
            auto rn = r->attris["Top"].toDouble(&g);
            if(!f||!g){
                throw 2;
            }
            return ln < rn;
        });
    }catch(...){
        qDebug()<<"error on sort by top attribute";
        throw 3;
    }
    QPrinter printer(info,QPrinter::HighResolution);
    //print title
    for(auto* p:memo0){
        auto dsn = p->attris["DataSetName"];
        if(dsn.isNull())continue;
        if(!DataSetNames.contains(dsn))continue;
        auto arr = DataSetNameToFieldArray[dsn];
        if(arr.isEmpty())continue;
        auto dat = DataSetNameToDataArray[dsn];
        if(dat.isEmpty())continue;
        //DataField     name
        auto nameField = p->attris["DataField"];
        if(nameField.isNull())continue;
        auto itr = std::find_if(arr.begin(),arr.end(),[=](QJsonValue ele){
            if(!ele.isObject())return false;
            auto obj = ele.toObject();
            return obj.contains("name") && obj["name"].toString()==nameField;
        });
        if(itr==arr.end())continue;
        auto fieldDesc = (*itr).toObject();
        auto require = fieldDesc.contains("required")&&fieldDesc["required"].isBool()&&fieldDesc["required"].toBool();

        QPainter painter;
        for(auto dataJson:dat){
            if(!dataJson.isObject())continue;
            auto obj = dataJson.toObject();
            auto dataHasField = obj.contains(nameField);
            if(require&&!dataHasField){
                qDebug()<<"field required but data no containes,"<<nameField;
                return;
            }
            if(!dataHasField)continue;
            if(painter.begin(&printer)){
                painter.drawText(
                            QRect(p->attris["Top"].toDouble()
                                ,p->attris["Left"].toDouble()
                                ,p->attris["Width"].toDouble()
                                ,p->attris["Height"].toDouble()
                            )
                        ,obj[nameField].toString());
                //painter.drawImage(0,0,img);
                painter.end();
            }
        }
    }
    QImage headerImage;    //print header //TODO
    QPainter painter(&headerImage);
    for(auto* p:findChildrenByTag(*header,"TfrxMemoView")){
        QPainter painter(&headerImage);
        auto text = p->attris["Text"];//商品名称
        painter.drawText(
                    QRect(
                        p->attris["Top"].toDouble()
                        ,p->attris["Left"].toDouble()
                        ,p->attris["Width"].toDouble()
                        ,p->attris["Height"].toDouble()
                    )
                ,text);
    }
    if(painter.begin(&printer)){
        painter.drawImage(0,0,headerImage);
        painter.end();
    }

    //print data
    if(data->attris.contains("DataSetName")){//TODO
        auto dsn = data->attris["DataSetName"];
        if(!dsn.isNull()&&DataSetNames.contains(dsn)&&DataSetNameToFieldArray.contains(dsn)){
            auto dat = DataSetNameToDataArray[dsn];
            auto fie = DataSetNameToFieldArray[dsn];
            for(auto dataJson:dat){
                if(!dataJson.isObject())continue;
                QImage img;
                QPainter painter(&img);
                for(auto* p:findChildrenByTag(*data,"TfrxMemoView")){
                    auto fdsn = p->attris["DataSetName"];
                    if(!fdsn.isNull()&&fdsn==dsn)continue;
                    auto nameField = p->attris["DataField"];
                    if(nameField.isNull())continue;
                    auto itr = std::find_if(fie.begin(),fie.end(),[=](QJsonValue ele){
                        if(!ele.isObject())return false;
                        auto obj = ele.toObject();
                        return obj.contains("name")&&obj["name"].toString()==nameField;
                    });
                    if(itr==fie.end())continue;
                    auto fieldDesc = (*itr).toObject();
                    auto require = fieldDesc.contains("required")&&fieldDesc["required"].isBool()&&fieldDesc["required"].toBool();
                    auto obj = dataJson.toObject();
                    auto dataHasField = obj.contains(nameField);
                    if(require&&!dataHasField){
                        qDebug()<<"field required but data no containes,"<<nameField;
                        continue;
                    }
                    painter.drawText(
                                QRect(
                                    p->attris["Top"].toDouble()
                                    ,p->attris["Left"].toDouble()
                                    ,p->attris["Width"].toDouble()
                                    ,p->attris["Height"].toDouble()
                                )
                            ,obj[nameField].toString());
                }
                if(painter.begin(&printer)){//TODO
                    painter.drawImage(0,0,img);
                    painter.end();
                }
            }

        }

    }

    //print footer
    for(auto* p:findChildrenByTag(*footer,"TfrxMemoView")){
        auto dsn = p->attris["DataSetName"];
        if(dsn.isNull())continue;
        if(!DataSetNames.contains(dsn))continue;
        auto arr = DataSetNameToFieldArray[dsn];
        if(arr.isEmpty())continue;
        auto dat = DataSetNameToDataArray[dsn];
        if(dat.isEmpty())continue;
        auto nameField = p->attris["DataField"];
        if(nameField.isNull())continue;
        auto itr = std::find_if(arr.begin(),arr.end(),[=](QJsonValue ele){
            if(!ele.isObject())return false;
            auto obj = ele.toObject();
            return obj.contains("name")
                    &&obj["name"].toString()==nameField
                    ;
        });
        if(itr==arr.end())continue;
        auto fieldDesc = (*itr).toObject();
        auto require = fieldDesc.contains("required")&&fieldDesc["required"].isBool()&&fieldDesc["required"].toBool();
        QPainter painter;
        auto text = p->attris["Text"];//已优惠金额：[A.&#34;yhje&#34;]
        for(auto dataJson:dat){
            if(!dataJson.isObject())continue;
            auto obj = dataJson.toObject();
            auto dataHasField = obj.contains(nameField);
            if(require&&!dataHasField){
                qDebug()<<"field required but data no containes,"<<nameField;
                continue;
            }
            QString tpl = "["+dsn+".&#34;"+nameField+"&#34;]";
            QString holerMessage = text.replace(tpl,obj[nameField].toString());
            if(!dataHasField)continue;
            if(painter.begin(&printer)){
                painter.drawText(
                            QRect(
                                p->attris["Top"].toDouble()
                                ,p->attris["Left"].toDouble()
                                ,p->attris["Width"].toDouble()
                                ,p->attris["Height"].toDouble()
                            )
                        ,holerMessage);

                painter.end();
            }
        }
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
        bool test = false;
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

        auto templateName = root["ReportName"];
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
        XmlNode desc;
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
        file.close();
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
            doUsePrinter(info,DataSetNameToFieldArray,DataSetNameToDataArray,desc);
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
