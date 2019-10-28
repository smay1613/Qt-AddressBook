#pragma once
#include <QAbstractListModel>
#include "contact.h"

class ContactsWorker;
class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactsModel();
    static void registerMe(const std::string& moduleName);
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

private slots:
    void onContactListDownloaded(std::vector<Contact> data);

private:
    std::vector<Contact> m_contacts;
    ContactsWorker& m_contactsWorker;

    enum ContactRoles
    {
        NameRole,
        SurnameRole,
        PhoneNumberRole
    };

    bool updateContacts();
};

