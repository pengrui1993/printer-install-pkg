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
#include<QSharedPointer>
struct XmlNode{
    QString tagName;
    QString text;
    QMap<QString,QString> attris;
    QList<QSharedPointer<XmlNode>> children;
};



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
QList<XmlNode*> findChildrenByTag(XmlNode& node,QString tag);
XmlNode* findChildNodeByTagAndAttr(XmlNode& node,QString tag,QString key,QString val);
XmlNode* findChildNodeByAttr(XmlNode& node,QString key,QString val);
XmlNode* findChildNodeByTagAndIndex(XmlNode& node,QString tag,int index);
XmlNode* findFirstChildNodeByTag(XmlNode& node,QString tag);

bool readFr3(QXmlStreamReader& xml,PagePrintDesc&desc);
bool readFr3(QXmlStreamReader& xml,XmlNode&root);
#endif // FR3XML_H
