#include <netinet/in.h> // For sockaddr_in
#include <vector>
#include <string>

const int PORT = 8080;
const int BUFFER_LEN = 100;
class Server {
    private:
        int sockfd;
        sockaddr_in sockaddr;
        std::vector<int> connectionfd;
        std::vector<sockaddr_in> connection_addr;   // Not sure if we'll need this? Dont think so

    public:
        int setup_server();
        int accept_connection();
        std::size_t read_from(int, char*);
        void send_to(int, std::string);
        void close_connection(int);
        void close_server();
};