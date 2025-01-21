#include<fr3xml.h>
namespace {

QDebug &operator<<(QDebug& stream,const Dataset& t) {
    stream<< t.name <<" "<<t.dataSet;
    return stream;
}
QDebug &operator<<(QDebug& stream,const Item& t) {
    stream<< t.tagName <<" "<<t.DataSetName <<'\n'
         << t.DataField <<" "<<t.fontName<<'\n'
        << t.fontColor <<" "<<t.fontHeight<<'\n'
        << t.left <<" "<<t.top<<'\n'
        << t.width <<" "<<t.height<<'\n'
             ;
    return stream;
}
bool testing = true;
}

static bool testPainter(){

    return testing;
}

static bool xmlTest(){

    QFile file(":/template/AAAPosTicket.fr3");
    const auto res = file.open(QIODevice::ReadOnly);
    if(!res){
        qDebug() << "open file error:" << file.fileName();
        return testing;
    }
    QXmlStreamReader xml(&file);
    PagePrintDesc desc;
    qDebug() << "start...";
    bool ok = readFr3(xml,desc);

    qDebug()<<desc.sortedTitles;
    qDebug()<<desc.sortedHeaders;
    qDebug()<<desc.sortedDatas;
    qDebug()<<desc.sortedFooters;
    return testing;
}
bool readFr3(QXmlStreamReader& xml,PagePrintDesc&desc){
    int deep;
    bool inDatasets = false;
    bool inTitle = false;
    bool inHeader = false;
    bool inMasterData = false;
    bool inFooter = false;
    QList<Dataset>& datasets = desc.datasets;
    QString preTagName;
    while(!xml.atEnd()){
        auto item = xml.readNext();
        switch(item){
        case QXmlStreamReader::NoToken:{

        }break;
        case QXmlStreamReader::Invalid:{

        }break;
        case QXmlStreamReader::StartDocument:{

        }break;
        case QXmlStreamReader::EndDocument:{

        }break;
        case QXmlStreamReader::StartElement:{

            auto eleName = xml.name();
            deep++;
            qDebug() << "TAG:" << eleName;

            if(eleName=="Datasets"){
                inDatasets = true;
                preTagName = eleName.toString();
            }else if(eleName=="TfrxMasterData"){
                preTagName = eleName.toString();
                inMasterData = true;
            }else if(eleName=="TfrxReportTitle"){
                preTagName = eleName.toString();
                inTitle = true;
            }else if(eleName=="TfrxHeader"){
                preTagName = eleName.toString();
                inHeader = true;
            }else if(eleName=="TfrxFooter"){
                preTagName = eleName.toString();
                inFooter = true;
            }

            if(inDatasets && eleName=="item"){
                auto attrs = xml.attributes();
                Dataset ds;
                for(const auto& attr:attrs){
                    const auto key = attr.name();
                    const auto value = attr.value().toString();
                    if(key=="DataSetName"){ //A
                        ds.name = value;
                    }else if(key =="DataSet"){//BfrxDBDataset
                        ds.dataSet = value;
                    }
                }
                datasets<<ds;
            }
            if(eleName=="TfrxMemoView"){
                auto attrs = xml.attributes();
                Item item;
                item.tagName = preTagName;
                for(const auto& attr:attrs){
                    const auto key = attr.name();
                    const auto value = attr.value().toString();
                    if(key=="DataSetName"){ //A
                        item.DataSetName = value;
                    }else if(key =="DataField"){//shuliang|je|shangpname
                        item.DataField =value;
                    }else if(key =="Font.Color"){
                        item.fontColor =value.toInt();
                    }else if(key =="Font.Height"){
                        item.fontHeight =value.toInt();
                    }else if(key =="Font.Name"){
                        item.fontName =value.toInt();
                    }else if(key =="Top"){
                        item.top = value.toDouble();
                    }else if(key =="Left"){
                        item.left = value.toDouble();
                    }else if(key =="Width"){
                        item.width = value.toDouble();
                    }else if(key =="Height"){
                        item.height = value.toDouble();
                    }
                }
                if(inTitle ){
                    desc.sortedTitles<<item;
                }else if(inHeader){
                    desc.sortedHeaders<<item;
                }else if(inMasterData){
                    desc.sortedDatas<<item;
                }else if(inFooter){
                    desc.sortedFooters<<item;
                }
            }
        }break;
        case QXmlStreamReader::EndElement:{
            auto eleName = xml.name().toString();
            deep--;
            qDebug();
            if(eleName=="Datasets"){
                inDatasets = false;
            }else if(eleName=="TfrxMasterData"){
                inMasterData = false;
            }else if(eleName=="TfrxReportTitle"){
                inTitle = false;
            }else if(eleName=="TfrxHeader"){
                inHeader = false;
            }else if(eleName=="TfrxFooter"){
                inFooter = false;
            }

        }break;
        case QXmlStreamReader::Characters:{

        }break;
        case QXmlStreamReader::Comment:{

        }break;
        case QXmlStreamReader::DTD:{

        }break;
        case QXmlStreamReader::EntityReference:{

        }break;
        case QXmlStreamReader::ProcessingInstruction:{

        }break;
        default:{
            qDebug() << "unknown";
        }
        }

    }
#define ITEMS_SORT_XML(list)\
        std::sort(list.begin(),list.end(),[](Item&left,Item&right){ \
    const auto diff = left.top-right.top; \
    return diff==0?(left.left-right.left):diff; \
}) \

    ITEMS_SORT_XML(desc.sortedDatas);
    ITEMS_SORT_XML(desc.sortedTitles);
    ITEMS_SORT_XML(desc.sortedFooters);
    ITEMS_SORT_XML(desc.sortedHeaders);
#undef ITEMS_SORT_XML
    if(xml.hasError()){
        return false;
    }
    return true;
}

bool testEtc(){

    return testPainter();
}

