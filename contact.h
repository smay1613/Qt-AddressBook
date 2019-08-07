#pragma once
#include <QString>

class Contact
{
public:
    Contact() = default;
    Contact(QString firstName, QString secondName, QString phone);
    QString firstName() const;
    QString secondName() const;
    QString phone() const;

private:
    QString m_phone;
    QString m_firstName;
    QString m_secondName;
};

