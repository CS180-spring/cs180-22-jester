#include <gtest/gtest.h> 
#include <vector> 
#include <string> 
#include <cstdlib> 
#include "../datastruct/table.h"
#include "../datastruct/table.cpp"
using namespace std; 


TEST(tabletest, tableInstantiation){
    Table* objtest = new Table();
    EXPECT_NE(nullptr, objtest); 
}




TEST(tabletest, tableInstantiationWithCols){
    vector<string> columnNames{"col1", "col2"}; 
    EXPECT_NO_THROW({
        Table* test = new Table("testingTable", 2, columnNames); 
    }); 
}

TEST(tabletest, getnameofcols){
    vector<string> columnNames{"col1", "col2"};
    Table* secondary = new Table("test", 2, columnNames);
    vector<string> testrescols = secondary->g_name_of_cols(); 
    EXPECT_EQ(testrescols, columnNames); 
}

TEST(tabletest, incorrectInstantiation){
    vector<string> columnNames{"col1", "col2"};
    EXPECT_ANY_THROW({ //expected behavior: throw an error 
        Table* test3 = new Table("testingTable2", 3, columnNames); 
    }); 
}

TEST(tabletest, addrow){
    vector<string>columnNames{"col1", "col2"}; 
    Table* secondary = new Table("test", 2, columnNames);
    vector<string>testRow{"r1", "r2"};  
    EXPECT_NO_THROW({
        secondary->add_row(testRow); 
    }); 
}

TEST(tabletest, addRowErr){
    vector<string>columnNames{"col1", "col2"}; 
    Table* secondary = new Table("test", 2, columnNames);
    vector<string>testRow{"r1", "r2", "r3"};  
    EXPECT_ANY_THROW({
        secondary->add_row(testRow); 
    }); 
}

TEST(tabletest, gettable){
    vector<string>columnNames{"col1", "col2"}; 
    Table* secondary = new Table("test", 2, columnNames);
    vector<string>testRow{"r1", "r2", "r3"};
    vector<vector<string> > testTable; 
    testTable.push_back(testRow); 
    vector<vector<string> >testResTable = secondary->g_allData(); 
    EXPECT_EQ(testResTable, testTable); 
}

//not sure how to test print functions yet