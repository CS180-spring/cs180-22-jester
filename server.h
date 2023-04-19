#include <netinet/in.h> // For sockaddr_in
#include <vector>
#include <string>

class Server {
    private:
        const int PORT = 9999;
        const int BUFFER_LEN = 100;
        int sockfd;
        sockaddr_in sockaddr;
        std::vector<int> connectionfd;
        std::vector<sockaddr_in> connection_addr;   // Not sure if we'll need this? Dont think so


    public:
        int setup_server();
        int accept_connection();
        char* read_from(int);
        void send_to(int, std::string);
        void close_connection(int);
        void close_server();
};