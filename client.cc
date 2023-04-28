// Reference link: https://www.thecrazyprogrammer.com/2017/06/socket-programming.html

#include "client.h"


void Client::setup_client()
{
    memset(recievedMessage, '0' ,sizeof(recievedMessage));
 
    if((CreateSocket = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("Error: Socket Initialization \n");
        // return 1;
        // exit 0;
    }
}


void Client::connect_to_server()
{
     ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_port = htons(9998); // Current Port used is 9998
    // The ip obtained using the command ip addr on terminal
    ipOfServer.sin_addr.s_addr = inet_addr("169.235.30.120"); 
 
    if(connect(CreateSocket, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer))<0)
    {
        printf("Connection failed due to port and ip problems\n");
        // return 1;
        // exit 2;
    }
}

void Client::send_message(char* input)
{
    write(CreateSocket, input, sizeof(input));
}

char* Client::read_from_server()
{
    if((messageSize = read(CreateSocket, recievedMessage, sizeof(recievedMessage)-1)) > 0)
    {
        recievedMessage[messageSize] = 0;
        if(fputs(recievedMessage, stdout) == EOF)
        {
            printf("\nStandard output error");
        }
 
        printf("\n");
    }
    
    return recievedMessage;
    
}


void Client::close_connection()
{
    write(CreateSocket, quit, sizeof(quit));
}

