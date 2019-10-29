#pragma once
#include <QCommandLineParser>

namespace net
{
class ConnectionArgumentsParser
{
public:
    explicit ConnectionArgumentsParser(const QCoreApplication& app);

    QString hostArgument() const;
    QString portArgument() const;

private:
    QCommandLineParser m_parser;
    QString m_hostArgument;
    QString m_portArgument;
};
}
