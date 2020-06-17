#ifndef _TEST_HPP
#define _TEST_HPP

#include "gtest/gtest.h"
#include "Ceil.hpp"
#include "Floor.hpp"
#include "op.hpp"
#include "Abs.hpp"
#include "mult.hpp"
#include "Sub.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "trunc.hpp"
#include "paren.hpp"
#include <iostream>

TEST(CeilTest, TestOne){

    Op* first = new Op(18.8);
     Ceil* test = new Ceil(first);
     EXPECT_EQ(test->evaluate(), 19);
}

TEST(CeilTest, TestTwoNegative){

Op* first = new Op(-1.8);
Ceil* test = new Ceil(first);
EXPECT_EQ(test->evaluate(), -1);
}

TEST(CeilTest, TestThreeZero){

  Op* first = new Op(0);
  Ceil* test = new Ceil(first);
  EXPECT_EQ(test->evaluate(), 0);
}
TEST(FloorTest, TestOne){

Op* first = new Op(45.3);
Floor* test = new Floor(first);
EXPECT_EQ(test->evaluate(), 45);
}

TEST(FloorTest, TestTwoNegative){

Op* first = new Op(-5.8);
Floor* test = new Floor(first);
EXPECT_EQ(test->evaluate(),-6);
}

TEST(AbsTest, TestOne){

Op* first = new Op(59.3);
Abs* test = new Abs(first);
EXPECT_EQ(test->evaluate(), 59.3);
}

TEST(AbsTest, TestNegative){
Op* first = new Op(-123);
Abs* test = new Abs(first);
EXPECT_EQ(test->evaluate(), 123);
}

TEST(CeilandFloor, TestOne){

Op* first = new Op(89.1);
Op* second = new Op(22.5);
Ceil* test = new Ceil(first);
Add* test2 = new Add(test, second);
Floor* test3 = new Floor(test2);
EXPECT_EQ(test3->evaluate(), 112);
}

TEST(CeilandFloor, TestTwo){
Op* first = new Op(15.1);
Op* second = new Op(5.2);
Floor* test = new Floor(second);
Mult* test2 = new Mult(first, test);
Ceil* test3 = new Ceil(test2);
EXPECT_EQ(test3->evaluate(), 76);
}

TEST(CeilandAbs, TestOne){
Op* first = new  Op(-32.9);
Op* second = new  Op(-2);
Ceil* test = new Ceil(second);
Sub* test2 = new Sub(first, test);
Abs* test3 = new Abs(test2);
EXPECT_EQ(test3->evaluate(), 30.9);
}


TEST(CeilandAbs, TestTwo){
Op* first = new Op(12.2);
Op* second = new Op(-4);
Abs* test = new Abs(second);
Div* test2 = new Div(first, test);
Ceil* test3 = new Ceil(test2);
EXPECT_EQ(test3->evaluate(), 4);
}

TEST(FloorandAbs, TestOne){
Op* first = new  Op(-132.1);
Op* second = new  Op(-22);
Floor* test = new Floor(second);
Add* test2 = new Add(first, test);
Abs* test3 = new Abs(test2);
EXPECT_EQ(test3->evaluate(), 154.1);
}


TEST(FloorandAbs, TestTwo){
Op* first = new Op(75.1);
Op* second = new Op(-15);
Abs* test = new Abs(second);
Mult* test2 = new Mult(first, test);
Floor* test3 = new Floor(test2);
EXPECT_EQ(test3->evaluate(), 1126);
}

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
TEST(TruncandParen, ThreeOperationsComboSep) {
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

TEST(TruncandParen, FourOperationsTruncInParen) {
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

TEST(Combination, TruncWithFloor){
Op* first = new Op(13.2);
Op* second = new Op(15.9);
Op* third = new Op(2);
Sub* sub = new Sub(second, first);
Floor* floor = new Floor(sub);
Trunc* trunc = new Trunc(floor);
Add* test = new Add(third, trunc);
EXPECT_EQ(test->stringify(), "2.000000 + 2.000000");
}

TEST(Combination, TrucnWithAbs){
Op* first = new Op(-10);
Op* second = new Op(13.5);
Abs* test = new Abs(second);
Add* test2 = new Add(first, test);
Trunc* test3 = new Trunc(test2);
EXPECT_EQ(test3->stringify(),std::to_string(test2->evaluate()));
}

TEST(Combination, CeilWithTruncAndParen){
Op* first = new Op (-2);
Op* second = new Op (14.5);
Op* third = new Op(5);
Ceil* ceil = new Ceil(second);
Add* add = new Add(first, ceil);
Trunc* trunc = new Trunc(add);
Add* add2 = new Add(trunc, third);
Paren* test = new Paren(add2);
EXPECT_EQ(test->stringify(), "(13.000000 + 5.000000)");
}


#endif

