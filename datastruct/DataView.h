#ifndef DATAVIEW_H
#define DATAVIEW_H

#include "schema.h"
#include <vector>


class DataView : public Schema {

    public: 
    DataView(int num_col, vector<string> names, vector<vector<string>> t) : Schema(num_col, names, t) {}
    DataView() : Schema() {};

    void filter(string, string, bool);
    void rangeNumerical(string, double, double, bool);
    void rangeString(string, string, string, bool);
    void range(string, string, string, bool);

    private:
        void filterByColumnEquality(int, int, bool);
        void filterByValue(int, string, bool);
    


};

#endif