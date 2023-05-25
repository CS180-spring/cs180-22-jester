
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string>

const int PORT = 8080;
const int BUFFER_LEN = 1024;
class Client {
    private:
        int sockfd;
        int CreateSocket = 0;
        
        // Current size for recieved message is 1024 but could be changed
        char recievedMessage [BUFFER_LEN];
        const char * quit = "QUIT";
        int messageSize = 0; //n from the reference for read()
        sockaddr_in ipOfServer;
        int getBufferLen(char*);

    public:
        void setup_client();
        void connect_to_server();
        void send_message(char *, std::size_t);
        std::string recieved_to_string(char *);
        char* read_from_server();
        void close_connection();

};