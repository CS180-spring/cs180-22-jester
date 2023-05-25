#include<iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "./server.h"
#include "./datastruct/database.h"

using namespace std;


/*

- Builds executable that will setup the server and except ONLY one (1) connection. 
- Send any message containing 'QUIT' to close connection and server

*/


int main() {
    Server myServer;
    char buffer[BUFFER_LEN];

    // Setup server, accept connection from client, and read first message 
    myServer.setup_server();
    int connection = myServer.accept_connection();
    size_t messageSize = myServer.read_from(connection, buffer);
    string response;    // Declare response string

    // Send/recieve loop
    while (string(buffer).find("QUIT") == string::npos) {
        cout << "The message was: " << string(buffer) << endl;
        
        myServer.execute(buffer);

        /* HELPER FUNCTIONS PROOF OF CONCEPT
        // Tokenize word
        vector<string> message = myServer.word_tokenize(buffer, ' ');
        cout << "Tokenized word: " << endl;
        for (string w : message) {
            cout << w << endl;
        }

        // Rejoin word
        string mes = myServer.join_words(message);
        cout << "Rejoined message: " << mes << endl;
        /*

        //can be made into seperate function
        /*
        string temp = string(buffer);
        string createDB = "BUILD DB";
        if(temp.find(createDB)!= string::npos)
        {
            temp.erase(temp.find(createDB), createDB.size());
            cout<<"create db called: "<<temp<<endl;
            myServer.initDB(temp);
        }
        // BUILD TABLE <tableName> WITH <columns> <fields*>
        string createTable = "BUILD TABLE ";
        if(temp.find(createTable)!= string::npos)
        {
            string WITH = " WITH ";
            if(temp.find(WITH)!= string::npos)
            {
                cout<<"create table called correctly"<<endl;
                string tableName;
                vector<string> colNames;
                tableName = temp.substr(0, temp.find(WITH));
                temp.erase(0, temp.find(WITH) + WITH.size());
                
                // cout<<tableName;
                cout<<"."<<endl;

                while(temp.find(',') != string::npos)
                {
                    string t = temp.substr(0, temp.find(','));
                    boost::trim(t);
                    colNames.push_back(t);
                    cout<<t;
                    temp.erase(0, temp.find(',')+1);
                }
                boost::trim(temp);
                colNames.push_back(temp);
                cout<<temp;


                myServer.getDB()->createTable(tableName, colNames.size(), colNames);
                vector<string> dummyRow = {"one","two","three"};
                myServer.getDB()->getTable(tableName)->add_row(dummyRow);

                myServer.getDB()->getTable(tableName)->print_all_data();

            }
            

        }
        */
        response = "This is a response\n";
        myServer.send_to(connection, response.c_str());
        
        messageSize = myServer.read_from(connection, buffer);
        // std::cout << buffer << std::endl;
    }

    // Clean up
    myServer.close_connection(connection);
    myServer.close_server();

    return 0;
}