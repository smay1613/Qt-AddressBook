QT += core network
QT -= gui
SOURCES += main.cpp

INCLUDEPATH += ../ServerLib/include

LIBS += -L$$PWD/../ServerLib/bin/ -lServerLib
LIBS += -L$$PWD/../DBManager/bin/ -lDBManager

