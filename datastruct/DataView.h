


#ifndef DATAVIEW_H
#define DATAVIEW_H

#include "schema.h"
#include <vector>
// #include "table.h"

class DataView : public Schema {

    public: 
        //constructors 
        DataView(int, vector<string>, vector<vector<string> >);
        DataView();
        DataView(vector<vector<string>> , vector<string>, int, int);

        void filter(string, string, bool);
        void rangeNumerical(string, double, double, bool);
        void rangeString(string, string, string, bool);
        void range(string, string, string, bool);

    private:
        void filterByColumnEquality(int, int, bool);
        void filterByValue(int, string, bool);
        bool cmp(int, int);
        void orderBy(string, bool);


};

#endif