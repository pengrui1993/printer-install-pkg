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
