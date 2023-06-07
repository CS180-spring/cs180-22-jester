#include <string> 
#include <sstream>
#include <vector> 
#include <stack>
#include <boost/lexical_cast.hpp>
#include <netdb.h>
#include <arpa/inet.h>
#include "../client.h"

using namespace std; 

class jesterAPI{
    public: 
        void interface(); 
        void init(); //move both of these to private later 
        // FILE *fp;
        void close();  //this too
    protected: 
        void buildDB();
        void deleteDB();  
        void modifyCell(); 
        void buildTable();
        void sendInstruction(); 
        void createQuery();
        void addRow(); 
        void deleteRow();
        void deleteCol();
        void deleteTable();  
        void printTable(); 
        void createTableFromCSV(); 

        void makeFilter(char (&instruc)[1024]);
        void makeRange(char (&instruc)[1024]);
        void makeOrder(char (&instruc)[1024]);
        void continuationMenu(char (&instruc)[1024]);
        void keepColumns(char (&instruc)[1024]);
    private: 
        Client* client; 
        const int BUFFER_SIZE = 1024;
        // char[] db_name; 
        // is there anything that's going to be here? 
}; 