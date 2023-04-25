#include "database.h"
using namespace std;


void Database::createTable(string tableName, int colNums, vector<string> &columnNames)
{
    Table* t = new Table(tableName, colNums, columnNames);
    db_map.insert({tableName, t});

}//will create new datatable (end of createTable)

void Database::createTable(string tb_name, int colNums)
{
    Table* t = new Table(tb_name, colNums);
    db_map.insert({tb_name, t});
}//will create new datatable (end of createTable)

void Database::createTable(string tb_name, int colNums)
{
    Table* t = new Table(tb_name, colNums);
    db_map.insert({tb_name, t});
}//end of create table

Table* Database::getTable(string tb_name)
{
    return db_map.find(tb_name)->second;
}//end of getTable
        