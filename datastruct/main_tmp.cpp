#include "database.h"
#include "table.h"
#include <vector>
using namespace std;
    
int main()
{
    Database* db = new Database("mydb");

    vector<string> test1 {"name","age","desc"};
    db->createTable("Teammate", 3, test1);

    vector<string> test2 {"edgar","24","test"};
    vector<string> test3 {"luis","21","test"};
    vector<string> test4 {"owen","23","test"};
    // vector<string> test {"owen","23","test"};
    vector<string> test5 {"owen","23"};
    vector<string> test6 {"owen","23", "", ""};
    
    db->getTable("Teammate")->add_row(test2);
    db->getTable("Teammate")->add_row(test3);
    db->getTable("Teammate")->add_row(test4);

    db->getTable("Teammate")->add_row(test5);
    db->getTable("Teammate")->add_row(test6);

    db->getTable("Teammate")->print_all_data();
}