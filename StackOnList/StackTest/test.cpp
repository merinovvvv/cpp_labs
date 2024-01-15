#include "pch.h"
#include "../StackOnList/Stack.h"
z
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//TEST(StackTest, PushAndPop) {
//	Stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	EXPECT_EQ(s.top(), 3);
//	s.pop();
//	EXPECT_EQ(s.top(), 2);
//	s.pop();
//	EXPECT_EQ(s.top(), 1);
//	s.pop();
//	EXPECT_TRUE(s.isEmpty());
//}
//
//TEST(StackTest, CopyConstructor) {
//	Stack<int> s1;
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//
//	Stack<int> s2(s1);
//	EXPECT_EQ(s1.top(), s2.top());
//	s1.pop();
//	EXPECT_NE(s1.top(), s2.top());
//}
//
//TEST(StackTest, MoveConstructor) {
//	Stack<int> s1;
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//
//	Stack<int> s2(std::move(s1));
//	EXPECT_EQ(s2.top(), 3);
//	EXPECT_TRUE(s1.isEmpty());
//}
//
//TEST(StackTest, CopyAssignment) {
//	Stack<int> s1;
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//
//	Stack<int> s2;
//	s2 = s1;
//	EXPECT_EQ(s1.top(), s2.top());
//	s1.pop();
//	EXPECT_NE(s1.top(), s2.top());
//}
//
//TEST(StackTest, MoveAssignment) {
//	Stack<int> s1;
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//
//	Stack<int> s2;
//	s2 = std::move(s1);
//	EXPECT_EQ(s2.top(), 3);
//	EXPECT_TRUE(s1.isEmpty());
//}
//
//TEST(StackTest, Swap) {
//	Stack<int> s1;
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//
//	Stack<int> s2;
//	s2.push(4);
//	s2.push(5);
//	s2.push(6);
//
//	s1.swap(s2);
//	EXPECT_EQ(s1.top(), 6);
//	EXPECT_EQ(s2.top(), 3);
//}