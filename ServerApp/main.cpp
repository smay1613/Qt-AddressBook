#include "servermanager.h"
#include "connectionargumentsparser.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    ConnectionArgumentsParser parser(app);
    ServerManager server {QHostAddress {parser.hostArgument()},
                          static_cast<quint16>(parser.portArgument().toUInt())};

    return app.exec();
}
