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




