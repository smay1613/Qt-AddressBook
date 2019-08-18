#pragma once
#include <QDataStream>
#include <QVariant>
#include "nettypes.h"

class Package
{
public:
    Package(NetTypes::PackageType type = NetTypes::PackageType::INVALID);

    Package(const QVariant& data, NetTypes::PackageType type = NetTypes::PackageType::INVALID);
    virtual ~Package() = default;

    NetTypes::PackageType type() const;

    QVariant data() const;

    QByteArray rawData() const;

    friend QDataStream& operator>> (QDataStream& stream, Package& package);

private:
    QByteArray m_rawData;
    QDataStream m_translationStream;

    NetTypes::PackageType m_type;
    QVariant m_data;
    void fillTranslationStream();
};
