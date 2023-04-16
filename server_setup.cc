#include <iostream>
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read
using namespace std;


/*


int socket(int domain, int type, int protocol);
    * Opens a socket and returns its file descriptor, or -1 on failure
    * domain: refers to the protocol the socket will use for communication (use a constant) (connectionless or connection-oriented)
    * type: specifies if the communication will be connectionless or persistent (use a constant)
    * protocol: probabl a 0

int bind(int sockfd, const sockaddr *addr, socklen_t addrlen);
    * Assigns an IP address and port to a socket, returns 0 on success and -1 on failure
    * sockfd: fd returned from socket()
    * addr: a struct used to specify the IP address to assign to the socket (varies by protocol)
    * addrlen: size() of addr

int listen(int sockfd, int backlog);
    * Marks a socket as passive i.e. the socket will be used to accept connections, returns 0 on success and -1 on failure
    * sockfd: fd return from socket()
    * backlog: number of connections that will be queued before connections start being refused

int accept(int sockfd, sockaddr *addr, socklen_t *addrlen);
    * Extracts an element from a queue of connections, returns fd of connection on success and -1 on failure
    * sockfd and addr are the same as for bind()
    * addrlen: expects size(addr), returns the size of the peer (connection?) address

*/

struct sockaddr_in {
    sa_family_t     sin_family; // Address family: AF_INET
    in_port_t       sin_port;   // Port In's network byte order (big or little endian)
    struct in_addr  sin_addr;   // Internet address (IP?) 

    sockaddr_in(sa_family_t sin_f, in_port_t sin_p, struct in_addr sin_add) {
        this->sin_family = sin_f;
        this->sin_port = sin_p;
        this->sin_addr = sin_add;
    }
}

int setup() {   // Setup server?
    // 1. Create and IPv4, TCP socket 
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        cerr << "Failed to create socket, errno: " << errno << endl;
        exit(EXIT_FAILURE);
    }

    // 2. Assign address and port to socket 
    sockaddr_in sockaddr(AF_INET, INADDR_ANY, htons(9999));

    // 3. Bind socket
    bind_result = bind(sockfd, (struct sockaddr_in*) &sockaddr, size(sockaddr));


    return -1
}

int main() {
    return 0;
}