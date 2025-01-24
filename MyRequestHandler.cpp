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
#include<QLabel>
#include<QSharedPointer>
#include<QRegExp>
#include<QRegularExpressionMatch>
#include<QRegularExpression>
#include<QDateTime>
#include<QDate>
MyRequestHandler::MyRequestHandler(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}
static QSharedPointer<QLabel> label;


static void doUsingPrinter(QPrinterInfo& info
                         , QMap<QString,QJsonArray>& DataSetNameToFieldArray
                         ,QMap<QString,QJsonArray>& DataSetNameToDataArray
                         ,XmlNode& desc
                         ){

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
    bool onOff = true;
    bool printTitle = true&&onOff,printHeader = true&&onOff,printData=true&&onOff,printFooter=true&&onOff;
    int imgWidth = 600,imgHeight = 600;
    auto pageData = findFirstChildNodeByTag(desc,"TfrxDataPage");
    if(pageData&&!pageData->attris["Width"].isNull()){
        bool cond;
        auto tmp = pageData->attris["Width"].toDouble(&cond);
        if(cond)imgWidth = (int)tmp;
    }
    double tmpHeight = 0;
    for(auto* p:memo0){
        auto dsn = p->attris["DataSetName"];
        auto nameField = p->attris["DataField"];
        auto fh = p->attris["Height"];
        auto fie = DataSetNameToFieldArray[dsn];
        if(!dsn.isNull()&&!fh.isNull()&&!nameField.isNull()&&!fie.isEmpty()){
            auto itr = std::find_if(fie.begin(),fie.end(),[=](QJsonValue ele){
                if(!ele.isObject())return false;
                auto obj = ele.toObject();
                return obj.contains("name") && obj["name"].toString()==nameField
                        ;
            });
            if(itr==fie.end())continue;
            bool cond;
            auto val = fh.toDouble(&cond);
            if(cond){
                tmpHeight+=val;
            }
        }
    }
    if(0!=tmpHeight){
        imgHeight = tmpHeight*2;
    }
    QImage titleImage(imgWidth,imgHeight,QImage::Format_Grayscale16);
    titleImage.fill(Qt::white); // 使用白色填充背景
    QPainter titlePainter(&titleImage);
    auto f = titlePainter.font();
    f.setBold(true);
    f.setPointSize(18);
    f.setPixelSize(18);
    titlePainter.setFont(f);
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
        for(auto dataJson:dat){
            if(!dataJson.isObject())continue;
            auto obj = dataJson.toObject();
            auto dataHasField = obj.contains(nameField);
            if(require&&!dataHasField){
                qDebug()<<"field required but data no containes,"<<nameField;
                return;
            }
            if(!dataHasField)continue;
            auto top = p->attris["Top"].toDouble();
            auto width = imgWidth;
            auto height = p->attris["Height"].toDouble();
            auto info = obj[nameField].toString();
            titlePainter.drawText(QRect(0,top,width ,height),info);
        }
    }
    titlePainter.end();
    if(printTitle){
        QPrinter printer(info,QPrinter::HighResolution);
        QPainter headerPrinterPainter;
        if(headerPrinterPainter.begin(&printer)){
            headerPrinterPainter.drawImage(0,20,titleImage);
            headerPrinterPainter.end();
        }
    }

    auto headerImageHeight = imgHeight;
    //print header
    QImage headerImage(imgWidth,headerImageHeight,QImage::Format_Grayscale16);
    headerImage.fill(Qt::white); // 使用白色填充背景
    QPainter headerPainter(&headerImage);
    f = headerPainter.font();
    f.setBold(true);
    f.setPointSize(18);
    f.setPixelSize(18);
    headerPainter.setFont(f);
    for(auto* p:findChildrenByTag(*header,"TfrxMemoView")){
        auto text = p->attris["Text"];//商品名称
        auto top = p->attris["Top"].toDouble();
        auto left = p->attris["Left"].toDouble();
        auto width = imgWidth;
        auto height = p->attris["Height"].toDouble();
        headerPainter.drawText(QRect(left,top,width,height),text);
    }
    headerPainter.end();


    if(printHeader){
        QPrinter printer(info,QPrinter::HighResolution);
        if(headerPainter.begin(&printer)){
            headerPainter.drawImage(0,0,headerImage);
            headerPainter.end();
        }
    }
    //print data
    if(data->attris.contains("DataSetName")){
        auto dsn = data->attris["DataSetName"];
        if(!dsn.isNull()&&DataSetNames.contains(dsn)&&DataSetNameToFieldArray.contains(dsn)){
            auto dataImageHeight = imgHeight;
            auto first = findFirstChildNodeByTag(*data,"TfrxMemoView");
            if(!first){
                qDebug()<< "invalid template ,cannot get TfrxMasterData.TfrxMemoView[0]";
                throw 4;
            }
            bool cond;
            auto heightPerLine = first->attris["Height"].toDouble(&cond);
            if(!cond){
                qDebug()<< "invalid template ,cannot get TfrxMemoView.Height";
                throw 5;
            }
            auto dat = DataSetNameToDataArray[dsn];
            auto fie = DataSetNameToFieldArray[dsn];
            QPrinter printer(info,QPrinter::HighResolution);
            dataImageHeight = heightPerLine*dat.size()*2;
            QImage img(imgWidth,dataImageHeight,QImage::Format_Grayscale16);
            img.fill(Qt::white); // 使用白色填充背景
            QPainter painter(&img);
            f = painter.font();
            f.setBold(true);
            f.setPointSize(18);
            f.setPixelSize(18);
            painter.setFont(f);
            auto yOffset = 0;
            for(auto dataJson:dat){
                if(!dataJson.isObject())continue;
                auto obj = dataJson.toObject();
                for(auto key:obj.keys()){
                    for(auto* p:findChildrenByTag(*data,"TfrxMemoView")){
                        auto fdsn = p->attris["DataSetName"];
                        if(!fdsn.isNull()&&fdsn!=dsn)continue;
                        auto nameField = p->attris["DataField"];
                        if(nameField.isNull()||key!=nameField)continue;
                        auto itr = std::find_if(fie.begin(),fie.end(),[=](QJsonValue ele){
                            if(!ele.isObject())return false;
                            auto obj = ele.toObject();
                            return obj.contains("name")&&obj["name"].toString()==nameField;
                        });
                        if(itr==fie.end())continue;
                        auto width = imgWidth;//p->attris["Width"].toDouble()
                        auto content = obj[nameField].toString();
                        painter.drawText(
                                    QRect(
                                        p->attris["Left"].toDouble()
                                        ,p->attris["Top"].toDouble()+yOffset
                                        ,width
                                        ,p->attris["Height"].toDouble()
                                    )
                                ,content);
                    }
                }

                yOffset+=heightPerLine;

            }
            painter.end();
            if(printData){
                if(painter.begin(&printer)){
                    painter.drawImage(0,0,img);
                    painter.end();
                }
            }

        }
    }

    //print footer
    auto dataImageHeight = 500;
    QImage footerImg(imgWidth,dataImageHeight,QImage::Format_Grayscale16);
    footerImg.fill(Qt::white); // 使用白色填充背景
    QPainter footerPainter(&footerImg);
    f = footerPainter.font();
    f.setBold(true);
    f.setPointSize(18);
    f.setPixelSize(18);
    footerPainter.setFont(f);
    for(auto* p:findChildrenByTag(*footer,"TfrxMemoView")){    
        auto nameAttr =  p->attris["Name"];
        enum class ViewType{
            Memo,FormatDataTime
        };
        auto type = ViewType::Memo;
        bool require = false;
        QString nameField;
        QString text;
        if(nameAttr.startsWith("Memo")){
            auto dsn = p->attris["DataSetName"];
            if(dsn.isNull())continue;
            if(!DataSetNames.contains(dsn))continue;
            auto arr = DataSetNameToFieldArray[dsn];
            if(arr.isEmpty())continue;
            auto dat = DataSetNameToDataArray[dsn];
            if(dat.isEmpty())continue;
            auto textAttr = p->attris["Text"];
            auto split = textAttr.split("\"");
            auto viewText = split[1];//已优惠金额：[A.&#34;yhje&#34;] //&#34; 是 " 双引号
            if(viewText.isNull())continue;//应收金额
            auto itr = std::find_if(arr.begin(),arr.end(),[=](QJsonValue ele){
                if(!ele.isObject())return false;
                auto obj = ele.toObject();
                return obj.contains("name")&&viewText==obj["name"].toString();
                        ;
            });
            if(itr==arr.end())continue;
            auto fieldDesc = (*itr).toObject();
            require = fieldDesc.contains("required")&&fieldDesc["required"].isBool()&&fieldDesc["required"].toBool();
            text = p->attris["Text"];//已优惠金额：[A.&#34;yhje&#34;]
            nameField = viewText;
        }else if(nameAttr=="FormatDateTime"){
            type = ViewType::FormatDataTime;
            text = p->attris["Text"];//打单日期：[FormatDateTime('yyyy-mm-dd hh:mm:ss',now)]
        }else{
            qDebug()<<"no impl name:"<<nameAttr;
        }

        auto left = p->attris["Left"].toDouble();
        auto top = p->attris["Top"].toDouble();
        auto width = imgWidth;//p->attris["Width"].toDouble()
        auto height = p->attris["Height"].toDouble();
        switch(type){
        case ViewType::Memo:{
            auto dsn = p->attris["DataSetName"];
            auto dat = DataSetNameToDataArray[dsn];
            for(auto dataJson:dat){
                if(!dataJson.isObject())continue;
                auto obj = dataJson.toObject();
                auto dataHasField = obj.contains(nameField);
                if(require&&!dataHasField){
                    qDebug()<<"field required but data no containes,"<<nameField;
                    continue;
                }
                if(!dataHasField)continue;
                QString tpl = "["+dsn+".\""+nameField+"\"]";
                QString holerMessage = text.replace(tpl,obj[nameField].toString());
                footerPainter.drawText(QRect(left,top,width,height),holerMessage);

            }

        }break;
        case ViewType::FormatDataTime:{
            QRegularExpression  regExp("\\[FormatDateTime\\('([ydhms\\- :]+)',(\\S+)\\)\\]");
            auto m = regExp.globalMatch(text);//打单日期：[FormatDateTime('yyyy-mm-dd hh:mm:ss',now)]
            QString pattern;
            QString desc;
            if(m.hasNext()){
                auto matcher = m.next();
                pattern = matcher.captured(1);
                desc = matcher.captured(2);
            }
            QString holerMessage = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
            if("now"==desc){
                QString filledPattern = "[FormatDateTime('$1',$2)]";
                QString time;
                if(pattern=="yyyy-mm-dd hh:mm:ss"){
                    time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                }else if(pattern=="yyyy-mm-dd"){
                    time = QDate::currentDate().toString("yyyy-MM-dd");
                }else{
                    time = QDateTime::currentDateTime().toString(pattern);
                }
                auto real = filledPattern.replace("$1",pattern).replace("$2",desc);
                holerMessage = text.replace(real,time);
            }//yyyy-mm-dd hh:mm:ss
            footerPainter.drawText(QRect(left,top,width,height),holerMessage);
        }break;
        }

    }
    footerPainter.end();

    if(printFooter){
        QPrinter footerPrinter(info,QPrinter::HighResolution);
        if(footerPainter.begin(&footerPrinter)){
            footerPainter.drawImage(0,0,footerImg);
            footerPainter.end();
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
    }else if(method=="printreport-base64-img"){
        auto printerName = root["PrinterName"];//
        auto base64Image = root["base64Image"];//
        if(printerName.isNull()
                ||base64Image.isNull()
                ||!base64Image.isString()
                ||!base64Image.toString().startsWith("data:")){
            QJsonObject obj;
            obj["status"] = "error";
            obj["data"] = "PrinterName|base64Image invalid ";
            QJsonDocument doc(obj);
            rsp.write(doc.toJson(),true);
            return;
        }

        qDebug()<< base64Image;
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
        auto rowBase64 = base64Image.toString().split(";base64,")[1];
        if(false){
            QPixmap image;
            image.loadFromData(QByteArray::fromBase64(rowBase64.toLocal8Bit()));
            if(!label){
                label = QSharedPointer<QLabel>(new QLabel);
            }
            if(label){
                QImage img = image.toImage();
//                img.setDotsPerMeterX(880);
//                img.setDotsPerMeterX(880);
                label->setPixmap(QPixmap::fromImage(img));
                label->show();
            }
            return;
        }
        QPrinter printer(info,QPrinter::HighResolution);
        QPainter p;
        p.setRenderHint(QPainter::Antialiasing);
        if(p.begin(&printer)){
            QPixmap image;
            image.loadFromData(QByteArray::fromBase64(rowBase64.toLocal8Bit()));
            p.drawImage(QPoint(0,0),image.toImage());
            p.end();
        }

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
            doUsingPrinter(info,DataSetNameToFieldArray,DataSetNameToDataArray,desc);
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
