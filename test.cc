#include<iostream>
#include "./server.h"
using namespace std;

int main() {
    Server myServer;
    char buffer[100];
    
    myServer.setup_server();
    
    int connection = myServer.accept_connection();
    size_t messageSize = myServer.read_from(connection, buffer);

    cout << "The message was: " << buffer;

    string response = "This is a response\n";
    myServer.send_to(connection, response);

    myServer.close_connection(connection);
    myServer.close_server();

    return 0;
}