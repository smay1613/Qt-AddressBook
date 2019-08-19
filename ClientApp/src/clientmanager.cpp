#include "clientmanager.h"
#include <QTimer>
#include <QDataStream>
#include "package.h"
#include "contact.h"

ClientManager::ClientManager(const ConnectionArgumentsParser& connectionSettings)
    : m_rConnectionSettings {connectionSettings}
{
    connectSocketSignals();
    connectToServer();
}

bool ClientManager::sendPackage(const Package& package)
{
    const bool isConnected {m_state == NetTypes::ConnectionState::Connected};
    if (isConnected)
    {
        m_serverSocket.write(package.rawData());
    }
    return isConnected;
}

void ClientManager::onSocketError(QAbstractSocket::SocketError socketError)
{
    qCritical() << "Socket error happened: " << socketError;

    // Each time socket error was recieved, we try to connect to server again.
    // If connection was failed, we'll get in this slot again.
}

void ClientManager::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "Socket state changed: " << socketState;

    switch (socketState) {
        case QAbstractSocket::SocketState::BoundState:
        case QAbstractSocket::SocketState::ConnectedState: {
            break;
        }
        case QAbstractSocket::SocketState::ClosingState:
        case QAbstractSocket::SocketState::UnconnectedState: {
            break;
        }
        default: {
        }
    }

}

void ClientManager::onDataRecieved()
{
}

void ClientManager::connectToServer()
{
    qDebug() << "Connecting to server...";

}

void ClientManager::connectSocketSignals()
{
    connect(&m_serverSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
                this, &ClientManager::onSocketError);
}

void ClientManager::handleContactsResponsePackage(const Package& package)
{
}
