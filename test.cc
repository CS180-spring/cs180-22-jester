#include<iostream>
#include "./server.h"
#include <regex>
using namespace std;


/*

- Builds executable that will setup the server and except ONLY one (1) connection. 
- Send any message containing 'QUIT' to close connection and server

*/


int main() {
    Server myServer;
    char buffer[100];
    

    // Setup server, accept connection from client, and read first message 
    myServer.setup_server();
    int connection = myServer.accept_connection();
    size_t messageSize = myServer.read_from(connection, buffer);
    string response;    // Declare response string

    // Send/recieve loop
    while (string(buffer).find("QUIT") == string::npos) {
        cout << "The message was: " << string(buffer) << endl;

        response = "This is a response\n";
        myServer.send_to(connection, response);
        
        messageSize = myServer.read_from(connection, buffer);
    }


    // Clean up
    myServer.close_connection(connection);
    myServer.close_server();

    return 0;
}