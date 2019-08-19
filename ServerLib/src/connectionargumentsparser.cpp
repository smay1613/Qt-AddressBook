#include "connectionargumentsparser.h"
#include <QDebug>

ConnectionArgumentsParser::ConnectionArgumentsParser(const QCoreApplication &app)
{
    m_parser.setApplicationDescription("Network application");

    m_parser.addHelpOption();
    m_parser.addOptions({{"server-host", "Server IP address or a hostname.", "host", "127.0.0.1"},
                         {"server-port", "Server port", "port", "8060"}
                        });

    m_parser.process(app);

    m_hostArgument = m_parser.value("server-host");
    m_portArgument = m_parser.value("server-port");
}

const QString ConnectionArgumentsParser::hostArgument() const
{
    return m_hostArgument;
}

const QString ConnectionArgumentsParser::portArgument() const
{
    return m_portArgument;
}
