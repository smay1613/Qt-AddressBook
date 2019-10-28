#include "contactsworker.h"
#include "package.h"

using namespace net;

ContactsWorker& ContactsWorker::instance()
{
    static ContactsWorker instance;
    return instance;
}

bool ContactsWorker::requestBrowse()
{
    if (!m_clientManager)
    {
        qCritical() << "Client manager is not initialized!";
        return false;
    }
    return m_clientManager->sendPackage(Package {QVariant::fromValue(true),
                                        PackageType::CONTACTS_REQUEST});

}

void ContactsWorker::setClientManager(ClientManager& clientManager)
{
    m_clientManager = &clientManager;
    connect(m_clientManager, &ClientManager::connectionStateChanged,
            this, &ContactsWorker::onConnectionStateChanged);
    connect(m_clientManager, &ClientManager::contactsResponse,
            this, &ContactsWorker::browseCompleted);
}

void ContactsWorker::onConnectionStateChanged(ConnectionState state)
{
    if (state == ConnectionState::Connected) {
        requestBrowse();
    }
}
