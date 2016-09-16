
QT += core network
 
SOURCES += \
    $$PWD/src/http/qhttpconnection.cpp \
    $$PWD/src/http/qhttprequest.cpp \
    $$PWD/src/http/qhttpresponse.cpp \
    $$PWD/src/http/qhttpserver.cpp \
    $$PWD/src/http/http_parser.c \
    $$PWD/src/restserver.cpp \
    $$PWD/src/restrequest.cpp \
    $$PWD/src/restrequestlistener.cpp \
    $$PWD/src/restresult.cpp

HEADERS += \
    $$PWD/src/http/qhttpconnection.h \
    $$PWD/src/http/qhttprequest.h \
    $$PWD/src/http/qhttpresponse.h \
    $$PWD/src/http/qhttpserver.h \
    $$PWD/src/http/qhttpserverapi.h \
    $$PWD/src/http/qhttpserverfwd.h \
    $$PWD/src/http/http_parser.h \
    $$PWD/src/restserver.h \
    $$PWD/src/restrequest.h \
    $$PWD/src/restrequestlistener.h \
    $$PWD/src/restresult.h


INCLUDEPATH += $$PWD/src
