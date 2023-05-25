#include <string> 
#include <vector> 
#include "../client.h"

using namespace std; 

class jesterAPI{
    public: 
        void interface(); 
    protected: 
        void buildDB();
        void deleteDB();  
        void modifyCell(); 
        void buildTable();
        void sendInstruction(); 
        void addRow(); 
        void deleteRow();
        void deleteCol();
        void deleteTable();  
        void printTable(); 
        void init(); //move both of these to private later 
        void close();  //this too
    private: 
        Client* client; 
        const int BUFFER_SIZE = 1024;
        char[] db_name; 
        // is there anything that's going to be here? 
}; 