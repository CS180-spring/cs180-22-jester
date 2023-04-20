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
        cout << "what do you want the table to be named?";
        cin >> name_of_table; 

        cout << "what is the num of cols";
        cin >> num_of_cols;

        cout << "enter the labels for the table" ; 
        for(int i = 0; i < num_of_cols;++i){
            string s; 
            cin >> s;
            name_of_colums.push_back(s);  
        }
    }

    Table(string table_name, int num_of_cols, vector<string> &columnNames){
        name_of_colums = columnNames;
    }

    void add_row_to_table();
    void delete_row();
    void modify_row();
    void printTableRAW();

    int g_num_of_rows();
    int g_num_of_cols(); 
    


    private:
    string name_of_table;
    vector<vector<string> > table; 
    vector<string> name_of_colums; 
    int num_of_rows;
    int num_of_cols;

}; 


#endif