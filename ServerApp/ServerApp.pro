QT += core network
QT -= gui
SOURCES += src/main.cpp \
           src/contactsreader.cpp \
           src/contactworker.cpp \
           src/servermanager.cpp

HEADERS += include/contactsreader.h \
           include/contactworker.h \
           include/servermanager.h

INCLUDEPATH += ../shared/include \
               include/

LIBS += -L$$PWD/../shared/lib -lNetworkLib
LIBS += -L$$PWD/../shared/lib -lDBManager
