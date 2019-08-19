#include "package.h"
#include <QByteArray>

Package::Package(NetTypes::PackageType type)
{
}

Package::Package(const QVariant &data, NetTypes::PackageType type)
    : Package(type)
{
}

NetTypes::PackageType Package::type() const
{
    return m_type;
}

QDataStream& operator>>(QDataStream& stream, Package& package)
{

    return stream;
}

void Package::fillTranslationStream()
{
}

QVariant Package::data() const
{
    return m_data;
}

QByteArray Package::rawData() const
{
    return m_rawData;
}

