#include <netinet/in.h> // For sockaddr_in
#include <vector>
#include <string>
#include "./datastruct/database.h"
// #include "./datastruct/table.h"

const int PORT = 8080;
const int BUFFER_LEN = 1024;
class Server {
    private:
        int sockfd;
        sockaddr_in sockaddr;
        std::vector<int> connectionfd;
        std::vector<sockaddr_in> connection_addr;   // Not sure if we'll need this? Dont think so
        Database* db; 

        bool tableExists(string);

    public:


        ~Server();
        int setup_server();
        int accept_connection();
        std::size_t read_from(int, char*);
        void send_to(int, std::string);
        void close_connection(int);
        void close_server();
        std::vector<std::string> word_tokenize(const char *, const char);
        std::string join_words(std::vector<std::string>);


        // void execute(std::vector<std::string>);
        void execute(char*);
        
        Database* getDB() {return db; }
        void initDB(string s) {db = new Database(s);}
};