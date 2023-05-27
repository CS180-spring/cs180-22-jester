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
        Database(string);
        ~Database();
        // void createTableWithCols(string, int, vector<string> &);

       void createTableWithCols(string, unsigned int, vector<string>&);//will create new datatable (new function added by nuha)

        // CRUD
        // CREATE
        void createTable(string, int, vector<string>);//will create new datatable 
        // void createTable(string, int);//will create new datatable
        void createTableFromCSVFile(string, string); 

        // READ
        Table* getTable(string);//will return table;
        vector<vector<string> > printRAW(string);//will return csv a single table *
        // UPDATE
        DataView* createView(Table *); 
        DataView* createView(const vector<string>&);
        vector<vector<string>> compileTable(vector<vector<string>>, vector<string> tableNames);
        // DELETE
        void deleteTable(string);//will delete table from database *

        bool tablesExist(const vector<string>&);

        
};//end of Database obejct




#endif