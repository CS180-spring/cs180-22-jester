#include "DataView.h"
#include <string>
// #include <iostream>
// using namespace std;

void DataView::filter(string c_name, string compareWith, bool invert)
{
    
    // this->print_col_names();
    // cout<<endl;
    bool found = false;
    int firstCol;
    cout<<"sd: "<<name_of_colums.size()<<endl;
    for(int i = 0; i < name_of_colums.size(); i++)
    {
            cout<<"|"<<name_of_colums.at(i)<<"|"<<endl;
        if(c_name.compare(name_of_colums.at(i)) == 0)
        {
            firstCol = i;
            found = true;
        }
    }
    if(!found)
    {
        cout<<"column1 "<< c_name <<"  was not found"<<endl;
        return;
    }

    if(compareWith.find('.')!=string::npos)//if it contains a . then it is a column anme
    {
        found = false;
        int SecondCol;
        for(int i = 0; i < num_of_cols; i++)
        {
            if(compareWith.find("." + name_of_colums.at(i)) != string::npos)
            {
                found = true;
                SecondCol = i;
            }
        }
        if(!found)
        {
            cout<<"column2 "<< compareWith <<" name was not found"<<endl;
            return;
        }
        else
        {
            if(invert)
            {
                int i = 0;
                while(i < table.size())
                {
                    if(table.at(i).at(firstCol) == table.at(i).at(SecondCol))
                    {
                        table.erase(table.begin()+i);
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else
            {
                int i = 0;
                while(i < table.size())
                {
                    if(table.at(i).at(firstCol) != table.at(i).at(SecondCol))
                    {
                        table.erase(table.begin()+i);
                    }
                    else
                    {
                        i++;
                    }
                }
            }
        }
    }
    else// comparing values in column
    {
        if(invert)
        {
            int i = 0;
            while(i < table.size())
            {
                if(table.at(i).at(firstCol) == compareWith)
                {
                    table.erase(table.begin()+i);
                }
                else
                {
                    i++;
                }
            }
        }
        else
        {
            int i = 0;
            while(i < table.size())
            {
                if(table.at(i).at(firstCol) != compareWith)
                {
                    table.erase(table.begin()+i);
                }
                else
                {
                    i++;
                }
            }
        }
        
    }
}




