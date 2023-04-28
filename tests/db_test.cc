

#include <gtest/gtest.h> 
#include "../datastruct/database.h"
#include "../datastruct/table.h"
#include "../datastruct/table.cpp"
#include "../datastruct/database.cpp"
#include <cstdlib> 
#include <string> 
#include <vector>
using namespace std; 


TEST(dbtest, objectinstantiation){
    Database* test = new Database("test"); 
    EXPECT_NE(nullptr, test); 
}


TEST(dbtest, nullPtrGetTable){ //should return null since no tables 
    Database* db = new Database("test"); 
    EXPECT_EQ(db->getTable("test"), nullptr); 
}

TEST(dbtest, createTablev1){
    vector<string> testVec{"col1", "col2"};  
    Database *db = new Database("test"); 
    EXPECT_NO_THROW({ //checks for create table basic functionality 
        db->createTableWithCols("testtable", 2, testVec); 
    }); 
}

TEST(dbtest, createTablev1error){
    Database *db = new Database("test");
    vector<string> testVec{"col1", "col2", "col3"}; 
    testVec.push_back("col3"); //num columns and vector not matching 
    EXPECT_ANY_THROW({
        db->createTableWithCols("testtable2", 2, testVec);
    }); 
}

TEST(dbtest, createTablev2){
    Database *db = new Database("test");
    EXPECT_NO_THROW({
        db->createTable("testtable3", 1); 
    });
}

TEST(dbtest, getTable){ //int testing: built on the assumption that table is fully functional, at least for instantiation 
    Database *db = new Database("test");
    Table *test = new Table(); 
    EXPECT_NO_THROW({
        Table* testing = db->getTable("testtable3"); 
        //come back to later - check for equality with instantiated table - int testing for llater
    }); 
}

