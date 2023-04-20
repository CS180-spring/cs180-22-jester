#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector> 
#include <iostream> 

using namespace std;

class Table{

    public: 
    Table();
    void add_row_to_table();
    void delete_row();
    void modify_row();
    void printTableRAW();

    int num_of_rows();
    int num_of_cols(); 
    


    private:
    string name_of_table;
    vector<vector<string> > table; 
    vector<string> name_of_rows; 
    int num_of_rows;
    int num_of_cols;

}; 

Table::Table(){//default constructor

        /* user input user values. 
        cout << "what do you want the table to be named?";
        cin >> name_of_table; 
        cout << "what is the num of cols";
        cin >> num_of_cols;

        cout << "enter the labels for the table" ; 
         
        for(int i = 0; i < num_of_cols){
            str s; 
            cin >> s;
            name_of_rows.append(s);  
        }

        */ 

        /* Default values upon creation.
        name_of_table = "no_name";
        num_of_cols = 0;

        */ 

    }


#endif