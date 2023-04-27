#include "gtest/gtest.h"
#include "db_test.hpp"
#include <iostream>
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}