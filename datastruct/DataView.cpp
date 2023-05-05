#include "DataView.h"
#include <string>

void DataView::filter(string c_name, string compareWith, bool invert)
{
    bool found = false;
    int firstCol;
    for(int i = 0; i < num_of_cols; i++)
    {
        if(c_name == ("." + name_of_colums.at(i)))
        {
            firstCol = i;
            found = true;
        }
    }
    if(!found)
    {
        cout<<"column "<< c_name <<" name was not found"<<endl;
        return;
    }

    if(compareWith.find('.'))//if it contains a . then it is a column anme
    {
        found = false;
        int SecondCol;
        for(int i = 0; i < num_of_cols; i++)
        {
            if(compareWith == ("." + name_of_colums.at(i)))
            {
                found = true;
                SecondCol = i;
            }
        }
        if(!found)
        {
            cout<<"column "<< compareWith <<" name was not found"<<endl;
            return;
        }
        else
        {
            if(!invert)
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
        if(!invert)
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
