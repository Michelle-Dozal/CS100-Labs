#ifndef _ADD_TEST_HPP
#define _ADD_TEST_HPP

#include "gtest/gtest.h"
#include "Add.hpp"
#include "op.hpp"

TEST (AddTest, AdditionValue){
    Op* first = new Op(3);
    Op*  second = new Op(2);
    Add* test = new Add(first,second);
	EXPECT_EQ(test->evaluate(), 5);
}
#endif //ADD_TEST_HPP
