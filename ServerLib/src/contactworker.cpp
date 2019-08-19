#include "contactworker.h"
#include "package.h"
#include <QList>

void ContactWorker::handleContactsRequest()
{
    bool browseResult;
    std::vector<QVariant> data;
    std::tie(browseResult, data) = m_contactsReader.requestBrowse();

    if (browseResult) {
        QVariantList dataList;
        std::copy(std::make_move_iterator(data.begin()),
                  std::make_move_iterator(data.end()),
                  std::back_inserter(dataList));

        Package resultPackage {QVariant::fromValue(dataList),
                               NetTypes::PackageType::CONTACTS_RESPONSE};
        emit contactsRequestCompleted(resultPackage);
    }
}
