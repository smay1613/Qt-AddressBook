#include "contact.h"

Contact::Contact(QString firstName, QString secondName, QString phone, DBTypes::DBIndex id)
    : m_phone {std::move(phone)},
      m_firstName {std::move(firstName)},
      m_secondName {std::move(secondName)},
      m_id {id}
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
