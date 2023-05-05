#include "schema.h"
#include "table.h"

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
                string s = t->g_table_name()  + "." + curColumnName;
                temp.push_back( s );
            }
        }
    }

    void filter(string, string, bool);
    void range(string, string, string, bool);

};

#endif