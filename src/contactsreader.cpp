#include "contactsreader.h"
#include "dbprocessing.h"
#include "dbtypes.h"

namespace
{
    static const std::vector<Contact> mockData {
        {"Wylie", "Johns", "380618395414"},
        {"Asher", "Blankenship", "380158932138"},
        {"Eric", "French", "380277473644"},
        {"Michael", "Cooper", "380999986699"},
        {"Ulric", "Shepherd", "380626465726"},
        {"Lionel", "Holt", "380454835415"},
        {"Aquila", "Tanner", "380813526568"},
        {"Lee", "Booth", "380423227258"},
        {"Drew", "Branch", "380955112745"},
        {"Francis", "Buckley", "380658457417"},
        {"Stuart", "Wright", "380813526568"},
        {"Leonard", "Tanner", "380813526568"},
        {"Christopher", "Dillon", "380565828659"},
        {"", "Ivanov", "380501728834"}
    };
}

std::pair<bool, std::vector<Contact>> ContactsReader::requestContactsBrowse()
{
}
