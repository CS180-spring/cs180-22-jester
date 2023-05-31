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
        cout << "3. Add a row to your table" << endl << "4. View your table" << endl << "5. Delete a row from your table" << endl; 
        cout << "6. Delete a column from your table" << endl << "7. Create your own instruction to execute" << endl;
        cout << "8. Modify a cell in your table" << endl<<"9. Create Query" << endl << "10. Upload CSV" << endl << "20. Quit" << endl;
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
            case 9: 
                createQuery();
                break;
            case 10: 
                // modifyCell();
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
     const int BUFFER_SIZE = 1024;
    char instr1[BUFFER_SIZE]  = "FROM "; 
    char instr2[BUFFER_SIZE] = "GET "; 
    char instr3[BUFFER_SIZE] = " COLUMNS"; 
    char instr4[BUFFER_SIZE] = " ADD "; 
    char table_name[BUFFER_SIZE]; 
    char newRow[BUFFER_SIZE]; 
    cout << "Please enter the name of the table that you would like to add to: " << endl; 
    // // TODO add ways to see column names for convinience 
    cin.ignore();
    std::cin.getline(table_name, BUFFER_SIZE);
    strcat(instr2, table_name);
    strcat(instr2, instr3);
    client->send_message(instr2, sizeof(instr2)+1);
    // strcat(instruction, table_name);
    // strcat(instruction, instruction_p2); 
    cout << "1. Add new row" << endl; 
    cout << "5. exit" << endl; 
    int option;
    cin >> option; 
    switch(option)
    {
        case 1: 
            cout<<"Add Row as values seperated only by commas"<<endl;
            cin.ignore();
            std::cin.getline(newRow, BUFFER_SIZE);
            strcat(instr1, table_name);
            strcat(instr1, instr4);
            strcat(instr1, newRow);
            client->send_message(instr1, sizeof(instr1)+1);
            break;
        default:
            cout<<"No row added"<<endl;
    }

} 
void jesterAPI::deleteRow() {
    const int BUFFER_SIZE = 1024;
    char instr1[BUFFER_SIZE]  = "DELETE ROW "; 
    char instr2[BUFFER_SIZE]  = " FROM "; 
    char digit[BUFFER_SIZE]; 
    char table_name[BUFFER_SIZE]; 
    char index_number[10]; 
    cout << "Please enter the name of the table that you would like to delete the row from:" << endl; 
    cin.ignore();
    std::cin.getline(table_name, BUFFER_SIZE);
    cout << "Please enter the index that you would like to delete:" << endl; 
    std::cin.getline(index_number, 10);

    strcat(instr1, index_number);
    strcat(instr1, instr2);
    strcat(instr1, table_name);

    client->send_message(instr1, sizeof(instr1)+1);
    return;
}
void jesterAPI::deleteCol()
{
    const int BUFFER_SIZE = 1024;
    char instr1[BUFFER_SIZE]  = "DELETE COLUMN "; 
    char instr2[BUFFER_SIZE]  = " FROM "; 
    char digit[BUFFER_SIZE]; 
    char table_name[BUFFER_SIZE]; 
    char col_name[BUFFER_SIZE]; 
    cout << "Please enter the name of the table that you would like to delete the column from:" << endl; 
    cin.ignore();
    std::cin.getline(table_name, BUFFER_SIZE);
    cout << "Please enter the column name that you would like to delete:" << endl; 
    std::cin.getline(col_name, BUFFER_SIZE);

    strcat(instr1, col_name);
    strcat(instr1, instr2);
    strcat(instr1, table_name);

    client->send_message(instr1, sizeof(instr1)+1);
    return;
}
void jesterAPI::modifyCell(){
    // usage: FROM <tableName> UPDATE <rowIndex> <colName> TO <newValue>
    const int BUFFER_SIZE = 1024;
    char instruction[BUFFER_SIZE] = "FROM ";
    char tableName[BUFFER_SIZE];  
    char rowidx[BUFFER_SIZE]; 
    char colName[BUFFER_SIZE]; 
    char newVal[BUFFER_SIZE]; 
    char space[2] = " "; 
    char instructionp2[BUFFER_SIZE] = " UPDATE "; 
    char instructionp3[BUFFER_SIZE] = " TO "; 
    cout << "Enter the name of the table that you would like to modify: " << endl; 
    cin.ignore(); 
    std::cin.getline(tableName, BUFFER_SIZE);
    // strcat(instruction, instructionp2); 
    cout << "Enter the row index that you would like to modify: " << endl; 
    std::cin.getline(rowidx, BUFFER_SIZE);
    cout << "Enter the name of the column that you would like to modify: " << endl; 
    std::cin.getline(colName, BUFFER_SIZE);
    cout << "Enter the new value of this cell: " << endl; 
    std::cin.getline(newVal, BUFFER_SIZE); 
    strcat(instruction, tableName);
    strcat(instruction, instructionp2);
    strcat(instruction, rowidx); 
    strcat(instruction, space);
    strcat(instruction, colName); 
    strcat(instruction, instructionp3);
    strcat(instruction, newVal); 
    cout << "Updating your cell value now ... " << endl; 
    client->send_message(instruction, sizeof(instruction)+1);     
    return;
}
void jesterAPI::createQuery()
{
    // BUILD QUERY table1,table2,...
    // FILTER BY ____ (==/!=) ____
    // RANGE (IN/OUT)  ___ TO ____ 
    // ORDER BY (DESC/ASC) <colname>
    const int BUFFER_SIZE = 1024;
    char instruction[BUFFER_SIZE] = "BUILD QUERY ";
    // char andInstruct[BUFFER_SIZE] = " AND";
    char order[BUFFER_SIZE] = " :ORDER BY ";
    char columns[BUFFER_SIZE] = " COLUMNS ";
    char input[BUFFER_SIZE];
    // choose tables to combine
    cout << "Enter Tables to query from(commas no space): " << endl; 
    cin.ignore(); 
    std::cin.getline(input, BUFFER_SIZE);
    strcat(instruction, input);
    input[0]='\0';
    // input.Clean();
    // choose filters
    bool cont = true;
    while(cont)
    {
        cout << "Create Query: " << endl; 
        cout << "1. Filter" << endl; 
        cout << "2. Range" << endl; 
        cout << "3. Continue" << endl; 
        cout << "Else Quit" << endl; 
        int option;
        cin >> option; 
        switch(option)
        {
            case 1: 
            // choose filters
                makeFilter(instruction);
                break;
            case 2: 
            // choose ranges
                makeRange(instruction);
                break;
            case 3: 
                continuationMenu(instruction);
                client->send_message(instruction, sizeof(instruction)+1);
                cont = false;
                break;
            default:
                cont = fals;
        }

    }
}

