#ifndef _SUB_TEST_HPP
#define _SUB_TEST_HPP
#include "op.hpp"
#include "Sub.hpp"
#include "gtest/gtest.h"
//#include "Add.hpp"

TEST(SubTest, Subtract) {
Op* one = new Op(9);
Op* two = new Op(3);

Sub* test = new Sub(one,two);
EXPECT_EQ(test->evaluate(),6);
}

TEST(SubTest2, EvaluateString){
Op* one = new Op(8);
Op* two = new Op(3);

Sub* test = new Sub(one, two);
EXPECT_EQ(test->stringify(), "8 - 3");
}
/*
TEST(SubTest, AddSub){
Op* one = new Op (10);
Op* two = new Op (3);

Sub* test = new Sub(one,two);
Add* test2 = new Add(one, test2);
EXPECT_EQ(test2->evaluate(),17); 
}
*/

#endif //_SUB_TEST_HPP
