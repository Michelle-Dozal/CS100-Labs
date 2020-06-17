#ifndef _LISTCONTAINER_TEST_HPP_
#define _LISTCONTAINER_TEST_HPP_

#include "ListContainer.hpp"
#include <iostream>
#include "op.hpp"
TEST(ListContainer, swapTest){

        Op* five = new Op(5);
ListContainer* test_container = new ListContainer();
test_container->add_element(five);

ASSERT_EQ(test_container->size(), 1);
EXPECT_EQ(test_container->at(0)->evaluate(), 5);

}


TEST(ListContainer, checkforswap){
Op* seven = new Op(7);
Op* ten = new Op(10);
Op* four = new Op(4);

ListContainer* test_forswap = new ListContainer();
test_forswap->add_element(seven);
test_forswap->add_element(ten);
test_forswap->add_element(four);
test_forswap->swap(0,2);

ASSERT_EQ(test_forswap->size(), 3);
EXPECT_EQ(test_forswap->at(0)->evaluate(),4);
EXPECT_EQ(test_forswap->at(2)->evaluate(), 7);
}
TEST(ListContainer, emptycontainer){

ListContainer* test_empty = new ListContainer();
ASSERT_EQ(test_empty->size(), 0);
}


#endif //_LISTCONTAINER_TEST_HPP_
