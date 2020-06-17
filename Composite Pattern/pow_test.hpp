#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include <iostream>
TEST(PowTest, PowEvaluateNonZero) {
    Op* base = new Op(2);
    Op* expo = new Op(4);
    Pow* test = new Pow(base, expo);
    EXPECT_EQ(test->evaluate(), 16);
}
TEST(PowTest3, PowWithMult) {
    Op* base = new Op(2);
    Op* expo = new Op(4);
    Mult* test2 = new Mult(base,expo);
    Pow* test = new Pow(test2, expo);
    EXPECT_EQ(test->evaluate(), 4096);
}

TEST(PowTest2, PowEvaluateNonZeroString) {
    Op* base = new Op(2);
    Op* expo = new Op(4);
    Pow* test = new Pow(base, expo);
    EXPECT_EQ(test->stringify(), base->stringify() + " ** " + expo->stringify());
}

#endif //__POW_TEST_HPP__
