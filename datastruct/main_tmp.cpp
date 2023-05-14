#include "database.h"
#include "schema.h"
#include "DataView.h"
#include <iostream>
#include "table.h"
#include <vector>
using namespace std;
    
int main()
{
    Database* db = new Database("mydb");

    // vector<string> test1 {"name","age","desc"};
    // db->createTable("Teammate", 3, test1);

    // vector<string> test2 {"edgar","24","test"};
    // vector<string> test3 {"luis","21","test"};
    // vector<string> test4 {"owen","23","test"};
    // // // vector<string> test {"owen","23","test"};
    // vector<string> test5 {"owen","23"};
    // vector<string> test6 {"owen","23", "", ""};
    
    // db->getTable("Teammate")->add_row(test2);
    // db->getTable("Teammate")->add_row(test3);
    // db->getTable("Teammate")->add_row(test4);

    // db->getTable("Teammate")->add_row(test5);
    // db->getTable("Teammate")->add_row(test6);

    // db->getTable("Teammate")->print_all_data();

    // cout<<"test test test"<<endl;
    db->createTableFromCSVFile("preMadeData/people_small.csv", "people");
    db->createTableFromCSVFile("preMadeData/organization_small.csv", "orgs");
    // db->getTable("people")->delete_row(998);
    // db->getTable("people")->delete_row(1);
    // cout<<"sdfs";
    // db->getTable("people")->print_all_data();
    // db->getTable("Teammate")->print_all_data();
    // Table* temp = db->getTable("people");
    // db->createView(temp->g_num_of_cols(), temp->g_name_of_cols(), temp->g_all_data());
    // cout<<"sdfs";
    DataView* dv = db->createView({"people", "orgs"});
    // DataView* dv = db->createView(db->getTable("people"));
    // cout<<"sdfs";
    // dv->filter(".Sex", "Female", true);
    // dv->filter(".First Name", "Eddie", true);
    // dv->filter(".First Namdfe", "Eddie", false);
    // dv->range(".Index", "1", "10", false);
    // dv->print_all_data();
    dv->delete_column(".Index");
    dv->delete_column(".User Id");
    dv->delete_column(".Date of birth");
    dv->delete_column(".Website");
    dv->delete_column(".Description");
    dv->delete_column(".Name");
    dv->print_all_data();
    // dv->range();
    // cout<<"sdfs";

    // db->create
}