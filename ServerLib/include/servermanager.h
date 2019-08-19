#pragma once
#include <QTcpServer>
#include "package.h"
#include "contactworker.h"

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(const QHostAddress& address, quint16 port);

    void handlePackage(const Package& package, QTcpSocket* socket);

public slots:
    void onReadyRead();
    void notifyAll(const Package& package);

    void onNewConnection();
    void onClientDisconnected();

private:
    void addClient(QTcpSocket* socket);

    void connectSignals();
    void connectSocketSignals(QTcpSocket* socket);

    QTcpServer m_server;

    std::vector<QTcpSocket*> m_clients;

    QHostAddress m_listenAddress;
    quint16 m_listenPort;

    ContactWorker m_contactWorker;
};
