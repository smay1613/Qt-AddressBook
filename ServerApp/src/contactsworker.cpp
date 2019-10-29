#include "contactsworker.h"

void ContactsWorker::handleContactsRequest(QTcpSocket *socket)
{
    bool browseResult;
    std::vector<QVariant> data;
    std::tie(browseResult, data) = m_contactsReader.requestContactsBrowse();

    if (browseResult)
    {
        QVariantList dataList;
        std::copy (std::make_move_iterator(data.begin()),
                   std::make_move_iterator(data.end()),
                   std::back_inserter(dataList));

        net::Package resultPackage {QVariant::fromValue(dataList),
                                    net::PackageType::CONTACTS_RESPONSE};
        emit contactsRequestCompleted(resultPackage, socket);
    }
}
