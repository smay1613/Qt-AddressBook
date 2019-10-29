#include "servermanager.h"
#include "connectionargumentsparser.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    net::ConnectionArgumentsParser parser {app};

    ServerManager server {parser};

    return app.exec();
}
