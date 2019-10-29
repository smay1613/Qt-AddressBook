#pragma once
#include <QTcpServer>
#include "package.h"
#include "contactsworker.h"
#include "connectionargumentsparser.h"

class ServerManager : public QObject
{
    Q_OBJECT
public:
    ServerManager(const net::ConnectionArgumentsParser& parser);

private slots:
    void onNewConnection();
    void onClientDisconnected();
    void onDataArrived();

    void notify(const net::Package& package, QTcpSocket* socket);

private:
    QTcpServer m_server;
    const net::ConnectionArgumentsParser& m_parser;

    std::vector<QTcpSocket*> m_clients;
    ContactsWorker m_contactsWorker;

    void handlePackage(net::Package& package, QTcpSocket* socket);

    void connectSignals();
    void connectSocketSignals(QTcpSocket* socket);
};
