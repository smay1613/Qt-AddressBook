#pragma once
#include <QAbstractListModel>
#include "contact.h"

class ContactsNetworkReader;
class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    Q_INVOKABLE void addNewContact();

    ContactsModel();
    static void registerMe(const std::string& moduleName);
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:
    void onContactListDownloaded(std::vector<Contact> data);
    void saveNewContact();

private:
    std::vector<Contact> m_contacts;
    ContactsNetworkReader& m_readerInstance;
    enum ContactRoles
    {
        NameRole,
        SurnameRole,
        PhoneNumberRole
    };

    bool updateContacts();
};

