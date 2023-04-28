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
    char test[10] = "hello!!!!";
    string input;

    cin >> input;

    cout << "Echoing: " << input << "and the test " << *test << "\n";

    // Sending the custom message to the server
    c.send_message(test);

    c.close_connection();

    // serverInput = input;
    
    // int CreateSocket = 0,n = 0;
    // char dataReceived[1024];
    // struct sockaddr_in ipOfServer;
 
    // memset(dataReceived, '0' ,sizeof(dataReceived));
 
    // if((CreateSocket = socket(AF_INET, SOCK_STREAM, 0))< 0)
    // {
    //     printf("Socket not created \n");
    //     return 1;
    // }
 
    // ipOfServer.sin_family = AF_INET;
    // ipOfServer.sin_port = htons(9998); // Current Port used is 9998
    // // The ip obtained using the command ip addr on terminal
    // ipOfServer.sin_addr.s_addr = inet_addr("169.235.30.120"); 
 
    // if(connect(CreateSocket, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer))<0)
    // {
    //     printf("Connection failed due to port and ip problems\n");
    //     return 1;
    // }
    // write(CreateSocket, "This is a test", sizeof("This is a test"));
 
    
    // while((n = read(CreateSocket, dataReceived, sizeof(dataReceived)-1)) > 0)
    // {
    //     dataReceived[n] = 0;
    //     if(fputs(dataReceived, stdout) == EOF)
    //     {
    //         printf("\nStandard output error");
    //     }
 
    //     printf("\n");
    // }
 
    // if( n < 0)
    // {
    //     printf("Standard input error \n");
    // }
 
    // return 0;
}