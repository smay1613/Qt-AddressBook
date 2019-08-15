#include "contactsmodel.h"
#include <QQmlEngine>
#include <QDebug>

ContactsModel::ContactsModel()
{

}

void ContactsModel::registerMe(const std::string& moduleName)
{
}

int ContactsModel::rowCount(const QModelIndex& parent) const
{
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
}

bool ContactsModel::updateContacts()
{
}
