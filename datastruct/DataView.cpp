#include "DataView.h"
#include <string>
// #include <iostream>
// using namespace std;

void DataView::filterByColumnEquality(int columnOne, int columnTwo, bool invert)
{
    int i = 0;
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
    int i = 0;
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

void DataView::range(string c_name, string lower, string upper, bool invert)
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
    int i = 0;
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




