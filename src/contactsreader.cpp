#include "contactsreader.h"
#include "dbprocessing.h"
#include "dbtypes.h"

ContactsReader::ContactsReader()
{

}

std::pair<bool, std::vector<Contact>> ContactsReader::requestContactsBrowse()
{
    return std::make_pair(true, std::vector<Contact>{});
}

ContactsReader::~ContactsReader()
{

}
