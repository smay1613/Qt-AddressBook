#pragma once
#include <QDataStream>
#include <QVariant>
#include "networktypes.h"

namespace net
{
class Package
{
public:
    Package(PackageType type = PackageType::INVALID);
    Package(const QVariant& data, PackageType = PackageType::INVALID);

    PackageType type() const;
    QVariant data() const;
    QByteArray rawData() const;

    friend QDataStream& operator>>(QDataStream& stream, Package& package);
private:
    QByteArray m_rawData;
    QDataStream m_translationStream;

    PackageType m_type;
    QVariant m_data;

    void fillTranslationStream();
};
}
