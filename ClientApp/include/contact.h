#pragma once
#include <QString>
#include <QVariant>

class Contact
{
public:
    Contact() = default;
    Contact(const QVariantList& entry);
    Contact(const QVariant& wrappedEntry);
    Contact(QString firstName, QString secondName, QString phone);
    QString firstName() const;
    QString secondName() const;
    QString phone() const;
    operator QVariantList() const;

private:
    int m_id;
    QString m_phone;
    QString m_firstName;
    QString m_secondName;
};

