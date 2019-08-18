#include "contactsreader.h"
#include "dbprocessing.h"
#include "dbtypes.h"

ContactsReader::ContactsReader()
    : m_dbProcessor {new DBProcessing}
{
}

std::pair<bool, std::vector<QVariant>> ContactsReader::requestBrowse()
{
    DBTypes::DBResult requestResult;
    std::vector<DBTypes::DBEntry> entries;
    std::tie(requestResult, entries) = m_dbProcessor->requestTableData(DBTypes::DBTables::Contacts);

    std::vector<QVariant> resultData {std::make_move_iterator(entries.begin()),
                                      std::make_move_iterator(entries.end())};
    return std::make_pair(requestResult == DBTypes::DBResult::OK, resultData);
}

ContactsReader::~ContactsReader()
{
}
