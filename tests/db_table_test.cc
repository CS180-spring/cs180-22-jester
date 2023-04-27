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
    EXPECT_NO_THROW({ //checks for create table basic functionality 
        db.createTable("testtable", 2, testVec); 
    }); 
}

TEST(dbtest, createTablev1error){
    testVec.push_back("col3"); //num columns and vector not matching 
    EXPECT_ANY_THROW({
        db.createTable("testtable2", 2, testVec);
    }); 

}

TEST(dbtest, createTablev2){
    EXPECT_NO_THROW({
        db.createTable("testtable3", 1); 
    });
}

TEST(dbtest, getTable){
    EXPECT_NO_THROW({
        Table* testing = db.getTable("testtable3"); 
        //come back to later - check for equality with instantiated table - int testing for llater
    }); 
}


TEST(tabletest, tableInstantiation){
    Table* objtest = new Table();
    EXPECT_NE(nullptr, objtest); 
}


//have to run seperately for command line input? check here for ref: https://github.com/google/googletest/issues/765
//
vector<string> columnNames; 
test2.push_back("col1"); 
test2.push_back("col2"); 
vector<string> testRow; 
testRow.push_back("row1");
testRow.push_back("row2"); 
vector<string> errTestRow; 
errTestRow.push_back("row1"); 

vector<vector<string> > testTable; 
testTable[0].push_back(testRow); 

Table* secondary = new Table("test", 2, columnNames);
TEST(tabletest, tableInstantiationWithCols){
    EXPECT_NO_THROW({
        Table* test = new Table("testingTable", 2, columnNames); 
    }); 
}

TEST(tabletest, getnameofcols){
    vector<string> testrescols = secondary->g_name_of_cols(); 
    EXPECT_EQ(testrescols, columnNames); 
}

TEST(tabletest, incorrectInstantiation){
    EXPECT_ANY_THROW({ //expected behavior: throw an error 
        Table* test3 = new Table("testingTable2", 3, columnNames); 
    }); 
}

TEST(tabletest, addrow){
    EXPECT_NO_THROW({
        secondary->add_row(testRow); 
    }); 
}

TEST(tabletest, addRowErr){
    EXPECT_ANY_THROW({
        secondary->add_row(errTestRow); 
    }); 
}

TEST(tabletest, gettable){
    vector<vector<string> >testResTable = secondary->g_allData(); 
    EXPECT_EQ(testResTable, testTable); 
}