#ifndef CONTACTSNETWORKREADER_H
#define CONTACTSNETWORKREADER_H
#include "contact.h"
#include "clientmanager.h"

class ContactsNetworkReader : public QObject
{
    Q_OBJECT
public:
    static ContactsNetworkReader& instance();
    bool requestBrowse();

    void setClientManager(ClientManager& clientManager);

signals:
    void browseCompleted(std::vector<Contact> data);

private slots:
    void onConnectionStateChanged(NetTypes::ConnectionState state);

private:
    ContactsNetworkReader() = default;
    ClientManager* m_clientManager;
};

#endif // CONTACTSNETWORKREADER_H
