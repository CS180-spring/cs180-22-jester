#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector> 
#include <iostream> 

using namespace std;

class Table{

    public: 
    Table(){
      name_of_table = "no_name";
      num_of_cols = 0;
    }

    Table(string table_name, int num_of_cols){
        name_of_table = table_name;
        this->num_of_cols = num_of_cols;

        cout << "enter the labels for the table" ; 
        for(int i = 0; i < num_of_cols;++i){
            string s; 
            cin >> s;
            name_of_colums.push_back(s);  
        }
    }

    Table(string table_name, int num_of_cols, vector<string> &columnNames){
        name_of_colums = columnNames;
        this->num_of_cols = num_of_cols;
        name_of_colums = columnNames;
    }


    // CRUD
    // CREATE
    void add_row(vector<string>&);//

    // READ
    void printTableRAW();
    void print_col_names();//
    void print_all_data();//

    // UPDATE
    void modify_table_value(string, string);

    // DELETE
    void delete_row(int);

    // HELPERS
    int g_num_of_rows();
    int g_num_of_cols(); 
    vector<string> g_name_of_cols();//
    vector<vector<string> > g_allData();//


    private:
    string name_of_table;
    vector<vector<string> > table; 
    vector<string> name_of_colums; 
    int num_of_rows;
    int num_of_cols;

}; 


#endif