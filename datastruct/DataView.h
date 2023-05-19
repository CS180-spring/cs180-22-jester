


#ifndef DATAVIEW_H
#define DATAVIEW_H

#include "schema.h"
#include <vector>
// #include "table.h"

class DataView : public Schema {

    public: 
    DataView(int num_col, vector<string> names, vector<vector<string> > t) : Schema(num_col, names, t) {}
    DataView() : Schema() {};

    DataView(vector<vector<string>> table, vector<string> name_of_colums, int num_of_rows, int num_of_cols):Schema(){
    
    this->table = table;
    this->name_of_colums = name_of_colums;
    this->num_of_rows = num_of_rows;
    this->num_of_cols = num_of_cols;
    }

    void filter(string, string, bool);
    void rangeNumerical(string, double, double, bool);
    void rangeString(string, string, string, bool);
    void range(string, string, string, bool);
    void orderBy(string, bool);
    private:
        void filterByColumnEquality(int, int, bool);
        void filterByValue(int, string, bool);
    
    bool cmp(int, int);
    


};

#endif