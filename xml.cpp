#include<fr3xml.h>
#include<QSharedPointer>
#include<QStack>
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

static bool xmlTest1(){

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
static void testXmlNode(XmlNode& root){

    auto* p = findFirstChildNodeByTag(root,"TfrxReportPage");
    auto* p1 = findFirstChildNodeByTag(*p,"TfrxReportTitle");
    auto* p3 = findChildNodeByTagAndIndex(*p1,"TfrxMemoView",1);
    qDebug()<< p3->attris["Name"];
}
static bool xmlTest(){
    QFile file(":/template/AAAPosTicket.fr3");
    const auto res = file.open(QIODevice::ReadOnly);
    if(!res){
        qDebug() << "open file error:" << file.fileName();
        return testing;
    }
    QXmlStreamReader xml(&file);
    XmlNode root;
    if(!readFr3(xml,root)){
          qDebug() << "read xml error:" << file.fileName();
        return testing;
    }
    testXmlNode(root);
    return testing;
}
bool readFr3(QXmlStreamReader& xml,XmlNode&root){
    int deep;
    QStack<XmlNode*> stack;
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

                deep++;
                XmlNode* cur;
                if(!stack.isEmpty()){
                    auto created = QSharedPointer<XmlNode>(new XmlNode);
                    stack.top()->children<<created;
                    cur = created.data();
                }else{
                    cur = &root;
                }
                auto attrs = xml.attributes();
                for(const auto& attr:attrs){
                    const auto key = attr.name().toString();
                    const auto value = attr.value().toString();
                    cur->attris[key]=value;
                }
                cur->tagName = xml.name().toString();
                cur->text = xml.text().toString();
                stack.push(cur);
            }break;
            case QXmlStreamReader::EndElement:{
                deep--;
                stack.pop();

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
    if(xml.hasError()){
        return false;
    }
    return true;

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
    XmlNode root;
    XmlNode* parent=nullptr;
    while(!xml.atEnd()){
        auto item = xml.readNext();
        switch(item){
        case QXmlStreamReader::NoToken:{

        }break;
        case QXmlStreamReader::Invalid:{

        }break;
        case QXmlStreamReader::StartDocument:{
                qDebug()<< "StartDoc:"<<xml.name();
        }break;
        case QXmlStreamReader::EndDocument:{

        }break;
        case QXmlStreamReader::StartElement:{
            deep++;
            XmlNode* cur;
            if(!parent){
                cur = &root;
            }else{
                auto created = QSharedPointer<XmlNode>(new XmlNode);
                parent->children<<created;
                cur = created.data();
            }
            auto attrs = xml.attributes();
            for(const auto& attr:attrs){
                const auto key = attr.name().toString();
                const auto value = attr.value().toString();
                cur->attris[key]=value;
            }
            cur->tagName = xml.name().toString();
            cur->text = xml.text().toString();
            auto eleName = xml.name();

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
            parent = cur;
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

    QString msg = "[B.&#34;shangpname&#34;]";
    qDebug()<< msg.replace("[B.","").replace("&#34;","").replace("]","");
    return testing;
    return xmlTest();
    //return testPainter();
}

XmlNode* findChildNodeByTagAndAttr(XmlNode& node,QString tag,QString key,QString val){
    for(auto shared:node.children){
        if(shared->tagName==tag
                &&shared->attris.contains(key)
                &&shared->attris[key]==val){
            return shared.data();
        }
    }
    return nullptr;
}


XmlNode* findChildNodeByTagAndIndex(XmlNode& node,QString tag,int index){
    if(index<0||node.children.size()<index)return nullptr;
    int i=0;
    for(auto shared:node.children){
        if(shared->tagName==tag){
            if(i==index){
                 return shared.data();
            }
            i++;
        }
    }
     return nullptr;
}
XmlNode* findFirstChildNodeByTag(XmlNode& node,QString tag){
    return findChildNodeByTagAndIndex(node,tag,0);
}
XmlNode* findChildNodeByAttr(XmlNode& node,QString key,QString val){
    for(auto shared:node.children){
        if(shared->attris.contains(key)
                &&shared->attris[key]==val){
            return shared.data();
        }
    }
    return nullptr;
}
QList<XmlNode*> findChildrenByTag(XmlNode& node,QString tag){
    QList<XmlNode*> list;
    for(auto shared:node.children){
        if(shared->tagName==tag){
            list<<shared.data();
        }
    }
    return list;
}


