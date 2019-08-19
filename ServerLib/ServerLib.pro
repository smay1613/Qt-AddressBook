QT += network
CONFIG += c++11

SOURCES += \
        src/package.cpp \
        src/servermanager.cpp \
        src/contactworker.cpp \
        src/contactsreader.cpp \
        src/connectionargumentsparser.cpp

HEADERS += \
        include/package.h \
        include/nettypes.h \
        include/servermanager.h \
        include/contactworker.h \
        include/contactsreader.h \
        include/connectionargumentsparser.h

INCLUDEPATH += include
INCLUDEPATH += ../DBManager/include

TEMPLATE = lib

DESTDIR = $$PWD/bin

LIBS += -L$$PWD/../DBManager/bin/ -lDBManager
