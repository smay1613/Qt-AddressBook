#include "contact.h"

Contact::Contact(const QVariantList& entry)
    : m_id {entry.first().toInt()},
      m_phone {entry.at(3).toString()},
      m_firstName {entry.at(1).toString()},
      m_secondName {entry.at(2).toString()}
{
}

Contact::Contact(const QVariant& wrappedEntry)
    : Contact(wrappedEntry.value<QVariantList>())
{
}

Contact::Contact(QString firstName, QString secondName, QString phone)
    : m_phone {std::move(phone)},
      m_firstName {std::move(firstName)},
      m_secondName {std::move(secondName)}
{
}

QString Contact::firstName() const
{
    return m_firstName;
}

QString Contact::secondName() const
{
    return m_secondName;
}

QString Contact::phone() const
{
    return m_phone;
}

Contact::operator QVariantList() const
{
    return QVariantList {m_firstName,
                         m_secondName,
                         m_phone};
}
