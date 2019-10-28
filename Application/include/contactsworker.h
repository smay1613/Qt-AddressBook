#pragma once
#include "contact.h"
#include "clientmanager.h"

class ContactsWorker : public QObject
{
    Q_OBJECT
public:
    static ContactsWorker& instance();
    bool requestBrowse();

    void setClientManager(ClientManager& clientManager);

signals:
    void browseCompleted(std::vector<Contact> data);

private slots:
    void onConnectionStateChanged(net::ConnectionState state);

private:
    ContactsWorker() = default;
    ClientManager* m_clientManager;
};
