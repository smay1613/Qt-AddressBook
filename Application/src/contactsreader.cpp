#include "contactsreader.h"
#include "Processor.h"
#include "dbtypes.h"
#include <iterator>

using namespace DBTypes;

ContactsReader::ContactsReader()
    : m_dbProcessor {new db::Processor {}}
{
}

std::vector<Contact> transform(const std::vector<DBEntry>& source)
{
    std::vector<Contact> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const DBEntry& entry) {
        return Contact {entry[1].toString(), entry[2].toString(), entry[3].toString(), entry[0].toInt()};
    });
    return target;
}

std::pair<bool, std::vector<Contact>> ContactsReader::requestContactsBrowse()
{
    DBResult result;
    std::vector<DBEntry> entries;
    std::tie(result, entries) = m_dbProcessor->requestTableData(DBTables::Contacts);
    return std::make_pair(result == DBResult::OK,
                          transform(entries));
}

ContactsReader::~ContactsReader()
{
}
