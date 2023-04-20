#include "table.h"


vector<string> Table::g_name_of_cols(){
    return name_of_colums;
}

vector<vector<string> > Table::g_allData(){
    return table;
}


void Table::print_col_names(){
    for(int i = 0; i < name_of_colums.size(); ++i){
        cout << name_of_colums.at(i);
    }
}

void Table::print_all_data(){
    for(int j = 0 ; j < name_of_colums.size(); ++j){
        cout << name_of_colums.at(j) <<", ";
    }


    for(int i =0 ; i < table.size(); ++i){
        for(int j = 0 ; i < table.at(0).size(); ++j){
        cout << table.at(i).at(j);
        }
    }


}
    
void Table::add_row(vector<string>& newRow)
{
    try
    {
        if(newRow.size() != num_of_cols)
        {
            string temp = "Size of new row "+to_string(newRow.size())+" does not match existing (" + to_string(num_of_cols) + ") ";
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
