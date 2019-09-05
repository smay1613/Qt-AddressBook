#include "contactsmodel.h"
#include <QQmlEngine>
#include <QDebug>
#include "contactsnetworkreader.h"

void ContactsModel::addNewContact(int x)
{
    qWarning()<< "Add worked";
}

ContactsModel::ContactsModel()
    : m_readerInstance {ContactsNetworkReader::instance()}
{
    connect(&m_readerInstance, &ContactsNetworkReader::browseCompleted,
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

void ContactsModel::onContactListDownloaded(std::vector<Contact> data)
{
    emit beginResetModel();
    m_contacts.swap(data);
    emit endResetModel();

    qDebug() << "Contact list downloaded!" << rowCount() << " contacts available";
}

void ContactsModel::saveNewContact()
{
    qWarning()<< "signal worked";
}

bool ContactsModel::updateContacts()
{
    bool requestResult {m_readerInstance.requestBrowse()};

    return requestResult;
}
