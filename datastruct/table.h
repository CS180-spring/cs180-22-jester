
#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>  
#include <iostream>  
#include <stdexcept> //try catch
#include <algorithm> //find in vec function
#include "schema.h"
#include "DataView.h"
#include <fstream>

using namespace std;

class Table: public Schema {

    public: 
    Table() : Schema(0) {
      name_of_table = "no_name";
    }

    Table(string table_name, int num_of_cols) : Schema( num_of_cols ) {
        name_of_table = table_name;
        
    }

    Table(string table_name, int num_of_cols, vector<string> &columnNames) : Schema(num_of_cols, columnNames) {
        name_of_table = table_name;
    }

    // CRUD
    string g_table_name() {return name_of_table; }
    // CREATE
    void add_row(vector<string>&);//DONE 

    // UPDATE
    void modify_table_value(int, string, string);

    //createView in order to Query

    void outputTableToDisk(string);
    DataView* createView(){
        DataView* temp = new DataView( this->table,this->name_of_colums, this->num_of_rows, this->num_of_cols);

        return temp; 
    }
    private:
    string name_of_table;

}; 

#endif