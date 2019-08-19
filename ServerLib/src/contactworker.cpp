#include "contactworker.h"
#include "package.h"
#include <QList>

void ContactWorker::handleContactsRequest()
{
    bool browseResult;
    std::vector<QVariant> data;
    std::tie(browseResult, data) = m_contactsReader.requestBrowse();
}
