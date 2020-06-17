#ifndef __TEST_STRING_HPP__
#define __TEST_STRING_HPP__

#include "gtest/gtest.h"

#include "trunc.hpp"
#include "paren.hpp"
#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
TEST(TruncTest, OneOp) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Mult* mult = new Mult(first,second);
    Trunc* test = new Trunc(mult);
   
    EXPECT_EQ(test->stringify(),std::to_string(mult->evaluate()));
}
TEST(TruncTest, TwoOperations) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Op* third = new Op(5);
    Mult* mult = new Mult(first,second);
    Trunc* test = new Trunc(mult);
    Add* add = new Add(third, test);

    EXPECT_EQ(add->stringify(), "5.000000 + " + std::to_string(mult->evaluate()));
}
TEST(ParenTest, NonZeroTwoOpEquation) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Op* third = new Op(5);
    Mult* mult = new Mult(first,second);
    Paren* test = new Paren(mult);
    Add* add = new Add(third,test);
	
    EXPECT_EQ(add->stringify(), third->stringify() + " + (" + mult->stringify() + ")" );
}
TEST(ComboTest, ThreeOperationsComboSep) {
    Op* ten = new Op(10);
    Op* seven = new Op(7);
    Op* five = new Op(5);
    Op* three = new Op(3);
    Mult* mult = new Mult(five,three);
    Sub* sub = new Sub(ten,seven);
    Trunc* trunc = new Trunc(mult);
    Paren* paren = new Paren(sub);
    Add* add = new Add(trunc, paren);
    EXPECT_EQ(add->stringify(), "15.000000 + (10.000000 - 7.000000)");
}
TEST(ComboTest, FourOperationsTruncInParen) {
    Op* ten = new Op(10);
    Op* seven = new Op(7);
    Op* five = new Op(5);
    Op* three = new Op(3);
    Op* two = new Op(2);

    Mult* mult = new Mult(five,three);
    Sub* sub = new Sub(ten,seven);
    
    Trunc* truncMult = new Trunc(mult);
    Trunc* truncSub = new Trunc(sub);
    Add* add = new Add(truncMult,truncSub);
    Paren* paren = new Paren(add);
    Add* addTwo = new Add(two, paren);
   
    EXPECT_EQ(addTwo->stringify(), "2.000000 + (15.000000 + 3.000000)");
}
#endif //__test_string_HPP__
