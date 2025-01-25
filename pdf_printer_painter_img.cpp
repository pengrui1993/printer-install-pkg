#include <QtPdf/QPdfDocument>
#include <QPrinterInfo>
#include <QStringList>
#include <QString>
#include <QImage>
#include <QPdfWriter>
#include <QSize>
#include <QPageSize>
#include <QPdfDocumentRenderOptions>
#include <QPainter>
#include <QPrinter>
#include <QLabel>
#include<QApplication>
static void pdfToImage(QPdfDocument& pd){
    auto info =QPrinterInfo::availablePrinters()[0];
    QPrinter printer(info,QPrinter::HighResolution);

    for(int i=0;i<pd.pageCount();i++){
        auto size = pd.pagePointSize(i).toSize();
        auto scaledSize = size*2;
        QImage img = pd.render(i, scaledSize);
        QPainter painter;
        if(painter.begin(&printer)){
            painter.drawImage(0,0,img);
            painter.end();
        }
    }

}
static int showPdf(QApplication&app,QImage&image){
    QLabel label;
    label.setPixmap(QPixmap::fromImage(image));
    label.show();
    return app.exec();
}
static int showDemo(QApplication&app){
    QPdfDocument pd;
    QFile f("/Users/pengrui/workspace/buss-store/tmp/report_output.pdf");
    f.open(QFile::ReadOnly);
    pd.load(&f);
    f.close();
    if(pd.pageCount()<1){
        qDebug()<<"no pdf page";
        return quit;
    }
    auto size = pd.pagePointSize(0).toSize();
    QImage img = pd.render(0, size);
    auto res= showPdf(app,img);
    return res;

}
static void mergePDFs(const QStringList& fileList, const QString& outputFileName) {
    QPdfWriter pdfWriter(outputFileName);
    pdfWriter.setResolution(150);
    QPdfDocument firstFilePDF;
    firstFilePDF.load(fileList.first());
    QPageSize pageSize = QPageSize(firstFilePDF.pagePointSize(1).toSize());
    pdfWriter.setPageSize(pageSize);
    firstFilePDF.close();

    QPainter painter(&pdfWriter);
    foreach(const QString& file, fileList) {
        QPdfDocument pdfDocument;
        pdfDocument.load(file);

        for(int i = 0; i < pdfDocument.pageCount(); i++) {

            QPdfDocumentRenderOptions renderOptions = QPdfDocumentRenderOptions();
            renderOptions.setRenderFlags(QPdfDocumentRenderOptions::RenderFlag::Annotations);

            QPageSize pageSize = QPageSize(pdfDocument.pagePointSize(i).toSize());
            pdfWriter.setPageSize(pageSize);

            QSize scaledSize = pdfDocument.pagePointSize(i).toSize()*=(2);
            QImage image = pdfDocument.render(i, scaledSize);
            painter.drawImage(QPoint(0, 0), image);

            pdfWriter.newPage();
        }
        pdfDocument.close();
    }
    painter.end();
}

static int renderPdf(QApplication&app){
    QString filePath("/Users/pengrui/workspace/java/java-code-etc/out/report_output.pdf");
    QImage img(400,300,QImage::Format_Grayscale16);

    QPainter painter(&img);


    QPrinter printer(QPrinter::HighResolution);
    printer.setCreator("");
    printer.setOutputFileName(filePath);
    printer.setOutputFormat(QPrinter::PdfFormat);
    //render(&painter);
    painter.end();

    // 显示 QImage 内容到一个 QLabel 上
    QLabel label;
    label.setPixmap(QPixmap::fromImage(img));
    label.show();
    return app.exec();
}
