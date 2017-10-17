//
// Created by crypt on 17/10/17.
//

#include "gtest/gtest.h"
#include "iostream"

TEST(SYSTEM, STARTUP) {
    std::cout << "STARTUP" << std::endl;
    EXPECT_EQ(1,1);
}

TEST(SYSTEM, SECOND) {
    std::cout << "SECOND" << std::endl;
    EXPECT_NE(2,1);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}