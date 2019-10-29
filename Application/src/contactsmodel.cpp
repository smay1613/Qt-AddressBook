#include "contactsmodel.h"
#include <QQmlEngine>
#include <QDebug>

ContactsModel::ContactsModel()
{
    connect(&m_worker, &ContactsWorker::browsingContactsCompleted,
            this, &ContactsModel::onContactListDownloaded);
    const bool updateResult {updateContacts()};
    if (!updateResult) {
        qWarning() << "Update contacts failed!";
    }
}

void ContactsModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<ContactsModel>(moduleName.c_str(), 1, 0, "ContactsModel");
}

int ContactsModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_contacts.size());
}

QVariant ContactsModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index)) {
        return {};
    }

    const Contact& contact = m_contacts.at(index.row());

    switch (role) {
        case ContactRoles::NameRole: {
            return QVariant::fromValue(contact.firstName());
        }
        case ContactRoles::SurnameRole: {
            return QVariant::fromValue(contact.secondName());
        }
        case ContactRoles::PhoneNumberRole: {
            return QVariant::fromValue(contact.phone());
        }
        default: {
            return {};
        }
    }
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContactRoles::NameRole] = "firstname";
    roles[ContactRoles::SurnameRole] = "surname";
    roles[ContactRoles::PhoneNumberRole] = "phoneNumber";

    return roles;
}

void ContactsModel::onContactListDownloaded(const std::vector<Contact> &data)
{
    emit beginResetModel();
    m_contacts = data;
    emit endResetModel();

    qDebug() << "Contact list downloaded!" << rowCount() << " contacts available!";
}

bool ContactsModel::updateContacts()
{
    bool requestResult {m_worker.requestBrowseContacts()};

    return requestResult;
}
