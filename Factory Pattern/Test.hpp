#ifndef _TEST_HPP
#define _TEST_HPP

#include "gtest/gtest.h"
#include "factory.hpp"

#include <iostream>


TEST(AddTest, TestOne){
char* test_val[3]; test_val[0] = "8"; test_val[1] = "+"; test_val[2] = "2";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->stringify(), "8.000000 + 2.000000");
}

TEST(AddTest, TestTwo){
char* test_val[3]; test_val[0] = "3"; test_val[1] = "+"; test_val[2] = "5";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->evaluate(), 8);
}

TEST(SubTest, TestOne){
char* test_val[3]; test_val[0] = "12";  test_val[1] = "-"; test_val[2] = "4";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->stringify(), "12.000000 - 4.000000");
}

TEST(SubTest, TestTwo){
char* test_val[3]; test_val[0] = "5"; test_val[1] = "-"; test_val[2] = "2";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->evaluate(), 3);
}

TEST(MultTest, TestOne){
char* test_val[3]; test_val[0] = "10"; test_val[1] = "*"; test_val[2] = "10";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->stringify(), "10.000000 * 10.000000");
}

TEST(MultTest, TestTwo){
char* test_val[3]; test_val[0] = "12"; test_val[1] = "*"; test_val[2] = "2";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->evaluate(), 24);
}

TEST(DivTest, TestOne){
char* test_val[3]; test_val[0] = "20"; test_val[1] = "/"; test_val[2] = "5";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->stringify(), "20.000000 / 5.000000");
}

TEST(DivTest, TestTwo){
char* test_val[3]; test_val[0] = "15"; test_val[1] = "/"; test_val[2] = "3";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->evaluate(), 5);
}

TEST(PowTest, TestOne){
char* test_val[3]; test_val[0] = "2"; test_val[1] = "^"; test_val[2] = "3";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->stringify(), "2.000000 ** 3.000000");
}

TEST(PowTest, TestTwo){
char* test_val[3]; test_val[0] = "3"; test_val[1] = "^"; test_val[2] = "5";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 3);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->evaluate(), 243);
}

TEST(Combination, AddandSub){
char* test_val[5]; test_val[0] = "1"; test_val[1] = "+"; test_val[2] = "2"; test_val[3] = "-"; test_val[4] = "3";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 5);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->stringify(), "1.000000 + 2.000000 - 3.000000");
}

TEST(Combination, MultandDiv){
char* test_val[5]; test_val[0] = "10"; test_val[1] = "*"; test_val[2] = "2"; test_val[3] = "/"; test_val[4] = "4";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 5);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->evaluate(), 5);
}

TEST(Combination, PowandMultandSub){
char* test_val[7]; test_val[0] = "2"; test_val[1] = "^"; test_val[2] = "3"; test_val[3] = "*"; test_val[4] = "4"; test_val[5] = "-"; test_val[6] = "3";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 7);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->stringify(), "2.000000 ** 3.000000 * 4.000000 - 3.000000");
}

TEST(Combination, AddandDivandPow){
char* test_val[7]; test_val[0] = "8"; test_val[1] = "+"; test_val[2] = "10"; test_val[3] = "/"; test_val[4] = "4"; test_val[5] = "^"; test_val[6] = "2";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 7);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->evaluate(), 20.250000);
}

TEST(Combination, AddandSubandMultandDiv){
char* test_val[9]; test_val[0] = "4"; test_val[1] = "+"; test_val[2] = "2"; test_val[3] = "-"; test_val[4] = "7"; test_val[5] = "*"; test_val[6] = "5"; test_val[7] = "/"; test_val[8] = "1";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val, 9);
ASSERT_NE(conversion, nullptr);
EXPECT_EQ(conversion->stringify(), "4.000000 + 2.000000 - 7.000000 * 5.000000 / 1.000000");
}

TEST(Invalidinput,ThrowsNull){
char* test_val[3]; test_val[0] = "1"; test_val[1] = "&"; test_val[2] = "2";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val,3);
EXPECT_NE(conversion, nullptr);
}

TEST(Invalidinput,ThrowsNullTestTwo){
char* test_val[3]; test_val[0] = "5"; test_val[1] = "+-"; test_val[2] = "2";
Factory* factory = new Factory();
Base* conversion = factory->parse(test_val,3);
EXPECT_NE(conversion, nullptr);
}

#endif
