#include<QImage>
#include<QLabel>
#include<QPainter>
#include<QWidget>
#include<QPushButton>
#include<QRect>
#include<QApplication>
 int testPaint(QApplication& app){
    // 创建一个 QImage 对象，指定大小和格式
    QImage image(400, 300, QImage::Format_ARGB32);
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
