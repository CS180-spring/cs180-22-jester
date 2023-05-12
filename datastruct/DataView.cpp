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
    int i = 0;
    while(i < table.size())
    {
        try
        {
            double temp1 = std::stod(table.at(i).at(pos));
            if( ( temp1 >= lower && temp1 < upper ) ^ !invert)//xor
            {
                table.erase(table.begin()+i);
            }
            else
            {
                i++;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cerr << "Values were not all numerical" << '\n';
        }
        
        
    }
}




