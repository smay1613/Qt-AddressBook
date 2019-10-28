#include "package.h"
#include <QByteArray>

namespace net
{
Package::Package(net::PackageType type)
    : m_translationStream {&m_rawData, QIODevice::WriteOnly},
      m_type {type}
{
    m_translationStream.setVersion(QDataStream::Qt_DefaultCompiledVersion);
}

Package::Package(const QVariant &data, net::PackageType type)
    : Package(type)
{
    m_data = data;
    fillTranslationStream();
}

net::PackageType Package::type() const
{
    return m_type;
}

QDataStream& operator>>(QDataStream& stream, Package& package)
{
    quint32 type;
    stream >> type;
    package.m_type = static_cast<net::PackageType>(type);

    QVariant data;
    stream >> data;
    package.m_data = data;

    package.fillTranslationStream();

    return stream;
}

void Package::fillTranslationStream()
{
    m_translationStream << static_cast<qint32>(m_type) << m_data;
}

QVariant Package::data() const
{
    return m_data;
}

QByteArray Package::rawData() const
{
    return m_rawData;
}
}
