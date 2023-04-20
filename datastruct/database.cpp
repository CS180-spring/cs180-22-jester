#include "database.h"
using namespace std;


void Database::createTable(string tableName, int colNums, &vector<vector<string>> columnNames)
{
    table* t = new table(tableName, colNums, columnNames);
    db_map.insert({tableName, t});

}//will create new datatable (end of createTable)
        