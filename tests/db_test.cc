#include <gtest/gtest.h> 
#include "../datastruct/database.h"

TEST(dbtest, testingtestlol){
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}