#ifndef _DIV_TEST_HPP
#define _DIV_TEST_HPP

#include "gtest/gtest.h"
#include "Div.hpp"
#include "op.hpp"
//#include "Add.hpp"

TEST (DivTest, DivisionValue){
	Op* first = new Op(8);
	Op* second = new Op(2);

	Div* test = new Div(first, second);
	EXPECT_EQ(test->evaluate(), 4);

}
/*
TEST(DivwAdd, Division&Addition){
Op* first = new Op(50);
Op* second = new Op(5);
Div* test2 = new Div(one,two);
Add* test = new Add(test2, second);
EXPECT_EQ(test->evaluate(), 15);
}*/
#endif //_DIV_TEST_HPP
