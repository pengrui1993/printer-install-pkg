#include<QImage>
#include<QLabel>
#include<QPainter>
#include<QWidget>
#include<QPushButton>
#include<QRect>
#include<QApplication>
#include<QList>
#include<QSet>
#include<QMap>
#include<QString>
#include<QColor>
#include<QJsonDocument>
#include<QJsonObject>
#include<QHash>
#include<QPair>
#include<QtPrintSupport/QPrinterInfo>
#include<QFont>
#include<QLineF>
#include<QDebug>
#include<QBrush>
#include<QPen>

#include<QPoint>
#include<QByteArray>
#include<QBuffer>
#include<QDir>
#include<QRegularExpressionMatch>
#include<QRegularExpression>
namespace{

using NodeIdSet = QSet<qint64>;
struct TreeNode{
    qint64 pid;
    qint64 id;
    QPoint absolutePos;
    QPoint refParentPos;
};


TreeNode nil{0};
QHash<qint64,TreeNode*> nodes{{{0},{&nil}}};
QHash<qint64,NodeIdSet> parentToChildren;


void calc(const QHash<qint64,NodeIdSet>& parentToChild
          ,qint64 nid,QPoint parentAbsPos){
    auto& node = *nodes[nid];
    node.absolutePos = node.refParentPos+parentAbsPos;
    for(auto cc:parentToChild[nid]){
        calc(parentToChild,cc,node.absolutePos);
    }
}

void calc(qint64 node){
    auto& children = parentToChildren[node];
    for(auto itr = children.begin();itr!=children.end();++itr){
        calc(parentToChildren,*itr,nodes[node]->absolutePos);
    }
}

void reDistanceWithParent(qint64 nid,QPoint distance){
    if(nid==0)return;
    if(distance.x()==0&&distance.y()==0)return;
    auto& node = *nodes[nid];
    node.refParentPos = distance;
    node.absolutePos = nodes[node.pid]->absolutePos+distance;
    calc(nid);
}

void refreshIndex(){
    for(auto itr=nodes.begin();itr!=nodes.end();++itr){
        auto& node = **itr;
        parentToChildren[node.pid]<<node.id;
    }
}


void calc(){
    calc(0);
}


}
static bool testJson(){
    QString json(R"(
{
    "AField":[{"name":"id"},{"name":"color"}]
    ,"AData":[{
        "id": 1
        ,"color": 123456
    },{
        "id": 2
        ,"color": 432123
    }]
}
)");
    QJsonDocument d = QJsonDocument::fromJson(json.toUtf8());
    auto obj = d.object();
    qDebug()<< obj["AField"];
    return false;
}




int testPaint(QApplication& app){
    // 创建一个 QImage 对象，指定大小和格式
    //QImage image(400, 300, QImage::Format_ARGB32);
    QImage image(400,300,QImage::Format_Grayscale8);
    image.fill(Qt::white); // 使用白色填充背景

    // 创建一个 QPainter 对象，并绑定到 QImage 上
    QPainter painter(&image);

    // 设置画笔和画刷
    painter.setPen(Qt::black);
    painter.setBrush(Qt::green);

    // 绘制一些内容，例如一个矩形
    painter.drawRect(50, 50, 300, 200);

    // 绘制一些文本
    painter.setPen(Qt::red);
    painter.drawText(60, 270, "Hello, QImage!");

    // 完成绘制并释放 QPainter
    painter.end();

    // 显示 QImage 内容到一个 QLabel 上
    QLabel label;
    label.setPixmap(QPixmap::fromImage(image));
    label.show();
    return app.exec();
}
//POS58 Printer
int testPaint2(QApplication& app){
    // 创建一个 QImage 对象，指定大小和格式
    //QImage image(400, 300, QImage::Format_ARGB32);
    QImage image(200,100,QImage::Format_Grayscale8);
    image.fill(Qt::white); // 使用白色填充背景
    // 创建一个 QPainter 对象，并绑定到 QImage 上
    QPainter painter(&image);
    auto f = painter.font();
    f.setBold(true);
    f.setPixelSize(20);
    painter.setFont(f);
    painter.drawText(80, 20, "abcdABCD你好!");

    // 完成绘制并释放 QPainter
    painter.end();
    for(auto& info :QPrinterInfo::availablePrinters() ){
        //break;
        if(info.printerName().startsWith("POS58 Printe")){
            QPrinter printer(info,QPrinter::HighResolution);
            QPainter p;
            p.setRenderHint(QPainter::Antialiasing);
            if(p.begin(&printer)){
                p.drawImage(QPoint(0,0),image);
                p.end();
            }

        }
    }

    // 显示 QImage 内容到一个 QLabel 上
    QLabel label;
    label.setPixmap(QPixmap::fromImage(image));
    label.show();
    app.exec();
    return true;
}
static constexpr const bool yesQuit = true;
bool testReg(){
    QString text = "打单日期：[FormatDateTime('yyyy-mm-dd hh:mm:ss',now)]";
    QRegularExpression  regExp("\\[FormatDateTime\\('([ydhms\\- :]+)',(\\S+)\\)\\]");
    auto m = regExp.globalMatch(text);
    if(m.hasNext()){
        auto matcher = m.next();
        qDebug()<< matcher.captured(1);
    }
    QRegExp reg("\\[FormatDateTime\\('([ydhms]+)',(\\S+)\\)\\]");


    return !yesQuit;
}
bool testEtc(QApplication& app){
    //return testPaint2(app);
    //return testJson();
    return testReg();
}
