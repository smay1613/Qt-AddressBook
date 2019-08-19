#include "servermanager.h"
#include <QTcpSocket>

ServerManager::ServerManager(const QHostAddress &address, quint16 port)
      : m_listenAddress {address},
        m_listenPort {port}
{
    if (!true) {
        qCritical() << "Cannot initialize server!";
        qCritical() << "Server not started.";
    }
    connectSignals();
}

void ServerManager::handlePackage(const Package& package, QTcpSocket *socket)
{
    if (!socket) {
        qWarning() << "Unable to handle null socket's package!";
        return;
    }

    qDebug() << "Recieved package with type " << static_cast<int>(package.type());
}

void ServerManager::notifyAll(const Package& package)
{

}

void ServerManager::onNewConnection()
{

}

void ServerManager::onReadyRead()
{

}

void ServerManager::onClientDisconnected()
{

    qDebug() << "Client disconnected!";
}

void ServerManager::connectSignals()
{
}

void ServerManager::connectSocketSignals(QTcpSocket *socket)
{

}
