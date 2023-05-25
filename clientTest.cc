#include <iostream>
#include <iomanip>
#include "client.cc"

using namespace std;


int main()
{

    Client c;

    // Initializing the client
    c.setup_client();

    // Connecting to the server
    c.connect_to_server();

    // Setting up the variables for input
    
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    char * response;
    
    //----------------------TESTING-----------------------------------

    FILE *fp;
    char * filename = "testSend.csv";

    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        perror("[-] Error in reading the file.");
        exit(1);
    }

    c.send_file(fp);
    printf("[+] The file was sent successfully");

    //----------------------TESTING-----------------------------------


    // Wait for the first input from the terminal
    // std::cout << "Enter the first message: ";
    // std::cin.getline(buffer, BUFFER_SIZE);

    // while(strcmp(buffer, "Q") != 0)
    // {
    //     // Sending the custom message to the server
    //     c.send_message(buffer, 0);

    //     // Get message back from the server
    //     response = c.read_from_server();
    //     // c.recieved_to_string(response);
    //     // std::cout << "Got the val\n";
    //     std::cout << "Recieved from server: " << c.recieved_to_string(response) << std::endl;

    //     std::cout << "Please enter more messges or type Q to exit: ";
    //     std::cin.getline(buffer, BUFFER_SIZE);
    // }

    c.close_connection();

}