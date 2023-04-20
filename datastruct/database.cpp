#include "database.h"
using namespace std;


void Database::createTable(string tableName, int colNums, vector<string> &columnNames)
{
    Table* t = new Table(tableName, colNums, columnNames);
    db_map.insert({tableName, t});

}//will create new datatable (end of createTable)
        