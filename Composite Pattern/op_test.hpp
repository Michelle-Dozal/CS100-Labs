#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
	
}
TEST(OpTestDecimal, OpEvaluateNonZeroDecimal) {
    Op* test = new Op(1.2);
    EXPECT_EQ(test->evaluate(), 1.2);
	
}
TEST(OpTestString, OpEvaluateNonZeroString) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(),std::to_string(test->evaluate()));
	
}
TEST(OpTestDoubleDige, OpEvaluateNonZeroDoubleDig) {
    Op* test = new Op(1238);
    EXPECT_EQ(test->evaluate(),1238);
	
}


#endif //__OP_TEST_HPP__
