#pragma once
#include <QtGlobal>

namespace net
{
enum class PackageType : qint32 {
    INVALID = 10,
    CONTACTS_REQUEST,
    CONTACTS_RESPONSE
};

enum class ConnectionState {
    Connected,
    Disconnected,
    Connecting
};
}
