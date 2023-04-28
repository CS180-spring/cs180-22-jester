#include "server.h"
#include <iostream>
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read
#include <errno.h>  // For error diagnosis (errno)
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

int Server::setup_server() {
    /*
    Setups a socket and begins listening to it, until close(sockfd) is called

    Returns: sockfd on success, -1 on failure
    */


    // 1. Create an IPv4, TCP socket 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Failed to create socket, errno: " << errno << std::endl;
        return -1;
    }

    // 2. Assign address and port to socket 
    sockaddr.sin_family = AF_INET;          // IPv4 internet protocols
    sockaddr.sin_addr.s_addr = INADDR_ANY;  // On any address
    sockaddr.sin_port = htons(PORT);        // Listen to port 9999

    // 3. Bind socket
    int bind_result = bind(sockfd, (struct sockaddr*) &sockaddr, sizeof(sockaddr));
    if (bind_result == -1) {
        std::cerr << "Failure to bind to port " << PORT << ". errno: " << errno << std::endl;
        return -1;
    }
    cout << "Server bound to port: " << PORT << endl;

    // 4. Start listening to socket
    int listen_result = listen(sockfd, 10);
    if (listen_result == -1) {
        std::cerr << "Failure to listen to socket. errno: " << errno << std::endl;
        return -1;
    }

    return sockfd;
}

int Server::accept_connection() {
    /*
    Reads one connection in queue. A user must establish/request this connection before it can
        start querying Jester
    
    Returns: connectionfd[] index of accepted connection file descriptor on success, -1 on failure
    */

    // auto addrlen = sizeof(sockaddr);
    std::size_t addrlen = sizeof(sockaddr);
    int connection = accept(sockfd, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
    if (connection == -1) {
        std::cerr << "Failed to grab connection. errno: " << errno << std::endl;
        //exit(EXIT_FAILURE);
        return -1;
    }

    connectionfd.push_back(connection);
    return connectionfd.size()-1;
}

std::size_t Server::read_from(int c, char* buffer) {
    /*
    Reads up to BUFFER_LEN characters sent from connectionfd[c]

    Parameters:
        c: index of the file descriptor of the connection you want to read from
        buffer: c-string to load the message into (recommend string size of BUFFER_LEN)

    Returns: # of bytes read from connection
    */

   int connection = connectionfd[c];
   std::size_t bytesRead = read(connection, buffer, BUFFER_LEN);

   return bytesRead;
}

void Server::send_to(int c, std::string m) {
    /*
    Sends message m to connectionfd[c]
    */

   send(connectionfd[c], m.c_str(), m.size(), 0);
}

void Server::close_connection(int c)  {
    /*
    Closes connection with connectionfd[c]
    */

   close(connectionfd[c]); 
}

void Server::close_server() {
    /*
    Closes server socket
    */

   close(sockfd);
}

// Server::~Server() {
//     for (int i : connectionfd) {
//         this->close_connection(i);
//     }

//     this->close_server();
// }