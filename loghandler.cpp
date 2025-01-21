#include<QString>
#include<QDebug>
#include<QMessageLogContext>
#include<QFile>
extern void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString logText;
    switch (type) {
    case QtDebugMsg:
        logText = QString("Debug: %1").arg(msg);
        break;
    case QtInfoMsg:
        logText = QString("Info: %1").arg(msg);
        break;
    case QtWarningMsg:
        logText = QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        logText = QString("Critical: %1").arg(msg);
        break;
    case QtFatalMsg:
        logText = QString("Fatal: %1").arg(msg);
        abort(); // 根据需要处理致命错误
    default:
        break;
    }

    QFile logFile("debug.log");
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream textStream(&logFile);
        textStream << logText << "\n";
    }
    logFile.close();
}
