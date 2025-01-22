QT       += core gui network
QT += serialport
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyRequestHandler.cpp \
    httpserver/httpconnectionhandler.cpp \
    httpserver/httpconnectionhandlerpool.cpp \
    httpserver/httpcookie.cpp \
    httpserver/httpglobal.cpp \
    httpserver/httplistener.cpp \
    httpserver/httprequest.cpp \
    httpserver/httprequesthandler.cpp \
    httpserver/httpresponse.cpp \
    httpserver/httpsession.cpp \
    httpserver/httpsessionstore.cpp \
    httpserver/staticfilecontroller.cpp \
    loghandler.cpp \
    main.cpp \
    mainwindow.cpp \
    painttest.cpp \
    xml.cpp

HEADERS += \
    MyRequestHandler.h \
    fr3xml.h \
    httpserver/httpconnectionhandler.h \
    httpserver/httpconnectionhandlerpool.h \
    httpserver/httpcookie.h \
    httpserver/httpglobal.h \
    httpserver/httplistener.h \
    httpserver/httprequest.h \
    httpserver/httprequesthandler.h \
    httpserver/httpresponse.h \
    httpserver/httpsession.h \
    httpserver/httpsessionstore.h \
    httpserver/staticfilecontroller.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    httpserver/httpserver.pri

RESOURCES += \
    res.qrc
