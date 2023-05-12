#ifndef __DATABASE_H
#define __DATABASE_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

#include <iostream>
#include <fstream>
#include <sstream>

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
        // void createTableWithCols(string, int, vector<string> &);


       void createTableWithCols(string, int, vector<string>&);//will create new datatable (new function added by nuha)

        void createTableFromCSVFile(/**HOwever we read in a file*/); // *

        // CRUD
        // CREATE
        void createTable(string, int, vector<string>&);//will create new datatable 
        // void createTable(string, int);//will create new datatable
        void createTableFromCSVFile(string, string); 

        // READ
        Table* getTable(string);//will return table;
        vector<vector<string> > printRAW(string);//will return csv a single table *

        // UPDATE
        DataView* createView(Table * t) 
        {
            DataView* temp = new DataView(t->g_num_of_cols(), t->g_name_of_cols(), t->g_all_data());
            return temp; 
        }
        // DELETE
        void deleteTable(string);//will delete table from database *
        
};//end of Database obejct

#endif