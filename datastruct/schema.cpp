#include "schema.h"

Schema::Schema()
{
    table = {}; 
    name_of_colums = {}; 
    num_of_cols = 0;
    num_of_rows = 0;
} // end of 0 arg schema constructor

Schema::Schema(int num_of_cols)
{
    this->num_of_cols = num_of_cols;

    cout << "enter the labels for the table" ; 
    for( int i = 0; i < num_of_cols;++i){
        string s; 
        cin >> s;
        name_of_colums.push_back(s);  
    }
}//end of 1 arg schema constructor

Schema::Schema(int num_of_cols, vector<string> &columnNames)
{
    name_of_colums = columnNames;
    this->num_of_cols = num_of_cols;
}

Schema::Schema(int num_of_cols, vector<string> &columnNames, vector<vector<string> > t )
{
    // cout<<"test 1"<<endl;
    name_of_colums = columnNames;
    // cout<<"test 2"<<endl;
    table = t;
    // cout<<"test 3"<<endl;
    num_of_cols = num_of_cols;
}

vector<string> Schema::g_name_of_cols(){
    return name_of_colums;
}

vector<vector<string> > Schema::g_all_data(){
    return table;
}

int Schema::g_num_of_cols(){
    return table.at(0).size();
}

int Schema::g_num_of_rows(){
    return table.size();
}

void Schema::updateNumOfRowsAndCols(){//checks if the inputted column name is in the table. return true if exists
    num_of_cols=table.at(0).size();
    num_of_rows=table.size();
}

bool Schema::does_this_col_name_exist(string s){

    vector<string>::iterator it = find(name_of_colums.begin(), name_of_colums.end(), s);

    try{
       
        //check for invalud row or col name
    if(it == name_of_colums.end() /* valid column name*/){
            throw runtime_error("column name does not exist");
            
        }
    }
    catch(runtime_error &e){
        cerr << e.what() << endl; 
        return false;
    }

    return true;

}



void Schema::print_col_names(){
    unsigned int j = 0;
    for(j = 0 ; j < name_of_colums.size()-1; ++j){
        cout <<"\033[1;34m"<<name_of_colums.at(j) <<", ";
    }
    cout << name_of_colums.at(j) <<"\033[0,]"<<endl;
}

void Schema::print_all_data(){
    // cout<<"### Data for "<< this->name_of_table <<"##"<<endl;
    unsigned int i = 0;
    unsigned int j = 0;

    print_col_names();
     i = 0;
     j = 0;
    cout<<"\033[33m";
    for(i = 0; i < table.size(); ++i){
        for(j = 0 ; j < table.at(i).size()-1; ++j){
            cout << table.at(i).at(j) <<", ";
        }
        cout << table.at(i).at(j) <<endl;
    }
    cout<<"\033[0m";
    
            cout << "\033[4;32mTable Printed\033[0m"<<endl;
}

int Schema::columnExisits(string column)
{
    unsigned int i = 0;
    if(column.at(0)=='.')//remove dot for column's name
    {
        column = column.substr(1, column.size());
        // cout<<"||"<<column<<endl;
    }
    for(i = 0; i < name_of_colums.size(); i++)
    {
        if(column.compare(name_of_colums.at(i)) == 0)
        {
            // cout<<"|"<<column<<"|"<<"=="<<"|"<<name_of_colums.at(i)<<"|"<<column.compare(name_of_colums.at(i))<<endl;
            // cout<<"sdfs"<<endl;
            return i;
        }
    }
    return -1;

}
    

void Schema::add_row(vector<string>& newRow)
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
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return; 
    }
}

void Schema::delete_row(int j){
    //deleting row is zero-indexed. 
    unsigned int i = unsigned(j);

    try{
        unsigned int index = 0;
        if(i < 1)
        {
            throw runtime_error("invalid row attempted to delete (Indexing Starts at 1) ");
        }
        index = i;
        if(index > table[0].size()){
            throw runtime_error("invalid row attempted to delete (Index Cannot be larger than number of rows)");
        }

    }
    catch(runtime_error &e){
        cerr << e.what() << endl; 
        return;
    }

    table.erase(table.begin()+i-1);
    updateNumOfRowsAndCols();

    cout << "\033[4;32mRow Deleted'\033[0m"<<endl;

}


void Schema::delete_column(string s){
    // cout<<"enter delete"<<endl<<endl;

    int loc = columnExisits(s);
    vector<string>::iterator it = name_of_colums.begin()+loc;
        try{
                if ( loc < 0 )
                {
                    string error = "invalid column attempted to delete " + s;
                    throw runtime_error(error);
                }
            }
        catch(runtime_error &e){
            cerr << e.what() << endl; 
            return;
        }
    name_of_colums.erase(it);
    num_of_cols = name_of_colums.size();
    for(unsigned int i = 0 ; i < table.size();++i){
        table.at(i).erase(table.at(i).begin()+loc);
    }

    
    cout << "\033[4;32mColumn Deleted'\033[0m"<<endl;
    // cout<<"sicess"<<endl;
}


// void Schema::delete_column(string s){

//     vector<string>::iterator it = find(name_of_colums.begin(), name_of_colums.end(), s);

//         try{
//             if ( std::find(vec.begin(), vec.end(), item) == vec.end() )
//                 throw runtime_error("invalid column attempted to delete ");
//             }
//         catch(runtime_error &e){
//             cerr << e.what() << endl; 
//         }

//     int i = distance( table.begin(), it); 

//     for(int i = 0 ; i < vector.size();++i){
//         table.erase(table.at(i).begin() + i-1);
//     }

// }

// void Table::modify_table_value(int row_number, string column_name, string new_val){
//     vector<string>::iterator it = find(name_of_colums.begin(), name_of_colums.end(), column_name);

//     try{
       
//         //check for invalud row or col name
//     if(row_number > table.size() /*valis row num*/ ||row_number < 0 ||it == name_of_colums.end() /* valid column name*/){
//             throw runtime_error("invalid modification");
//         }
//     }
//     catch(runtime_error &e){
//         cerr << e.what() << endl; 
//         return;
//     }


//     //if you got to here, its valid. 
//     table.at(row_number).at(it - name_of_colums.begin()) = new_val;


// }

