#pragma once
#include <QString>
#include <QVariant>
#include "dbtypes.h"

class Contact
{
public:
    Contact() = default;
    Contact(const DBTypes::DBEntry& entry);
    Contact(QString firstName, QString secondName, QString phone);
    QString firstName() const;
    QString secondName() const;
    QString phone() const;
    operator DBTypes::DBEntry() const;

private:
    DBTypes::DBIndex m_id;
    QString m_phone;
    QString m_firstName;
    QString m_secondName;
};

