#pragma once
#include <QString>
#include <QVariant>
#include "dbtypes.h"

class Contact
{
public:
    Contact() = default;
    Contact(QString firstName, QString secondName, QString phone, DBTypes::DBIndex id);
    QString firstName() const;
    QString secondName() const;
    QString phone() const;

private:
    QString m_phone;
    QString m_firstName;
    QString m_secondName;
    DBTypes::DBIndex m_id;
};

