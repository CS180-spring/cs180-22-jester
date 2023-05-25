#include "server.h"
#include <iostream>
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read
#include <errno.h>  // For error diagnosis (errno)

#include "./datastruct/database.h"
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

Server::~Server() {
    for (int fd : connectionfd) {
        close_connection(fd);
    }

    close_server();
}

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
    Reads up to BUFFER_LEN characters recieved from the file descriptor referenced by connectionfd[c]

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


std::vector<std::string> Server::word_tokenize(const char * inp, const char delim = ' ') {
    /*
    Seperates a char* (i.e. a string) inp and returns a vector of it's words 
    */
    std::vector<std::string> words = {};

    std::string w = "";
    char c;
    for (auto it = inp; *it != '\0'; it++) {
        c = *it;
        if (c != delim) { // Build a word, one char at a time
            w += c;
        }
        else {  // Ignore and reset on whitespaces
            words.push_back(w);
            w = "";
        }
    }

    // Push final word
    words.push_back(w);

    return words;
}

std::string Server::join_words(std::vector<std::string> m) {
    std::string s = "";
    for (size_t i = 0; i < m.size()-1; i++) {
        s += m.at(i);
        s += " ";
    }
    s += m.at(m.size()-1);

    return s;
}

// void Server::execute(std::vector<std::string> m) {
void Server::execute(char * message) {
    std::vector<std::string> m = word_tokenize(message, ' ');

    if (m.at(0) == "BUILD") {
        if (m.at(1) == "DB" && m.size() == 3) {
            std::string name = m.at(2);
            initDB(name);
            cout << "Building database with name: " << name << endl;
            return;
        }
        if (m.at(1) == "TABLE" && m.at(3) == "WITH" && m.size() == 5) {
            std::string name = m.at(2);
            // int num_cols = stoi(m.at(4));
            std::string field_names = m.at(4);
            // grab individual field names by Server.word_tokenize(field_names, ',')
            // cout << "Building table with name: " << name << " and " << "columns that have the names: " << field_names; 
            std::vector<std::string> columns = word_tokenize(field_names.c_str(), ',');
            getDB()->createTable(name, columns.size(), columns);
            // getDB()->getTable(name)->print_all_data();
            return;
        }
    }
    else if (m.at(0) == "GET")
    {
        if (m.at(2) == "COLUMNS")
        {
            cout<<"Columns of table '"<<m.at(1)<<"': "<<endl;
            if(!tableExists(m.at(1)))
            {
                return;
            }

            getDB()->getTable(m.at(1))->print_col_names();
        }
    }
    else if (m.at(0) == "VIEW")
    {
        if (m.at(1) == "TABLE")
        {
            if(!tableExists(m.at(2)))
            {
                return;
            }
            getDB()->getTable(m.at(2))->print_all_data();
        }
    }
    else if (m.at(0) == "FROM")
    {
        if (m.at(2) == "ADD")
        {
            std::string row = m.at(3);
            std::vector<std::string> newRow = word_tokenize(row.c_str(), ',');
            if(!tableExists(m.at(1)))
            {
                return;
            }
            getDB()->getTable(m.at(1))->add_row(newRow);
        }
    }
}

bool Server::tableExists(string tableName)
{
    if(getDB()->getTable(tableName) == nullptr)
    {
        // cout<<"ERROR: Table was not found"<<endl;
        cout<<"\033[1;31mERROR: \033[0m Table was not found"<<endl;
        return false;
    }
    return true;
}//end of check