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
    ClientManager(const net::ConnectionArgumentsParser& connectionSettings);

    constexpr static std::chrono::milliseconds reconnectionTime() {
        return std::chrono::seconds {5};
    }

    bool sendPackage(const net::Package& package);

signals:
    void contactsResponse(std::vector<Contact> data);
    void connectionStateChanged(net::ConnectionState state);
    void reconnectionTimerStarted();

public slots:
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

    //! Entry point for packages
    void onDataRecieved();

private:
    void connectToServer();
    void connectSocketSignals();
    const net::ConnectionArgumentsParser& m_rConnectionSettings;

    void handleContactsResponsePackage(const net::Package& package);

    net::ConnectionState m_state;
    QTcpSocket m_serverSocket;
};
