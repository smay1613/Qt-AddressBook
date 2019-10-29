#pragma once
#include <QObject>
#include <QTcpSocket>
#include "networktypes.h"
#include "connectionargumentsparser.h"
#include "contact.h"
#include "package.h"

class ClientManager : public QObject
{
    Q_OBJECT
public:
    static ClientManager& instance();

    constexpr static std::chrono::milliseconds reconnectionTime() {
        return std::chrono::seconds {5};
    }

    bool sendPackage(const net::Package& package);

    void setConnectionSettings(const net::ConnectionArgumentsParser &connectionSettings);

signals:
    void contactsResponse(const std::vector<QVariant>& data);
    void connectionStateChanged(net::ConnectionState state);
    void reconnectionTimerStarted();

private slots:
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

    void onDataRecieved();

private:
    ClientManager();
    void connectToServer();
    void connectSocketSignals();

    void handlePackage(net::Package& package);
    void handleContactsResponsePackage(const net::Package& package);

    const net::ConnectionArgumentsParser* m_connectionSettings {nullptr};
    net::ConnectionState m_state;
    QTcpSocket m_serverSocket;
};
