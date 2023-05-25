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
    //add something for delete db here too? or ask the user if they want to delete their database or not. 
    client->close_connection(); 
}

void jesterAPI::interface(){
    bool quit = false; 
    int option = -1; 
    string db;
    bool dbMade = false;
    char * response;
    // add send instruction to interface 

    cout << "Welcome to Jester's document store!" << endl; 
    buildDB();
    while (!quit){
        cout << "1. Create a table" << endl << "2. Delete a table" << endl; 
        cout << "3. Add a row to your table" << endl << "4. View your table" << endl << "5. Delete a row from your table" << endl << 
        "6. Delete a column from your table" << endl << "7. Create your own instruction to execute" << endl <<"8. Modify a cell in your table" << endl << "20. Quit" << endl;
        cout << "Please type a number for your option: " << endl; 
        // cin.ignore();
        cin >> option; 

        switch(option)
        {
            case 1:
                buildTable();
                break;
            case 2:
                deleteTable();
                break;
            case 3:
                addRow();
                break;
            case 4:
                printTable();
                break;
            case 5:
                deleteRow();
                break;
            case 6:
                deleteCol();
                break;
            case 7:
                sendInstruction(); 
                break;
            case 8: 
                modifyCell();
                break;
            case 20:
                quit = true; 
                break; 
            default:
                cout<<"Invalid input! Please try again." << endl;
        }
    }
    cout << "closing the server..." << endl; 
    close(); 
    cout << "all done. Bye! :+)" << endl; 
}

void jesterAPI::buildDB()
{

    char buffer[this.BUFFER_SIZE];
    cout << "Please enter the name of your database: " << endl; 
    std::cin.getline(buffer, BUFFER_SIZE);
    this.db_name = buffer; 
    char instruction[this.BUFFER_SIZE] = "BUILD DB ";
    strcat(instruction, buffer);
    printf("%s\n", instruction);
    client->send_message(instruction, sizeof(instruction)+1);
    return; 
}


void jesterAPI::deleteDB()
{
    // cout << "Please enter the name of the database that you would like to delete: " << endl; 
    // cin >> db; 
 
    // return; 
}
void jesterAPI::buildTable()
{
    // // vector<string>fields; 
    // //         int col = 0; 
    // //         cout << "Please enter the name of the database that you would like to add the table to: " << endl; 
    // //         cin >> db; 
    // //         cout << "Please enter the name of the table: " << endl; 
    // //         cin >> tableName; 
    // //         cout << "How many columns would you like in your table?" << endl; 
    // //         cin >> col; 
    // //         string curr = ""; 
    // //         for (unsigned int i = 0; i < col; i++){
    // //             cout << "Enter the name of column " << (i + 1) << ":" << endl;   //idk if the i+1 thing works lol 
    // //             cin >> curr; 
    // //             fields.push_back(curr); 
    // //         }
    // //         cout << "got it! making your table now ..... >:)" << endl; 
    //         // buildTable(db, tableName, col, fields);
    // return;
}
void jesterAPI::deleteTable()
{
    char[this.BUFFER_SIZE] instruction = "DELETE TABLE "; 
    char[this.BUFFER_SIZE] table_name; 
    cout << "Enter the name of the table that you would like to delete: " << endl; 
    std::cin.getline(table_name, this.BUFFER_SIZE);  
    strcat(instruction, table_name);
    cout << "got it! deleting your table now .... " << endl; 
    client->send_message(instruction, sizeof(instruction)+1);
    return;
}  
void jesterAPI::addRow()
{
    int option; 
    char[this.BUFFER_SIZE] instruction = "ADD ROW TO "; 
    char[this.BUFFER_SIZE] table_name; 
    cout << "Please enter the name of the table that you would like to add to: " << endl; 
    std::cin.getline(table_name, this.BUFFER_SIZE);
    strcat(instruction, table_name);
    strcat(instruction, instruction_p2); 
    cout << "Would you like to enter values for your row? 1 for yes, 2 for no, 3 to quit." << endl; 
    cin >> option; 
    switch(option)
    {
        case 1: 

        case 2: 

        case 3: 
            cout << "exiting add row...." << endl; 
            return; 
            break; 
        else: 
            "Invalid input. Please try again." << endl; 
            break; 
    }

} // ? 
void jesterAPI::printTable()
{
    cout << "Please enter the name of the table that you would like to view:" << endl; 
    cin >> tableName; 
    printTable(db, tableName); 
    return;
}
void jesterAPI::deleteRow() {
    cout << "Please enter the name of your database:" << endl; 
    cin >> db; 
    cout << "Please enter the name of the table that you would like to delete the row from:" << endl; 
    cin >> tableName; 
    cout << "Please enter the number of the index that you would like to delete:" << endl; 
    int index = 0; 
    cin >> index; 
    deleteRow(db, tableName, index); 
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
    
// add sample queries for menu 
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