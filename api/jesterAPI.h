#include <string> 
#include <vector> 
using namespace std; 

class JesterAPI{
    public: 
        
        void close(); 
        void interface(); 
        void buildDB(string name);
        void deleteDB(string dbName);  
        void modifyCell(string dbName, string tableName, int rowIndex, string colName, string newValue); 
        void buildTable(string dbName, string tableName, int columns, vector<string> fields);
        void createQuery(string dbName, string query);
        void addRow(string dbName, string tableName, vector<string> theRowItself); // ? 
        void deleteRow(string dbName, string tableName, int index);
        void deleteTable(string dbName, string tableName);  
        void printTable(string dbName, string tableName); 
    private: 
        void init(); 
        // is there anything that's going to be here? 
}