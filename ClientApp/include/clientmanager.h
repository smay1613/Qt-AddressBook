#pragma once
#include <QObject>
#include <QTcpSocket>
#include "nettypes.h"
#include "connectionargumentsparser.h"
#include "contact.h"


class Package;
class ClientManager : public QObject
{
    Q_OBJECT
public:
    ClientManager(const ConnectionArgumentsParser& connectionSettings);

    constexpr static std::chrono::milliseconds reconnectionTime() {
        return std::chrono::seconds {5};
    }

    bool sendPackage(const Package& package);

signals:
    void contactsResponse(std::vector<Contact> data);
    void connectionStateChanged(NetTypes::ConnectionState state);
    void reconnectionTimerStarted();

public slots:
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

    //! Entry point for packages
    void onDataRecieved();

private:
    void connectToServer();
    void connectSocketSignals();
    const ConnectionArgumentsParser& m_rConnectionSettings;

    void handleContactsResponsePackage(const Package& package);

    NetTypes::ConnectionState m_state;
    QTcpSocket m_serverSocket;
};
