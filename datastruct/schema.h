
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
        Schema();
        Schema(int );
        Schema(int, vector<string> &);
        Schema(int, vector<string> &, vector<vector<string> > );
        // CREATE
        // void add_row(vector<string>&);//DONE 
        // READ
        void print_col_names();//DONE 
        void print_all_data();//DONE
        int columnExisits(string);//Done
        // DELETE
        // void delete_row(int);//DONE
        // void delete_column(string);  
        // HELPERS
        int g_num_of_rows();//DONE
        int g_num_of_cols(); //DONE
  
        vector<string> g_name_of_cols();//DONE
        vector<vector<string> > g_all_data();//DONE
        // void updateNumOfRowsAndCols();
        virtual void add_row(vector<string>&);//DONE 
      // DELETE
        virtual void delete_row(int);//DONE
        virtual void delete_column(string);  
        void updateNumOfRowsAndCols();
        bool does_this_col_name_exist(string);

    protected:
        vector<vector<string> > table; 
        vector<string> name_of_colums; 
        unsigned int num_of_rows;
        unsigned int num_of_cols;

};
#endif