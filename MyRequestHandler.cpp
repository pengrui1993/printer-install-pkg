#include "MyRequestHandler.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
MyRequestHandler::MyRequestHandler(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void MyRequestHandler::service(HttpRequest &request, HttpResponse &response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());
    if (path.startsWith("/") ) {
        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(request.printerQuery, &parseError);
        if (parseError.error == QJsonParseError::NoError) {
           auto jsonObj = jsonDoc.object();
           if(!jsonObj["abcd"].isNull()){
                qDebug() << "access from abcd:"<<jsonObj["abcd"].toString();
           }

        }

        response.write("Hello World",true);

    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong no such document.");
    }

    qDebug("RequestMapper: finished request");
}
