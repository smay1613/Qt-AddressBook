QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEPENDENCY_LIBRARIES += ServerLib DBManager
include(dependencies.pri)

SOURCES += \
        include/contactsnetworkreader.cpp \
        src/contact.cpp \
        src/contactsmodel.cpp \
        src/clientmanager.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD/qml
QML2_IMPORT_PATH += $$PWD/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/../ClientLib/include
INCLUDEPATH += $$PWD/../ServerLib/include

HEADERS += \
    include/contact.h \
    include/contactsmodel.h \
    include/contactsnetworkreader.h \
    include/clientmanager.h

DISTFILES += \
    dependencies.pri
