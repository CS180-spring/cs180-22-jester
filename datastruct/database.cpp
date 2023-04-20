#include "database.h"
using namespace std;


void Database::createTable(string tableName, int colNums, &vector<vector<string>> columnNames)
{
    table* t = new table(tableName, colNums, columnNames);

}//will create new datatable (end of createTable)
        