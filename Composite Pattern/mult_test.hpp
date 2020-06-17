#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
TEST(MultTest, MultEvaluateNonZero) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Mult* test = new Mult(first,second);
    EXPECT_EQ(test->evaluate(), 56);
}
TEST(MultTest, MultAndPow) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Pow* test2 = new Pow(first,second);
    Mult* test = new Mult(first,test2);
    EXPECT_EQ(test->evaluate(), 16777216);
}

TEST(MultTestString, MultEvaluateNonZeroString) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Mult* test = new Mult(first, second);
    EXPECT_EQ(test->stringify(),first->stringify() + " * " + second->stringify());
}

#endif //__MULT_TEST_HPP__
