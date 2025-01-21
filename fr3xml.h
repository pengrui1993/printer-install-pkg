#ifndef FR3XML_H
#define FR3XML_H
#include <QFile>
#include <QXmlStreamReader>
#include <iostream>
#include <QString>
#include <QDebug>
#include <QFont>
#include <QList>
#include <QSharedPointer>
#include <QMap>
struct Item{
    QString tagName;//TfrxHeader|TfrxFooter |TfrxMemoView|TfrxReportTitle
    QString DataSetName; //A|B
    QString DataField;
    QString fontName;
    qint32 fontColor;
    qreal fontHeight;

    qreal left;
    qreal top;
    qreal width;
    qreal height;

};
struct Dataset{
    QString name;
    QString dataSet;
};
struct PagePrintDesc{
    QList<Dataset> datasets;
    QList<Item> sortedTitles;//TfrxReportTitle
    QList<Item> sortedHeaders;//TfrxHeader
    QList<Item> sortedDatas;//TfrxMasterData
    QList<Item> sortedFooters;//TfrxFooter
};
bool readFr3(QXmlStreamReader& xml,PagePrintDesc&desc);
#endif // FR3XML_H
