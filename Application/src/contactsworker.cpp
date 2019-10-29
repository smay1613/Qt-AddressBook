#include "contactsworker.h"

ContactsWorker::ContactsWorker()
               : m_clientManager {ClientManager::instance()}
{
    connect(&m_clientManager, &ClientManager::connectionStateChanged,
            this, &ContactsWorker::onConnectionStateChanged);
    connect(&m_clientManager, &ClientManager::contactsResponse,
            this, &ContactsWorker::onContactsDownloadSucceed);
}

bool ContactsWorker::requestBrowseContacts()
{
    const auto& package = net::Package {QVariant::fromValue(true), net::PackageType::CONTACTS_REQUEST};
    return m_clientManager.sendPackage(package);
}

void ContactsWorker::onConnectionStateChanged(net::ConnectionState state)
{
    if (state == net::ConnectionState::Connected)
    {
        requestBrowseContacts();
    }
}

std::vector<Contact> transform(const std::vector<QVariant>& source)
{
    std::vector<Contact> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const QVariant& entry) {
        QSequentialIterable value = entry.value<QSequentialIterable>();
        return Contact {
            value.at(1).toString(),
            value.at(2).toString(),
            value.at(3).toString(),
            value.at(0).toInt()
        };
    });
    return target;
}

void ContactsWorker::onContactsDownloadSucceed(const std::vector<QVariant> &data)
{
    emit browsingContactsCompleted(transform(data));
}
