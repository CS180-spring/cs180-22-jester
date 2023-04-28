#include "database.h"
#include "table.h"
using namespace std;



void Database::createTableWithCols(string tableName, int colNums, vector<string> &columnNames)
{
    try
    {
        if(colNums != columnNames.size())
        {
            throw invalid_argument("number of columns does not match vector");
        }
        else
        {
            Table* t = new Table(tableName, colNums, columnNames);
            db_map.insert({tableName, t});
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}//will create new datatable (end of createTable)

void Database::createTable(string tb_name, int colNums)
{
    Table* t = new Table(tb_name, colNums);
    db_map.insert({tb_name, t});
}//will create new datatable (end of createTable)

Table* Database::getTable(string tb_name)
{
    return db_map[tb_name];
    // return nullptr;
}//end of getTable
        