#pragma once
#include <vector>
#include <memory>
#include "contact.h"

class DBProcessing;
class ContactsReader
{
public:
    ContactsReader();
    std::pair<bool,
              std::vector<Contact>> requestContactsBrowse();
    ~ContactsReader();

private:
    std::unique_ptr<DBProcessing> m_dbProcessor;
};

