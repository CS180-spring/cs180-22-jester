


#ifndef DATAVIEW_H
#define DATAVIEW_H

#include "schema.h"
#include <vector>
#include "table.h"

class DataView : public Schema {

    public: 
    DataView(int num_col, vector<string> names, vector<vector<string>> t) : Schema(num_col, names, t) {
        // this->table = t->g_all_data();
        // cout<<"made view"<<endl;
    }
    // DataView( Table* td ) : Schema(td->g_num_of_cols(), td->g_name_of_cols(), td->g_all_data()) {
    //     // this->table = t->g_all_data();
    // }

    // DataView(vector<Table*> vec) : Schema()
    // {
    //     vector<string> temp;
    //     for(Table* t : vec)
    //     {
    //         vector<string> curNames = t->g_name_of_cols();
    //         for(string curColumnName : curNames)
    //         {
    //             string s = t->g_table_name()  + "." + curColumnName;
    //             temp.push_back( s );
    //         }
    //     }
    // }

    DataView(vector<vector<string>> table, vector<string> name_of_colums, int num_of_rows, int num_of_cols):Schema(){
    
    this->table = table;
    this->name_of_colums = name_of_colums;
    this->num_of_rows = num_of_rows;
    this->num_of_cols = num_of_cols;

    }

    void filter(string, string, bool);
    void range(string, string, string, bool);

    private:
        void filterByColumnEquality(int, int, bool);
        void filterByValue(int, string, bool);
    


};

#endif