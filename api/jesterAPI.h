#include <string> 
#include <vector> 
#include "../client.h"

using namespace std; 

class jesterAPI{
    public: 
        void init(); //move both of these to private later 
        void close();  //this too
        void interface(); 
        void buildDB();
        void deleteDB();  
        void modifyCell(); 
        void buildTable();
        void createQuery();
        void addRow(); 
        void deleteRow();
        void deleteCol();
        void deleteTable();  
        void printTable(); 
        
        void sendInstruction(); 
    private: 
        
        Client* client; 
        // is there anything that's going to be here? 
}; 