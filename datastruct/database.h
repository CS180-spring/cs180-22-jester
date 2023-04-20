#ifndef __DATABASE_H
#define __DATABASE_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "table.h"

using namespace std;

class Database
{
    private:
        string db_name ="";
        map<string, Table*> db_map;

    public:
        Database(string db_name) : db_name(db_name) {}
        ~Database()
        {
            for(map<string, Table*>::iterator itr = db_map.begin(); itr != db_map.end(); itr++)
            {
                delete (itr->second);
            }
            db_map.clear();
        }

        void createTable(string, int, vector<string>&);//will create new datatable 
        void createTable(string, int);//will create new datatable

        Table* getTable(string);//will return table;

        void deleteTable(string);//will delete table from database *

        vector<vector<string>> printRAW(string);//will return csv a single table *

        vector<vector<string>> createQuery(/*Some way to read queries*/); // *
        void createTableFromCSVFile(/**HOwever we read in a file*/); // *
        

    



};//end of Database obejct

#endif