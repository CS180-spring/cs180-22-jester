
#ifndef SCHEMA_H
#define SCHEMA_H

#include <string>
#include <vector>  
#include <iostream>  
#include <stdexcept> //try catch
#include <algorithm> //find in vec function

using namespace std;

class Schema{

    public: 
    Schema(){
      num_of_cols = 0;
    }

    Schema(int num_of_cols){;
        this->num_of_cols = num_of_cols;

        cout << "enter the labels for the table" ; 
        for(int i = 0; i < num_of_cols;++i){
            string s; 
            cin >> s;
            name_of_colums.push_back(s);  
        }
    }

    Schema(int num_of_cols, vector<string> &columnNames){
        name_of_colums = columnNames;
        this->num_of_cols = num_of_cols;
    }


    // CRUD
    // CREATE
    void add_row(vector<string>&);//DONE 


    // READ
    void print_table_raw();
    void print_col_names();//DONE 
    void print_all_data();//DONE

    // DELETE
    void delete_row(int);//DONE
    void delete_column(string);  

    // HELPERS
    int g_num_of_rows();//DONE
    int g_num_of_cols(); //DONE
    vector<string> g_name_of_cols();//DONE
    vector<vector<string> > g_all_data();//DONE


    protected:
    vector<vector<string> > table; 
    vector<string> name_of_colums; 
    int num_of_rows;
    int num_of_cols;

}; 


#endif