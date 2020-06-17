#ifndef _VISIT_TEST_HPP
#define _VISIT_TEST_HPP

#include "gtest/gtest.h"
#include <iostream>
#include "base.hpp"
#include "Abs.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Div.hpp"
#include "pow.hpp"
#include "decorator.hpp"
#include "Ceil.hpp"
#include "Floor.hpp"
#include <iostream>
#include "visitor.hpp"
TEST(VisitorTest, Test1){
	CountVisitor *visitor = new CountVisitor();
        Op* first = new Op(18);
	Op* second = new Op(10);
	
	first->accept(visitor);
	second->accept(visitor);
 	
	Mult* mult = new Mult(first,second);
	Sub* sub = new Sub(first,second);
	
	mult->accept(visitor);
	sub->accept(visitor);
	
	EXPECT_EQ(visitor->op_count(),2);
	EXPECT_EQ(visitor->sub_count(),1);
	EXPECT_EQ(visitor->mult_count(),1);
}

TEST(VisitorTest, Test2){
	CountVisitor *visitor = new CountVisitor();
        Op* first = new Op(5);
	Op* second = new Op(16);
	
	first->accept(visitor);
	second->accept(visitor);
 	
	Add* add = new Add(first,second);
	Div* div = new Div(first,second);
	
	add->accept(visitor);
	div->accept(visitor);
	
	EXPECT_EQ(visitor->op_count(),2);
	EXPECT_EQ(visitor->add_count(),1);
	EXPECT_EQ(visitor->div_count(),1);
}

TEST(VisitorTest, Test3){
	CountVisitor *visitor = new CountVisitor();
        Op* first = new Op(12);
	Op* second = new Op(1);
	
	first->accept(visitor);
	second->accept(visitor);
 	
	Pow* pow = new Pow(first,second);
	
	pow->accept(visitor);
	
	EXPECT_EQ(visitor->op_count(),2);
	EXPECT_EQ(visitor->pow_count(),1);
}

TEST(VisitorTest, Test4){
        CountVisitor *visitor = new CountVisitor();
        Op* first = new Op(22);
        Op* second = new Op(15);
        Op* third = new Op(4);


        first->accept(visitor);
        second->accept(visitor);
        third->accept(visitor);

        Mult* mult = new Mult(first,second);
        Sub* sub = new Sub(mult, third);

        mult->accept(visitor);
        sub->accept(visitor);

         EXPECT_EQ(visitor->op_count(),3);
        EXPECT_EQ(visitor->mult_count(),1);
        EXPECT_EQ(visitor->sub_count(),1);
}

TEST(VisitorTest, Test5){
Op* first = new Op(22);
Op* second = new Op(5);
Add* temp = new Add(first,second);
Decorator* dummy = new Ceil(temp);

Iterator *it = new PreorderIterator(dummy);
CountVisitor *visit = new CountVisitor();
it->first();
while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
}
                EXPECT_EQ(visit->op_count(), 2);
                EXPECT_EQ(visit->add_count(), 1);
}


TEST(VisitorTest, Test6){
Op* first = new Op(13.56);
Op* second = new Op(4);
Mult* temp = new Mult(first,second);
Decorator* dummy = new Floor(temp);

Iterator *it = new PreorderIterator(dummy);
CountVisitor *visit = new CountVisitor();
it->first();
while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
}
                EXPECT_EQ(visit->op_count(), 2);
                EXPECT_EQ(visit->mult_count(), 1);
}

TEST(VisitorTest, Test7){
Op* first = new Op(-2.56);
Op* second = new Op(5);
Op* third = new Op(9.2);
Op* fourth = new Op(5);

Add* add = new Add(third,second);
Decorator* dummy = new Floor(add);
Mult* mult = new Mult(dummy, first);
Decorator* dummy2 = new Ceil(mult);
Sub* sub = new Sub(dummy2, fourth);
Decorator* dummy3 = new Abs(sub);

Iterator *it = new PreorderIterator(dummy3);
CountVisitor *visit = new CountVisitor();
it->first();
while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
}
                EXPECT_EQ(visit->op_count(), 4);
                EXPECT_EQ(visit->mult_count(), 1);
                EXPECT_EQ(visit->sub_count(), 1);
                EXPECT_EQ(visit->add_count(), 1);
}
#endif
