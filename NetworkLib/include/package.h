#pragma once
#include <QDataStream>
#include <QVariant>
#include "networktypes.h"

namespace net
{
class Package
{
public:
    Package(net::PackageType type = net::PackageType::INVALID);

    Package(const QVariant& data, net::PackageType type = net::PackageType::INVALID);
    virtual ~Package() = default;

    net::PackageType type() const;

    QVariant data() const;

    QByteArray rawData() const;

    friend QDataStream& operator>> (QDataStream& stream, Package& package);

private:
    QByteArray m_rawData;
    QDataStream m_translationStream;

    net::PackageType m_type;
    QVariant m_data;
    void fillTranslationStream();
};
}
