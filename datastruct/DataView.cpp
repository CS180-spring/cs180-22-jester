#include "DataView.h"




#include <string>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DataView::filterByColumnEquality(int columnOne, int columnTwo, bool invert)
{
    unsigned int i = 0;
    while(i < table.size())
    {
        if( (table.at(i).at(columnOne) == table.at(i).at(columnTwo)) ^ !invert)//xor
        {
            table.erase(table.begin()+i);
        }
        else
        {
            i++;
        }
    }
}
void DataView::filterByValue(int columnOne, string compareWith, bool invert)
{
    unsigned int i = 0;
    while(i < table.size())
    {
        if( (table.at(i).at(columnOne) == compareWith) ^ !invert)//xor
        {
            table.erase(table.begin()+i);
        }
        else
        {
            i++;
        }
    }
}

void DataView::filter(string c_name, string compareWith, bool invert)
{
    int columnPos = columnExisits(c_name);
    if(columnPos  < 0)
    {
        cout<<"(1)could not find columns name: "<<c_name<<endl;
        return;
    }
    else
    {
        if(columnExisits(compareWith) < 0)
        {
            filterByValue(columnPos, compareWith, invert);
            // return;
        }
        else
        {
            int secondColumnPos = columnExisits(compareWith);
            filterByColumnEquality(columnPos, secondColumnPos, invert);
        }
    }  

}

void DataView::rangeString(string c_name, string lower, string upper, bool invert)
{
    string l = lower;
    string u = upper;
    int pos = columnExisits(c_name);
    if(pos < 0)
    {
        cout<<"(3)could not find columns"<<endl;
        return;
    }
    if(l.compare(u) > 0)
    {
        swap(l, u);
    }
    unsigned int i = 0;
    while(i < table.size())
    {
        transform(l.begin(), l.end(), l.begin(), ::toupper);
        transform(u.begin(), u.end(), u.begin(), ::toupper);
        // cout<<table.at(i).at(pos)<<" is " << ((table.at(i).at(pos)).compare(l) >= 0) << " to "<< l <<endl;
        // cout<<table.at(i).at(pos)<<" is " << (table.at(i).at(pos).compare(l) < 0) << " to "<< u <<endl;
        string temp1 = table.at(i).at(pos);
        transform(temp1.begin(), temp1.end(), temp1.begin(), ::toupper);
        if( ( temp1.compare(l) >= 0 && temp1.compare(u) < 0 ) ^ !invert)//xor
        {
            table.erase(table.begin()+i);
        }
        else
        {
            i++;
        }
    }
}
void DataView::range(string c_name, string lower, string upper, bool invert)
{
    double l_double;
    double u_double;
    try
    {
        l_double = stod(lower);
        u_double = stod(upper);

        rangeNumerical(c_name, l_double, u_double, invert);//do numerical comperison
    }
    catch(const std::exception& e)
    {
        rangeString(c_name, lower, upper, invert);//do string comparison
    }
}

void DataView::rangeNumerical(string c_name, double lower, double upper, bool invert)
{
    int pos = columnExisits(c_name);
    if(pos < 0)
    {
        cout<<"(4)could not find columns"<<endl;
        return;
    }
    if(lower > upper)
    {
        swap(lower, upper);
    }
    unsigned int i = 0;
    while(i < table.size())
    {
        double temp1;
        try
        {
             temp1 = std::stod(table.at(i).at(pos));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cerr << "Values were not all numerical: "<< '\n';
            return;
        }
        
        if( ( temp1 >= lower && temp1 < upper ) ^ !invert)//xor
        {
            table.erase(table.begin()+i);
        }
        else
        {
            i++;
        }
        
        
    }
}
//int orderByGlobal;

bool columnSortDescending(const std::vector<std::string>& row1, const std::vector<std::string>& row2, int columnIndex) {
    return row1[columnIndex] < row2[columnIndex];
}

bool columnSortAscending(const std::vector<std::string>& row1, const std::vector<std::string>& row2, int columnIndex) {
    return row1[columnIndex] > row2[columnIndex];
}



// std::sort(vec.begin(), vec.end(),[](const std::vector<string>& a, const std::vector<String>& b) {
//   return a[orderByGlobal] < b[orderByGlobal];
// });


// string s is the column to be sorted.
//bool b if true - descending, if false, ascending. 
void DataView::orderBy(string s, bool b){
    int orderByGlobal=0;
    //check if the column name that was specified is in the table. 

        try{
            if ( std::find(name_of_colums.begin(), name_of_colums.end(), s) == name_of_colums.end() )
                throw runtime_error("invalid column attempted to delete ");
            }catch(runtime_error &e){
            cerr << e.what() << endl; 
        }

        //
        auto it = find(name_of_colums.begin(), name_of_colums.end(), s);

        orderByGlobal = it - name_of_colums.begin();

        cout<< "going to sort col num" <<orderByGlobal;

        //sort(table.begin(), table.end(), sortcol);
        cout<<"soooorting \n ";

        if(b){
            std::sort(table.begin(), table.end(), [&](const std::vector<std::string>& row1, const std::vector<std::string>& row2) {
                 return columnSortDescending(row1, row2, orderByGlobal);
         });

        }else{
                std::sort(table.begin(), table.end(), [&](const std::vector<std::string>& row1, const std::vector<std::string>& row2) {
                 return columnSortAscending(row1, row2, orderByGlobal);
         });
        }

            
    // std::sort(table.begin(),table.end(),cmp);

}







//sort(v.begin(), v.end() , cmp);

