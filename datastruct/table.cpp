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
            for(unsigned int i = 0; i < newRow.size(); i++)
            {
                temp += (newRow.at(i) + ", ");
            }
            throw invalid_argument(temp);
        }//end of if to make sure size of new column matches
        else
        {
            table.push_back(newRow);
            outputTableToDisk();
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return;
    }

}

void Table::modify_table_value(int row_number_in, string column_name, string new_val){
    vector<string>::iterator it = find(name_of_colums.begin(), name_of_colums.end(), column_name);

    unsigned int row_number = unsigned(row_number_in);

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
    outputTableToDisk();
}

void Table::outputTableToDisk(){
  ofstream myfile;
  string outputFile = "test_" + g_table_name() + ".txt";
  myfile.open(outputFile);

    unsigned int i = 0;
    unsigned int j = 0;

    for(j = 0 ; j < name_of_colums.size()-1; ++j){
        myfile << name_of_colums.at(j) <<", ";
    }
    myfile << name_of_colums.at(j) <<endl;

     i = 0;
     j = 0;

    for(i = 0; i < table.size(); ++i){
        for(j = 0 ; j < table.at(i).size()-1; ++j){
            myfile << table.at(i).at(j) <<", ";
        }
        myfile << name_of_colums.at(j) <<endl;

    }

  myfile.close();
}

void Table::delete_row(int i){
    Schema::delete_row(i);
    outputTableToDisk();
}

void Table::delete_column(string s){
    Schema::delete_column(s);
    outputTableToDisk();
}

// void Table::add_row(vector<string>& v ){
//     Schema::add_row(v);
//     outputTableToDisk();
// }