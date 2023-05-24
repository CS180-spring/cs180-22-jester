// Reference link: https://www.thecrazyprogrammer.com/2017/06/socket-programming.html

#include "client.h"


int Client::getBufferLen(char * buffer) 
{
/*
    Gets the current length of the input char array obtained from the terminal

    Parameters:
        buffer: The char array (pointer) containing the input message

    Returns: (count) # of characters present in the input array 

*/
   int count = 0;
   for (char * p = buffer; *p != '\0'; ++p) {
        // std::cout << *p;
        count++;
   }
//    std::cout << std::endl;

   return count;
}

void Client::setup_client()
{
/*
    Setting up the client side socket and assigning the createSocket value 
*/
    memset(recievedMessage, '0' ,sizeof(recievedMessage));
 
    if((CreateSocket = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("Error: Socket Initialization \n");

        // return 1;
    }
}

void Client::connect_to_server()
{
/*
    Collects the socket's return value and sets up our connection with the running server
*/
     ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_port = htons(PORT); // Current Port used is 8080
    // The ip obtained using the command ip addr on terminal
    ipOfServer.sin_addr.s_addr = inet_addr("169.235.30.120"); 
 
    if(connect(CreateSocket, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer))<0)
    {
        printf("Connection failed due to port and ip problems\n");
        return; // Exit from function
        // exit 2;
    }
}

void Client::send_message(char * input, std::size_t input_len)
{
    /*
        Sends the message collected from the client's input

        Parameters:
            input = the char array that is collected
            input_len = the size variable that is supposed to store the current len of input
                        (not to be confused with the capacity of input)
    */
    input_len = getBufferLen(input);
    input[input_len] = '\0';
    input_len += 1; 
    printf("This is our current input: %s and it's size: %d \n", input, input_len);
    write(CreateSocket, input, input_len);
}

char* Client::read_from_server()
{
    /*
        Reads any response sent over by the server

        Returns: The message recieved from the server (recievedMessage)
    */
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
    /*
        Similar to send_message but hard-coded to QUIT to end the connection
    */
    write(CreateSocket, quit, sizeof(quit));
}

std::string Client::recieved_to_string(char * message) 
{
    char * temp = message;
    std::string ret = "";
    for (char *  it = temp; *it != '\0'; ++it) {
        ret += *it;
    }

    return ret;
}
