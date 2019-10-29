#pragma once
#include <QObject>
#include "contact.h"
#include "networktypes.h"
#include "clientmanager.h"

class ContactsWorker : public QObject
{
    Q_OBJECT
public:
    ContactsWorker();
    bool requestBrowseContacts();

signals:
    void browsingContactsCompleted(const std::vector<Contact>& data);

private slots:
    void onConnectionStateChanged(net::ConnectionState state);
    void onContactsDownloadSucceed(const std::vector<QVariant>& data);

private:
     ClientManager& m_clientManager;
};
