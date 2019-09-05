#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "contactsmodel.h"
#include "clientmanager.h"
#include "contactsnetworkreader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    ConnectionArgumentsParser parser {*QCoreApplication::instance()};
    ClientManager manager {parser};
    ContactsNetworkReader::instance().setClientManager(manager);
    ContactsModel::registerMe("Contacts");
    qmlRegisterType<ContactsModel> ("Contacts", 1, 0, "ContactsModel");


    QQmlApplicationEngine engine;
    engine.addImportPath(":/qml");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
