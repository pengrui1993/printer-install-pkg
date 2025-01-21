#include <QFile>
#include <QXmlStreamReader>
#include <iostream>
#include <QString>
static void xmlTest(){
    const auto filepath = QString("/tmp/AAAPosTicket.fr3");
    QFile file(filepath);
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
            auto attrs = xml.attributes();
            for(const auto& attr:attrs){
                std::cerr << attr.name().toString().toStdString() <<":" << attr.value().toString().toStdString() << " ";
            }
            std::cerr << std::endl;
        }break;
        case QXmlStreamReader::EndElement:{
            auto eleName = xml.name().toString();
            //qDebug() <<eleName.trimmed();
            deep--;
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

