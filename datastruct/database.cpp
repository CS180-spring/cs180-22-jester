#include "database.h"
using namespace std;


void Database::createTable(string tableName, int colNums, vector<string> &columnNames)
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

void Database::createTable(string tb_name, int colNums)
{
    Table* t = new Table(tb_name, colNums);
    db_map.insert({tb_name, t});
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
    
    


}
        