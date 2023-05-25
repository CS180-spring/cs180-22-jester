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
    
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    cout << "Please enter the name of your database: " << endl; 
    std::cin.getline(buffer, BUFFER_SIZE);
    // char db_name[BUFFER_SIZE]  = buffer; 
    char instruction[BUFFER_SIZE] = "BUILD DB ";
    strcat(instruction, buffer);
    printf("%s\n", instruction);
    client->send_message(instruction, sizeof(instruction)+1);
    return; 
}


void jesterAPI::deleteDB()
{
    int input = 0;
    cout << "Are you sure?????" << endl; 
    cout << "1. Yes" << endl; 
    cout << "Literaly anything else for no" << endl; 
    cin>>input;
    if(input == 1)
    {
        cout<<"Deleting Database"<<endl;
        client->send_message("DELETE DB", 12);
    }else
    {
        cout<<"Delete abordted"<<endl;
    }
}
void jesterAPI::buildTable()
{
    // vector<string>fields; 
    int col = 0; 
    
    const int BUFFER_SIZE = 1024;
    char instr[BUFFER_SIZE] = "BUILD TABLE ";
    char instruction[BUFFER_SIZE] = " WITH ";
    char comma[2] = ",";
    char table[BUFFER_SIZE];
    char colName[BUFFER_SIZE];
    cout << "Please enter the name of the table: " << endl;
    cin.ignore(); 
    std::cin.getline(table, BUFFER_SIZE);
    strcat(instr, table);
    strcat(instr, instruction);
    cout << "How many columns would you like in your table?" << endl; 
    cin >> col; 
    // string curr = ""; 
    if(col < 1)
    {
        cout<<"No such table can be created"<<endl;
        return;
    }
    cin.ignore();
    for (unsigned int i = 0; i < col-1; i++){
        cout << "Enter the name of column " << (i + 1) << ":" << endl;   //idk if the i+1 thing works lol 
        std::cin.getline(colName, BUFFER_SIZE);
        strcat(instr, colName);
        strcat(instr, comma);
    }
    cout << "Enter the name of column " << (col) << ":" << endl;   //idk if the i+1 thing works lol 
    std::cin.getline(colName, BUFFER_SIZE);
    strcat(instr, colName);

    
    cout << "got it! making your table now ..... >:)" << endl; 
            
        client->send_message(instr, sizeof(instr)+1);
    // return;
}
void jesterAPI::deleteTable()
{
// vector<string>fields; 
    int col = 0; 
    
    const int BUFFER_SIZE = 1024;
    char instr[BUFFER_SIZE] = "DELETE TABLE ";
    char table[BUFFER_SIZE];
    cout << "Please enter the name of the table: " << endl;
    cin.ignore(); 
    std::cin.getline(table, BUFFER_SIZE);
    strcat(instr, table);
    client->send_message(instr, sizeof(instr)+1);
    return;
}  
void jesterAPI::printTable()
{
    const int BUFFER_SIZE = 1024;
    char instr[BUFFER_SIZE] = "VIEW TABLE ";
    char table[BUFFER_SIZE];
    cout << "Please enter the name of the table: " << endl;
    cin.ignore(); 
    std::cin.getline(table, BUFFER_SIZE);
    strcat(instr, table);
    client->send_message(instr, sizeof(instr)+1);
    return;
    // cout << "Please enter the name of the table that you would like to view:" << endl; 
    // cin >> tableName; 
    // printTable(db, tableName); 
    // return;
}
void jesterAPI::addRow()
{
    // int option; 
    //  const int BUFFER_SIZE = 1024;
    // char instr1[BUFFER_SIZE]  = "ADD ROW TO "; 
    // char instr2[BUFFER_SIZE] = "GET COLUMNS FROM "; 
    // char table_name[BUFFER_SIZE]; 
    // cout << "Please enter the name of the table that you would like to add to: " << endl; 
    // // TODO add ways to see column names for convinience 
    // std::cin.getline(table_name, this.BUFFER_SIZE);
    // strcat(instr2, table_name);
    // client->send_message(instr2, sizeof(instr2)+1);
    // strcat(instruction, table_name);
    // strcat(instruction, instruction_p2); 
    // cout << "Would you like to enter values for your row? 1 for yes, 2 for no, 3 to quit." << endl; 
    // cin >> option; 
    // switch(option)
    // {
    //     case 1: 

    //     case 2: 

    //     case 3: 
    //         cout << "exiting add row...." << endl; 
    //         return; 
    //         break; 
    //     else: 
    //         "Invalid input. Please try again." << endl; 
    //         break; 
    // }

} 
void jesterAPI::deleteRow() {
    // cout << "Please enter the name of your database:" << endl; 
    // cin >> db; 
    // cout << "Please enter the name of the table that you would like to delete the row from:" << endl; 
    // cin >> tableName; 
    // cout << "Please enter the number of the index that you would like to delete:" << endl; 
    // int index = 0; 
    // cin >> index; 
    // deleteRow(db, tableName, index); 
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