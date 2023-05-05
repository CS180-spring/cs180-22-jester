#include "schema.h"
#include "table.h"
#include <vector>

#ifndef DATAVIEW_H
#define DATAVIEW_H

class DataView:public Schema{

    public: 
    DataView():Schema(0)
    {
        
    } 

    DataView(vector<Table*> v) : Schema()
    {
        vector<string> temp;
        for(Table* t : v)
        {
            vector<string> curNames = t->g_name_of_cols();
            for(string curColumnName : curNames)
            {
                string s = t->g_name_of_cols() + "." +curColumnName;
                temp.push_back( s );
            }
        }
    }

    DataView(vector<vector<string>> table, vector<string> name_of_colums, int num_of_rows, int num_of_cols):Schema(){
    
    this->table = table;
    this->name_of_colums = name_of_colums;
    this->num_of_rows = num_of_rows;
    this->num_of_cols = num_of_cols;

    }

    void filter(string, string, bool);
    void range(string, string, string, bool);

};

#endif