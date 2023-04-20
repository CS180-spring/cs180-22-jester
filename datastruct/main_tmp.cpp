#include "database.h"
using namespace std;
    
int main()
{
    Database* db = new Database("mydb");
    db->createTable("Teammate", 3);
}