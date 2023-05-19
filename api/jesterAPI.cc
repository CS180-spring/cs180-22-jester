#include "jesterAPI.h"
#include <string> 
#include <cstring>
#include <vector> 
#include <iostream> 

using namespace std; 
void jesterAPI::init(){ 
    client->setup_client(); 
    client->connect_to_server();  
}
void jesterAPI::close(){
    //server stuffs here 
    // owen haaaalp 
    client->close_connection(); 


}

//no error handling for these bois 
void jesterAPI::interface(){
    bool quit = false; 
    int option = -1; 
    string db;
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    char * response;
    

    vector<string>emptyRow; 
    string tableName = ""; 
    cout << "Welcome to Jester's document store!" << endl; 
    cout<<"Name your database: ";
    std::cin.getline(buffer, BUFFER_SIZE);
    cout<<"this should print before calling  db"<<endl;
    buildDB(buffer);

    while (!quit){
        cout << /**"1. Create your new database" << endl << **/"2. Delete your database" << endl << "3. Create a table" << "4. Delete a table" << endl; 
        cout << "5. Add a row to your table" << endl << "6. View your table" << endl << "7. Delete a row to the table" << endl << 
        "8. Modify a cell in your table" << endl << "10. Quit" << endl;
        cout << "Please type a number for your option: " << endl; 
        cin >> option; 
        if (option == 1){
            cout << "Please enter the name of your database: " << endl; 
            // cin >> db; 
            // buildDB(db); 
        } else if (option == 2){
            cout << "Please enter the name of the database that you would like to delete: " << endl; 
            cin >> db; 
            deleteDB(db); 
        } else if (option == 3){
            vector<string>fields; 
            int col = 0; 
            cout << "Please enter the name of the database that you would like to add the table to: " << endl; 
            cin >> db; 
            cout << "Please enter the name of the table: " << endl; 
            cin >> tableName; 
            cout << "How many columns would you like in your table?" << endl; 
            cin >> col; 
            string curr = ""; 
            for (unsigned int i = 0; i < col; i++){
                cout << "Enter the name of column " << (i + 1) << ":" << endl;   //idk if the i+1 thing works lol 
                cin >> curr; 
                fields.push_back(curr); 
            }
            cout << "got it! making your table now ..... >:)" << endl; 
            buildTable(db, tableName, col, fields); 
        } else if (option == 4){
            cout << "Enter the name of the database that you would like to delete a table from: " << endl; 
            cin >> db; 
            cout << "Enter the name of the table that you would like to delete: " << endl; 
            cin >> tableName; 
            cout << "got it! deleting your table now .... " << endl; 
            deleteTable(db, tableName); 

        } else if (option == 5){
            cout << "Please enter the name of your database: " << endl; 
            cin >> db; 
            cout << "Please enter the name of the table that you would like to add to:" << endl; 
            cin >> tableName; 
            //wouldn't we have to know the values of the table? maybe we grab the column names and order in addRow. for now empty string vector 
            addRow(db, tableName, emptyRow); 
 
        } else if (option == 6){
            cout << "Please enter the name of your database:" << endl; 
            cin >> db; 
            cout << "Please enter the name of the table that you would like to view:" << endl; 
            cin >> tableName; 
            printTable(db, tableName); 

        } else if (option == 7){
            cout << "Please enter the name of your database:" << endl; 
            cin >> db; 
            cout << "Please enter the name of the table that you would like to delete the row from:" << endl; 
            cin >> tableName; 
            cout << "Please enter the number of the index that you would like to delete:" << endl; 
            int index = 0; 
            cin >> index; 
            deleteRow(db, tableName, index); 
        } else if (option == 8){
            cout << "Please enter the name of your database:" << endl; 
            cin >> db; 
            cout << "Please enter the name of the table that you would like to modify a cell in:" << endl; 
            cin >> tableName; 
            cout << "Please enter the row index that you would like to modify:" << endl; 
            int rowIndex = 0; 
            cin >> rowIndex; 
            cout << "Please enter the name of the column name of the cell that you would like to modify:" << endl; 
            string col = ""; 
            cin >> col; 
            cout << "What would you like the new value of this cell to be?" << endl; 
            string cell = ""; 
            cin >> cell; 
            modifyCell(db, tableName, rowIndex, col, cell); 
        } else if (option == 10){
            quit = true; 
            break; 
        }
    }
    cout << "closing the server..." << endl; 
    close(); 
    cout << "all done. Bye! :+)" << endl; 
}


void jesterAPI::deleteDB(string dbName){

    return; 
}
void jesterAPI::modifyCell(string dbName, string tableName, int rowIndex, string colName, string newValue){

return;
}
void jesterAPI::buildTable(string dbName, string tableName, int columns, vector<string> fields)
{
    return;
}
void jesterAPI::createQuery(string dbName, string query)
{
    return;
}
void jesterAPI::addRow(string dbName, string tableName, vector<string> theRowItself){
return;
} // ? 
void jesterAPI::deleteRow(string dbName, string tableName, int index){
return;
}
void jesterAPI::deleteTable(string dbName, string tableName){
return;
}  
void jesterAPI::printTable(string dbName, string tableName){
return;
}

void jesterAPI::buildDB(char * name)
{

    cout<<"Running Build DB 0"<<endl;

    char* start = "BUILD DB ";  
    char* char_array;
    char_array =  malloc(strlen(start)+strlen(name)+1); 
    strcpy(full_text, start ); 
    strcat(full_text, name);

    // cout<<"Running Build DB 2"<<endl;
    // strcpy(char_array, msg.c_str());
    // cout<<"Running Build DB 3"<<endl;
    // client->send_message(char_array, msg.size());
    client->send_message(name, sizeof(name)+1);
    cout<<"Running Build DB 4"<<endl;
    return; 
}