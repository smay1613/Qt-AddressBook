#pragma once
#include <vector>
#include <memory>
#include <QVariant>

class DBProcessing;
class ContactsReader
{
public:
    ContactsReader();
    std::pair<bool,
              std::vector<QVariant>> requestBrowse();
    ~ContactsReader();

private:
    std::unique_ptr<DBProcessing> m_dbProcessor;
};

