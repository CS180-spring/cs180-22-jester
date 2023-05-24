#include "jesterAPI.h"
#include <string> 
// #include <cstring>
#include <vector> 
#include <iostream>
#include <sstream> 

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
    bool dbMade = false;
    char * response;
    

    vector<string>emptyRow; 
    string tableName = ""; 
    cout << "Welcome to Jester's document store!" << endl; 
    // cout<<"Name your database: ";
    // std::cin.getline(buffer, BUFFER_SIZE);
    // cout<<"this should print before calling  db"<<endl;
    buildDB();

    while (!quit){
        cout <<"2. Delete your database" << endl << "3. Create a table" << endl << "4. Delete a table" << endl; 
        cout << "5. Add a row to your table" << endl << "6. View your table" << endl << "7. Delete a row to the table" << endl << 
        "8. Delete a column from the table"<<endl<<"9. Create Query"<<endl<<"10. Modify a cell in your table" << endl << "20. Quit" << endl;
        cout << "Please type a number for your option: " << endl; 
        // cin.ignore();
        cin >> option; 

        switch(option)
        {
            case 1:
                // buildDB();
                break;
            case 2:
                deleteDB();
                break;
            case 3:
                buildTable();
                break;
            case 4:
                deleteTable();
                break;
            case 5:
                addRow();
                break;
            case 6:
                printTable();
                break;
            case 7:
                deleteRow();
                break;
            case 8:
                deleteCol();
                break;
            case 9:
                createQuery();
                break;
            case 10: 
                modifyCell();
                break;
            case 20:
                quit = true; 
                break; 
            default:
                cout<<"Invalid Input"<<endl;
        }
    }
    cout << "closing the server..." << endl; 
    close(); 
    cout << "all done. Bye! :+)" << endl; 
}

void jesterAPI::buildDB()
{
    
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    string input;
    cout << "Please enter the name of your database: " << endl; 
    std::cin.getline(buffer, BUFFER_SIZE);
    char instruction[BUFFER_SIZE] = {'B','U','I','L','D',' ','D','B',' '};
    strcat(instruction, buffer);
    printf("%s\n", instruction);
    client->send_message(instruction, sizeof(instruction)+1);
    return; 
}


void jesterAPI::deleteDB(){
    // cout << "Please enter the name of the database that you would like to delete: " << endl; 
    // cin >> db; 
 
    // return; 
}
void jesterAPI::buildTable()
{
    // vector<string>fields; 
    //         int col = 0; 
    //         cout << "Please enter the name of the database that you would like to add the table to: " << endl; 
    //         cin >> db; 
    //         cout << "Please enter the name of the table: " << endl; 
    //         cin >> tableName; 
    //         cout << "How many columns would you like in your table?" << endl; 
    //         cin >> col; 
    //         string curr = ""; 
    //         for (unsigned int i = 0; i < col; i++){
    //             cout << "Enter the name of column " << (i + 1) << ":" << endl;   //idk if the i+1 thing works lol 
    //             cin >> curr; 
    //             fields.push_back(curr); 
    //         }
    //         cout << "got it! making your table now ..... >:)" << endl; 
            // buildTable(db, tableName, col, fields);
    return;
}
void jesterAPI::deleteTable(){
    // cout << "Enter the name of the database that you would like to delete a table from: " << endl; 
    //         cin >> db; 
    //         cout << "Enter the name of the table that you would like to delete: " << endl; 
    //         cin >> tableName; 
    //         cout << "got it! deleting your table now .... " << endl; 
    //         deleteTable(db, tableName); 
return;
}  
void jesterAPI::addRow(){
// cout << "Please enter the name of your database: " << endl; 
//             cin >> db; 
//             cout << "Please enter the name of the table that you would like to add to:" << endl; 
//             cin >> tableName; 
//             //wouldn't we have to know the values of the table? maybe we grab the column names and order in addRow. for now empty string vector 
//             addRow(db, tableName, emptyRow); 
return;
} // ? 
void jesterAPI::printTable(){
    // cout << "Please enter the name of your database:" << endl; 
    //         cin >> db; 
    //         cout << "Please enter the name of the table that you would like to view:" << endl; 
    //         cin >> tableName; 
    //         printTable(db, tableName); 
return;
}
void jesterAPI::deleteRow() {
    // cout << "Please enter the name of your database:" << endl; 
    //         cin >> db; 
    //         cout << "Please enter the name of the table that you would like to delete the row from:" << endl; 
    //         cin >> tableName; 
    //         cout << "Please enter the number of the index that you would like to delete:" << endl; 
    //         int index = 0; 
    //         cin >> index; 
    //         deleteRow(db, tableName, index); 
return;
}
void jesterAPI::deleteCol()
{
return;
}
void jesterAPI::modifyCell(){
    //  cout << "Please enter the name of your database:" << endl; 
    //         cin >> db; 
    //         cout << "Please enter the name of the table that you would like to modify a cell in:" << endl; 
    //         cin >> tableName; 
    //         cout << "Please enter the row index that you would like to modify:" << endl; 
    //         int rowIndex = 0; 
    //         cin >> rowIndex; 
    //         cout << "Please enter the name of the column name of the cell that you would like to modify:" << endl; 
    //         string col = ""; 
    //         cin >> col; 
    //         cout << "What would you like the new value of this cell to be?" << endl; 
    //         string cell = ""; 
    //         cin >> cell; 
    //         modifyCell(db, tableName, rowIndex, col, cell); 

return;
}
void jesterAPI::createQuery()
{
    // return;
}

void jesterAPI::sendInstruction()
{
    bool quit = false; 
    int option = -1; 

    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    char * response;
    

    vector<string>emptyRow; 
    string tableName = ""; 
    cout << "Welcome to Jester's document store!" << endl;
    // cout<<"this should print before calling  db"<<endl;
    // buildDB(buffer);
    while (!quit)
    {
        cout<<"1. Enter Instruction"<<endl;
        cout<<"5. Exit"<<endl;
        cin >> option;

        switch(option)
        {
            case 1: 
                cout<<"Enter Database Instruction: "<<endl;
                cin.ignore(); 
                cin.getline(buffer, BUFFER_SIZE);
                client->send_message(buffer, sizeof(buffer));
               break;
            case 5:
                cout << "closing the server..." << endl; 
                close(); 
                quit = true;
                cout << "all done. Bye! :+)" << endl; 
                break;
            default:
                cout<<"Not a valid option"<<endl;
        }
    }
}