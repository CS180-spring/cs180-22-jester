
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

class Table: public Schema 
{
    private:
       string name_of_table;

    public: 

    // Constructors
    Table();
    Table(string, int);
    Table(string, int, vector<string>&);


    // CRUD
    string g_table_name();
    // CREATE
    void add_row(vector<string>&); 

    // UPDATE
    void modify_table_value(int, string, string);

    //createView in order to Query

    DataView* createView();

    void outputTableToDisk();

    void delete_row(int) override;

    void delete_column(string) override;
    //void add_row(vector<string>&) override;
    void keepCols(vector<string>&);

    ~Table();

    private:
    string name_of_table;


}; //END OF TABLE CLASS

#endif