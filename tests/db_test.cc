#include <gtest/gtest.h> 
#include "../datastruct/database.h"
#include "../datastuct/table.h"
#include <cstdlib> 
#include <vector>
#include <string>  
using namespace std; 

vector<string> testVec; 
testVec.push_back("col1"); 
testVec.push_back("col2"); 

TEST(dbtest, objectinstantiation){
    try { //creation for database 
        Database test = new Database("test"); 
        EXPECT_NE(nullptr, test); 
    } catch(...){
        cout << "db object instantiation err" << endl; 
    }
}

Database db = new Database("test2"); //will be used reoccuringly throughout remaining tests for db 

TEST(dbtest, nullPtrGetTable){ //should return null since no tables 
    EXPECT_EQ(db.getTable("test"), nullptr); 
}

TEST(dbtest, createTablev1){
    try{ //checks for create table basic functionality 
        db.createTable("testtable", 2, testVec); 
    } catch(...){
        cout << "Err. See above" << endl; 
    }

}

TEST(dbtest, createTablev1error){
    testVec.push_back("col3"); //num columns and vector not matching 
    try{
        db.createTable("testtable2", 2, testVec);
    } catch(...){
        cout << "err. see above" << endl;  
    }

}

TEST(dbtest, createTablev2){
    try{
        db.createTable("testtable3", 1); 
    } catch(const std::exception& e){
        cout << e.what() << endl; 
    }
}

TEST(dbtest, getTable){
    try{
        Table* testing = db.getTable("testtable3"); 
    } catch(const std::exception& e){
        cout << e.what() << endl; 
    }
}