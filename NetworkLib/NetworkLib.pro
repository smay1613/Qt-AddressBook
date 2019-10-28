QT += network
CONFIG += c++11

SOURCES += \
        src/package.cpp \
        src/connectionargumentsparser.cpp

HEADERS += \
        include/package.h \
        include/networktypes.h \
        include/connectionargumentsparser.h

INCLUDEPATH += include
INCLUDEPATH += $$PWD/../shared/include

TEMPLATE = lib

DESTDIR = $$PWD/../shared/lib

headers.path = ../shared/include
headers.files = include/networktypes.h \
                include/package.h \
                include/connectionargumentsparser.h

INSTALLS += headers
