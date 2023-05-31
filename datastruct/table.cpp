#include "table.h"


using namespace std;
    
void Table::add_row(vector<string>& v ){
    Schema::add_row(v);
    outputTableToDisk();
}

void Table::modify_table_value(int row_number_in, string column_name, string new_val){
    vector<string>::iterator it = find(name_of_colums.begin(), name_of_colums.end(), column_name);

    unsigned int row_number = unsigned(row_number_in);

    try{
       
        //check for invalud row or col name
    if(row_number > table.size() /*valis row num*/ ||row_number < 0 ||!(Schema::does_this_col_name_exist(column_name)) /* valid column name*/){
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
  string outputFile = "./outputDisk/test_" + g_table_name() + ".csv";
  myfile.open(outputFile);

    unsigned int i = 0;
    unsigned int j = 0;

    for(j = 0 ; j < name_of_colums.size(); ++j){
        myfile << name_of_colums.at(j) <<", ";
    }
    myfile << endl;

     i = 0;
     j = 0;

    for(i = 0; i < table.size(); ++i){
        for(j = 0 ; j < table.at(i).size(); ++j){
            myfile << table.at(i).at(j) <<", ";
        }
        myfile <<endl;
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

void Table::keepCols(vector<string>& input){
    //input: the name of the rows that you are trying to keep, delete everything else. 
    std::vector<std::string> result;
    std::vector<std::string> v1 = g_name_of_cols(); 
    std::vector<std::string> v2 = input;
    
    for(const auto& str : v1) {
        if (std::find(v2.begin(), v2.end(), str) == v2.end()) {
            result.push_back(str);
            cout<<str;
        }
    }
    //result should have at this point the name of the columns that are not in the input. 

    

    for(int i = 0; i < result.size(); ++i){
        Schema::delete_column(result.at(i));
    }

    outputTableToDisk(); //update output file

}

Table::~Table() {
    
}
