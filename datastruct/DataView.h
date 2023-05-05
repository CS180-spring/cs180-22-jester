#ifndef DATAVIEW_H
#define DATAVIEW_H

#include "schema.h"
#include <vector>


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

    void filter(string, string, bool);
    void range(string, string, string, bool);
    


};

#endif