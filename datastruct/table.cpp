#include "table.h"


using namespace std;
    

Table::Table() : Schema(0)
{
    
    name_of_table = "no_name";
}//end of 0 arg table constructor
Table::Table(string table_name, int num_of_cols) : Schema( num_of_cols ) 
{
    name_of_table = table_name; 
}// end of 2 arg table constructor
Table::Table(string table_name, int num_of_cols, vector<string> &columnNames) : Schema(num_of_cols, columnNames) 
{
        name_of_table = table_name;
}//end of 3 arg table constructor


string Table::g_table_name() {return name_of_table; }


void Table::add_row(vector<string>& newRow)
{
    try
    {
        if(newRow.size() != num_of_cols)
        {
            string temp = "\033[1;31mSize of new row "+to_string(newRow.size())+" does not match existing (Expected: " + to_string(num_of_cols) + ", Got: "+to_string(newRow.size())+") \033[0m";
            throw invalid_argument(temp);
        }//end of if to make sure size of new column matches
        else
        {
            table.push_back(newRow);
            cout << "\033[4;32mRow Added\033[0m"<<endl;
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

}//end of add_row class

void Table::modify_table_value(int row_number, string column_name, string new_val){
    // vector<string>::iterator it = find(name_of_colums.begin(), name_of_colums.end(), column_name);

    try{
       
        //check for invalud row or col name
    if(row_number-1 > table.size() /*valis row num*/ ||row_number-1 < 0 || columnExisits(column_name) < 0 /* valid column name*/){
            throw runtime_error("invalid modification");
        }
    }
    catch(runtime_error &e){
        cerr << e.what() << endl; 
        return;
    }


    //if you got to here, its valid. 
    
    cout << "\033[4;32mModify Cell\033[0m"<<endl;
    table.at(row_number-1).at(columnExisits(column_name)) = new_val;

}

void Table::outputTableToDisk(string s){
  ofstream myfile;
  string outputFile = "example_" + (s) + ".txt";
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

DataView* Table::createView()
{
    DataView* temp = new DataView( this->table,this->name_of_colums, this->num_of_rows, this->num_of_cols);
    return temp; 
}//end of create DataCiew