#include "DataView.h"
#include <string>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DataView::filter(string c_name, string compareWith, bool invert)
{
    
    // this->print_col_names();
    // cout<<endl;
    bool found = false;
    int firstCol;
    cout<<"sd: "<<name_of_colums.size()<<endl;
    for(unsigned int i = 0; i < name_of_colums.size(); i++)
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

