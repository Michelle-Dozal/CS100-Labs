#ifndef _TEST_HPP
#define _TEST_HPP

#include "gtest/gtest.h"
/*
#include "base.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Ceil.hpp"*/
#include <iostream>

TEST(IteratorTest, TestOne){
	int count = 0;
        Op* first = new Op(18);
	Op* second = new Op(10);
 	Mult* mult = new Mult(first,second);

	Iterator *it = mult->create_iterator();
	it->first();	
	while(!it->is_done())
	{
		Base* phase = it->current();
		count++;
		it->next();
	}
        EXPECT_EQ(2, count);
}

TEST(iteratorTest, BinarywithAdd){
int count = 0;
Base* one = new Op(18);
Base* two = new Op(10);
Add* temp = new Add(one, two);

Iterator* it = temp->create_iterator();
while(!it->is_done()){
 Base* phase = it->current();
count++;
it->next();}

EXPECT_EQ(2, count);
}

TEST(iteratorTest, UnarywithCeil){
int count = 0;
Base* one = new Op(10);
Ceil* ceil = new Ceil(one);
Iterator* it = ceil->create_iterator();
while(!it->is_done()){
Base* phase = it->current();
count++;
it->next();}
EXPECT_EQ(1, count);
}

TEST(iteratorTest, NullwithOp){
int count = 0;
Base* one = new Op(5);
Iterator* it = one->create_iterator();
while(!it->is_done()){
Base* phase = it->current();
count++;
it->next();}
EXPECT_EQ(NULL, count);
}


#endif

