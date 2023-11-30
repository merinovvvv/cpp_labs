#include "pch.h"
#include "../lab09/StackOnList.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(StackOnList, isCostrWorking) {
	StackOnList* stack = new StackOnList();
	EXPECT_NE(stack, nullptr);
	delete stack;
}

TEST(StackOnList, IsPushWorking) {
	StackOnList stack;
	stack.push(1);
	EXPECT_TRUE(stack.top(), 1);
	stack.push(5);
	EXPECT_TRUE(stack.top(), 5);
}

TEST(StackOnList, IsPopWorking) {
	StackOnList stack;
	stack.push(1);
	stack.push(5);
	EXPECT_TRUE(stack.pop(), 5);
	EXPECT_TRUE(stack.pop(), 1);
}

TEST(StackOnList, IsStackEmpty) {
	StackOnList stack;
	EXPECT_TRUE(stack.isEmpty());
	stack.push(1);
	stack.push(2);
	EXPECT_FALSE(stack.isEmpty());
	stack.pop();
	EXPECT_FALSE(stack.isEmpty());
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());
}

TEST(StackOnList, IsCopyCostrWorking) {
	StackOnList stack;
	stack.push(2);
	stack.push(4);
	stack.push(6);
	StackOnList stack2(stack);
	EXPECT_EQ(stack2.top(), stack.top());
	stack.push(8);
	stack2.push(8);
	EXPECT_EQ(stack2.top(), stack.top());
}
