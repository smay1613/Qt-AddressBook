#include "contact.h"

Contact::Contact(const DBTypes::DBEntry& entry)
{
}

Contact::Contact(QString firstName, QString secondName, QString phone)
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
}
