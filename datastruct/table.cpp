#include "table.h"


using namespace std;
    
void Table::add_row(vector<string>& newRow)
{
    try
    {
        if(newRow.size() != num_of_cols)
        {
            string temp = "Size of new row "+to_string(newRow.size())+" does not match existing (" + to_string(num_of_cols) + ", "+to_string(newRow.size())+") ";
            temp += ("\n\t");
            for(int i = 0; i < newRow.size(); i++)
            {
                temp += (newRow.at(i) + ", ");
            }
            throw invalid_argument(temp);
        }//end of if to make sure size of new column matches
        else
        {
            table.push_back(newRow);
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

}

void Table::modify_table_value(int row_number, string column_name, string new_val){
    vector<string>::iterator it = find(name_of_colums.begin(), name_of_colums.end(), column_name);

    try{
       
        //check for invalud row or col name
    if(row_number > table.size() /*valis row num*/ ||row_number < 0 ||it == name_of_colums.end() /* valid column name*/){
            throw runtime_error("invalid modification");
        }
    }
    catch(runtime_error &e){
        cerr << e.what() << endl; 
        return;
    }


    //if you got to here, its valid. 
    table.at(row_number).at(it - name_of_colums.begin()) = new_val;

}