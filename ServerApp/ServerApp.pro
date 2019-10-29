QT += core network
QT -= gui

SOURCES += src/main.cpp \
           src/contactsreader.cpp \
           src/contactsworker.cpp \
           src/servermanager.cpp

HEADERS += include/contactsreader.h \
           include/contactsworker.h \
           include/servermanager.h


INCLUDEPATH += include/ \
               ../shared/include

LIBS += -L$$PWD/../shared/lib -lDBManager
LIBS += -L$$PWD/../shared/lib -lNetworkLib
