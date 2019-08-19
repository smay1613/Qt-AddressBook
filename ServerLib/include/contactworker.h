#pragma once
#include <QObject>
#include "contactsreader.h"
#include "package.h"

class ContactWorker : public QObject
{
    Q_OBJECT
public:
    void handleContactsRequest();

signals:
    void contactsRequestCompleted(const Package& packageData);

private:
    ContactsReader m_contactsReader;
};
