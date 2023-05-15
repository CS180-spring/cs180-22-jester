#include "jesterAPI.h"
#include <string> 
#include <vector> 

using namespace std; 
jesterAPI::init(){ 
//add server stuffs here 
    //call interface here? 
}
jesterAPI::close(){
    //server stuffs here 
    // owen haaaalp 
}

//no error handling for these bois 
jesterAPI::interface(){
    bool quit = false; 
    int option = -1; 
    string db = ""; 
    string tableName = ""; 
    cout << "Welcome to Jester's document store! See our list of options: " << endl; 
    while (!quit){
        cout << "1. Create your new database" << endl << "2. Delete your database" << endl << "3. Create a table" << "4. Delete a table" << endl; 
        cout << "5. Add a row to your table" << endl << "6. View your table" << endl << "7. Add a row to the table" << endl << 
        "8. Modify a cell in your table" << endl << "10. Quit" << endl;
        cout << "Please type a number for your option: " << endl; 
        cin >> option; 
        if (option == 1){
            cout << "Please enter the name of your database: " << endl; 
            cin >> db; 
            buildDB(db); 
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

        }
    }

}