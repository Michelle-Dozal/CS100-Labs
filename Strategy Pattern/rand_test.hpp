#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluateNonZero) {
    Rand* test = new Rand();
    EXPECT_FALSE(test->evaluate() == rand()%100 );
}
TEST(RandTestString, RandEvaluateNonZeroString) {
    Rand* test = new Rand();
    EXPECT_EQ(test->stringify(),std::to_string(test->evaluate() ));
}



#endif //__RAND_TEST_HPP__