void jesterAPI::makeFilter(char (&instruc)[1024])
{
    const int BUFFER_SIZE = 1024;
    char filter[BUFFER_SIZE] = " :FILTER BY ";
    char eq[BUFFER_SIZE] = " == ";
    char notEq[BUFFER_SIZE] = " != ";
    char input1[BUFFER_SIZE];
    char input2[BUFFER_SIZE];
    char input3[BUFFER_SIZE];

    cout << "Enter Column " << endl; 
    cin.ignore(); 
    std::cin.getline(input1, BUFFER_SIZE);
    int option = 0;
    while(option != 1 && option != 2)
    {
        cout << "1. Equal"<<endl;
        cout << "2. Not Equals"<<endl;
        strcpy(input2, "");
        // cin.ignore();
        cin>>option;
        if(option == 1)
            strcat(input2, " == ");
        else if(option == 2)
            strcat(input2, " != ");
    }
     cout << "Enter Next Value (add '.' to the start if it its to a column) " << endl; 
    cin.ignore(); 
    std::cin.getline(input3, BUFFER_SIZE);
    strcat(instruc, filter);
    strcat(instruc, input1);
    strcat(instruc, input2);
    strcat(instruc, input3);

}

void jesterAPI::makeRange(char (&instruc)[1024])
{
    const int BUFFER_SIZE = 1024;

    char range[BUFFER_SIZE] = " :RANGE ";
    char to[BUFFER_SIZE] = " TO ";

    char input1[BUFFER_SIZE];
    char input2[BUFFER_SIZE];
    char input3[BUFFER_SIZE];
    char input4[BUFFER_SIZE];

    cout << "Enter Column " << endl; 
    cin.ignore(); 
    std::cin.getline(input1, BUFFER_SIZE);
    int option = 0;
    while(option != 1 && option != 2)
    {
        cout << "1. IN"<<endl;
        cout << "2. Not IN"<<endl;
        strcpy(input2, "");
        // cin.ignore();
        cin>>option;
        if(option == 1)
            strcat(input2, " WITHIN ");
        else if(option == 2)
            strcat(input2, " OUTSIDE ");
    }
    cout << "Enter Lower Bound " << endl; 
    cin.ignore(); 
    std::cin.getline(input3, BUFFER_SIZE);
    cout << "Enter Upper Bound " << endl; 
    cin.ignore(); 
    std::cin.getline(input4, BUFFER_SIZE);
    strcat(instruc, range);
    strcat(instruc, input1);
    strcat(instruc, input2);
    strcat(instruc, input3);
    strcat(instruc, to);
    strcat(instruc, input4);

}

void jesterAPI::continuationMenu(char (&instruc)[1024])
{
    makeOrder(instruc);
    keepColumns(instruc);
}

void jesterAPI::makeOrder(char (&instruc)[1024])
{
    const int BUFFER_SIZE = 1024;
    char order[BUFFER_SIZE] = " :ORDER BY ";
    char input1[BUFFER_SIZE];
    char input2[BUFFER_SIZE];

    cout << "Order By " << endl; 
    // cin.ignore(); 
    // std::cin.getline(input1, BUFFER_SIZE);
    int option = 0;
    while(option != 1 && option != 2)
    {
        cout << "1. Ascending"<<endl;
        cout << "2. Decending"<<endl;
        cout << "Else Do not reorder"<<endl;
        strcpy(input2, "");
        // cin.ignore();
        cin>>option;
        if(option == 1 || option == 2)
        {
            if(option == 1)
                strcat(input2, " ASCENDING");
            else
                strcat(input2, " DECENDING");

            cout << "Enter Column " << endl; 
            cin.ignore(); 
            std::cin.getline(input1, BUFFER_SIZE);
            strcat(instruc, order);
            strcat(instruc, input1);
            strcat(instruc, input2);
        }
    }
}

void jesterAPI::keepColumns(char (&instruc)[1024])
{
    const int BUFFER_SIZE = 1024;
    char keepColumns[BUFFER_SIZE] = " :SHOW COLUMNS ";
    char input1[BUFFER_SIZE];
    char input2[BUFFER_SIZE];

    cout << "Show Specific Columns: " << endl; 
    // cin.ignore(); 
    // std::cin.getline(input1, BUFFER_SIZE);
    int option = 0;
    while(option != 1 && option != 2)
    {
        cout << "1. Yes"<<endl;
        cout << "Else No"<<endl;
        strcpy(input2, "");
        // cin.ignore();
        cin>>option;
        if(option == 1)
        {
            cout << "Enter Columns(only comma seperation) " << endl; 
            cin.ignore(); 
            std::cin.getline(input1, BUFFER_SIZE);
            strcat(instruc, keepColumns);
            strcat(instruc, input1);
        }
    }

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