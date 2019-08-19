#include "servermanager.h"
#include <QTcpSocket>

ServerManager::ServerManager(const QHostAddress &address, quint16 port)
      : m_listenAddress {address},
        m_listenPort {port}
{
    if (!m_server.listen(m_listenAddress, m_listenPort)) {
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

    switch (package.type()) {
        case NetTypes::PackageType::CONTACTS_REQUEST:
        {
            m_contactWorker.handleContactsRequest();
            break;
        }
//        case networking::PType::HISTORY_HASH_UPDATE:
//        case networking::PType::COMMAND_HASHES_REQUEST:
//        case networking::PType::COMMAND_HASHES_RESPONSE:
//        case networking::PType::COMMANDS_REQUEST:
        default: {
            qWarning() << "Invalid package recieved!";
        }
    }
}

void ServerManager::notifyAll(const Package& package)
{
    for (const auto& client : m_clients)
    {
        client->write(package.rawData());
    }
}

void ServerManager::onNewConnection()
{
    qDebug() << "New connection!";
    QTcpSocket* clientConnection = m_server.nextPendingConnection();
    if (clientConnection) {
        connectSocketSignals(clientConnection);
        m_clients.push_back(clientConnection);
    }
}

void ServerManager::onReadyRead()
{
    auto* senderObject = sender();
    QTcpSocket* socket {qobject_cast<QTcpSocket*>(senderObject)};

    if (!socket) {
        return;
    }

    QDataStream in {socket};
    in.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    forever {
        in.startTransaction();

        Package inputPackage {};
        in >> inputPackage;

        if (!in.commitTransaction()) {
            break;
        }

        handlePackage(inputPackage, socket);
    }
}

void ServerManager::onClientDisconnected()
{
    QObject* senderObject = sender();
    QTcpSocket* socket {qobject_cast<QTcpSocket*>(senderObject)};

    if (!socket) {
        return;
    }

    m_clients.erase(std::remove(m_clients.begin(), m_clients.end(), socket));
    socket->deleteLater();
    qDebug() << "Client disconnected!";
}

void ServerManager::connectSignals()
{
    connect(&m_server, &QTcpServer::newConnection,
                this, &ServerManager::onNewConnection);

    connect(&m_contactWorker, &ContactWorker::contactsRequestCompleted,
                this, &ServerManager::notifyAll);
}

void ServerManager::connectSocketSignals(QTcpSocket *socket)
{
    connect(socket, &QAbstractSocket::disconnected,
                this, &ServerManager::onClientDisconnected);
    connect(socket, &QAbstractSocket::readyRead,
                this, &ServerManager::onReadyRead);
}
