#include "database.h"
#include "table.h"
using namespace std;


Database::Database(string db_name) : db_name(db_name) {cout << "\033[4;32mDatabase Built: " << db_name <<"\033[0m"<<endl;}
Database::~Database()
{
    
    for(map<string, Table*>::iterator itr = db_map.begin(); itr != db_map.end(); itr++)
    {
        delete (itr->second);
    }
    db_map.clear();
}

void Database::createTableWithCols(string tableName, unsigned int colNums, vector<string> &columnNames)
{
    try
    {
        if(colNums != columnNames.size())
        {
            throw invalid_argument("number of columns does not match vector");
        }
        else
        {
            Table* t = new Table(tableName, colNums, columnNames);
            db_map.insert({tableName, t});
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}//will create new datatable (end of createTable)

void Database::createTable(string tb_name, int colNums, vector<string> s)
{
    Table* t = new Table(tb_name, colNums, s);
    db_map.insert({tb_name, t});
    cout<<"\033[4;32mTable '"<<tb_name<<"' Created \033[0m"<<endl;
}//will create new datatable (end of createTable)

Table* Database::getTable(string tb_name)
{

    return db_map[tb_name];
    // return nullptr;
}//end of getTable

void Database::createTableFromCSVFile(string fileName, string tableName)
{
    try
    {

        fstream inputFile(fileName, ios::in);
        if(!inputFile.is_open())
        {
            throw invalid_argument("File by name "+fileName+" did could not be opened");
        }
        else
        {
            //declare temparary varaibles 
            // vector<vector<string>> content;
            vector<string> csv_row;
            string csv_line; 
            string value;
            
            // get column names
            getline(inputFile, csv_line);

            stringstream colNames(csv_line);

            while(getline(colNames, value, ','))
            {
				csv_row.push_back(value);
            }//end of while

            //create table
            this->createTable(tableName, csv_row.size(), csv_row);

            //read remaining data
            while(getline(inputFile, csv_line))
            {
                csv_row.clear();
    
                stringstream readRows(csv_line);
    
                while(getline(readRows, value, ','))
                {
                    if(value.at(0) == '"')
                    {
                        string temp;
                        getline(readRows, temp, ',');//incase you are reading a string
                        value += temp; 
                    }
                    csv_row.push_back(value);
                }
                getTable(tableName)->add_row(csv_row);
            }//end of while
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //getTable(tableName)->outputTableToDisk(tableName);    //uncomment this to output the input as soon as it comes in. 
}//end of create table from csfFile

DataView* Database::createView(const vector<string>& tableNames)
{
    // Step 1: check if all tables exists
    if(tablesExist(tableNames) == false)
    {
        cout<<"not all values are recognized as existing tables;";
        return nullptr;
    }
    // Step 2: create vecotor of the string names (make sure no dublicate column Names)
    vector<string> compiledColumns;
    vector<vector<string>> compiledTable;

    for(string table : tableNames)
    {
        Table* temp = getTable(table);
        vector<string> currentTableColumns = temp->g_name_of_cols();
        for( string col : currentTableColumns)
        {
            int countOccurence = count(compiledColumns.begin(), compiledColumns.end(), col);
            if( countOccurence )
            {
                string holder = col+"("+to_string(countOccurence+1)+")";
                compiledColumns.push_back(holder);
            }
            else 
            {
                compiledColumns.push_back(col);
            }

        }//end of loop that goes through each column
    }//end of loop that goes throguh each table;



    // generate the compiledTable (will be very ineffecient)
    // int predictNumRows = 1;
    // for(string name : tableNames)
    // {
    //     predictNumRows *= getTable(name)->g_num_of_rows();
    // }
    // compiledTable.reserve(predictNumRows);
    // for(int i = 0; i < predictNumRows; i++)
    // {
    //     compiledTable.at(i).reserve(compiledColumns.size());
    // }

    compiledTable = compileTable(compiledTable, tableNames);
    // for(string ss : compiledTable.at(0))
    //     cout<<ss<<"\t";
    // cout<<endl<<endl;
    return new DataView(compiledColumns.size(), compiledColumns, compiledTable);
}//end of createView (from multiles)

vector<vector<string>> Database::compileTable(vector<vector<string>> exisiting, vector<string> tableNames)
{

    if(exisiting.size() <= 0)
    {
        exisiting.push_back({});//NEEDED in the event that we dont have a table to start off with
    }
    if(tableNames.size() <= 0)
        return exisiting;
    else
    {
        vector<vector<string>> compiledTable;
        Table* cur = getTable(tableNames.at(0));
        vector<vector<string>> curTable = cur->g_all_data();
        int predictNumRows = exisiting.size() * curTable.size();

        // cout<<"s: "<< exisiting.size() << "|" <<curTable.size()<<endl;
        compiledTable.reserve(predictNumRows);

        for(int i = 0; i < predictNumRows; i++)//initialize empty vecotrs that we are expecting
        {
            compiledTable.push_back({});
        }

            // cout<<"test"<<endl;
        int counter = 0;
        for(unsigned int i = 0; i < exisiting.size(); i++)
        {
            for(unsigned int j = 0; j < curTable.size(); j++)
            {
                // cout<<"test2"<<endl;
                compiledTable.at(counter).reserve(exisiting.at(i).size() + curTable.at(j).size());
                // cout<<"test3"<<endl;
                compiledTable.at(counter).insert(compiledTable.at(counter).begin(), curTable.at(j).begin(), curTable.at(j).end());
                compiledTable.at(counter).insert(compiledTable.at(counter).begin(), exisiting.at(i).begin(), exisiting.at(i).end());
                counter++;
            }
        }//done combining the table
        // cout<<"size of compiled: "<<compiledTable.size()<<endl;
        // for(vector<string> v : compiledTable)
        // {
        //     cout<<v.size()<<'\t'<<endl;
        // }
        // string ssss;
        // cin>>ssss;
        vector<string> newList = tableNames;
        newList.erase(newList.begin()+0);
        return compileTable(compiledTable, newList);
    }
}
        

/**
 * Param: list of table names
 * Output: will output true if all the values
 *      int the list of table names are valid
 *      table names, othewise it will return 
 *      false if even on value is not
 * */       
bool Database::tablesExist(const vector<string>& listOfTables)
{
    for(string s : listOfTables)
    {
        if(db_map[s]==nullptr)
        {
            return false;
        }
    }
    return true;
}

void Database::deleteTable(string tableName)
{
    delete getTable(tableName);
    db_map.erase(tableName);
    cout << "\033[4;31mTable: " << tableName <<" deleted\033[0m"<<endl;
}

DataView* Database::createView(Table * t) 
{
    DataView* temp = new DataView(t->g_num_of_cols(), t->g_name_of_cols(), t->g_all_data());
    return temp; 
}//end of createView