#include <QFile>
#include <QXmlStreamReader>
#include <iostream>
#include <QString>
#include <QDebug>
#include <QFont>
namespace {
struct Item{
    QString tagName;//TfrxHeader|TfrxFooter |TfrxMemoView

    QString fontName;
    qint32 fontColor;
    qreal fontHeight;

    qreal left;
    qreal top;
    qreal width;
    qreal height;
};

}
void xmlTest(){

    QFile file(":/template/AAAPosTicket.fr3");
    const auto res = file.open(QIODevice::ReadOnly);
    if(!res){
        qDebug() << "open file error:" << file.fileName();
        return;
    }
    QXmlStreamReader xml(&file);
    qDebug() << "start...";
    int deep=0;
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
            auto attrs = xml.attributes();
            for(const auto& attr:attrs){
                const auto key = attr.name().toString();
                const auto value = attr.value().toString();
                qDebug() << key <<":" << value << " ";
            }

        }break;
        case QXmlStreamReader::EndElement:{
            auto eleName = xml.name().toString();
            //qDebug() <<eleName.trimmed();
            deep--;
            qDebug();
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
        qDebug() << " xml error";
    }

}

