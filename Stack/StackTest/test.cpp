#include "pch.h"
#include "../StackOnList/StackOnList.h"
#include "../StackOnArray/StackOnArray.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(StackOnLIst, commonTest) {
	StackOnList<int> a;
	a.push(3);
	a.push(4);
	a.pop();
	a.push(5);
	EXPECT_EQ(a.top(), 5);
	a.push(12);
	a.push(12);
	a.push(12);
	a.pop();
	a.pop();
	StackOnList<int> b = a;
	StackOnList<int> b1(a);

	EXPECT_EQ(a.top(), 12);
	EXPECT_EQ(b.top(), 12);
	EXPECT_EQ(b1.top(), 12);

	for (int i = 0; i > -1000; i--) {
		a.push(i);
		b.push(i);
		b1.push(i);
	}
	EXPECT_EQ(a.top(), -999);
	EXPECT_EQ(b.top(), -999);
	EXPECT_EQ(b1.top(), -999);
	for (int i = 0; i < 1000; i++) {
		a.pop();
		b.pop();
		b1.pop();
	}
	EXPECT_EQ(a.top(), 12);
	EXPECT_EQ(b.top(), 12);
	EXPECT_EQ(b1.top(), 12);
}

TEST(StackOnArray, commonTest) {
	StackOnArray<int> a;
	a.push(3);
	a.push(4);
	a.pop();
	a.push(5);
	EXPECT_EQ(a.top(), 5);
	a.push(12);
	a.push(12);
	a.push(12);
	a.pop();
	a.pop();
	StackOnArray<int> b = a;
	StackOnArray<int> b1(a);
	EXPECT_EQ(a.top(), 12);
	EXPECT_EQ(a.size(), 3);
	EXPECT_EQ(b.top(), 12);
	EXPECT_EQ(b.size(), 3);
	EXPECT_EQ(b1.top(), 12);
	EXPECT_EQ(b1.size(), 3);
	for (int i = 0; i > -1000; i--) {
		a.push(i);
		b.push(i);
		b1.push(i);
	}
	EXPECT_EQ(a.top(), -999);
	EXPECT_EQ(a.size(), 1003);
	EXPECT_EQ(b.top(), -999);
	EXPECT_EQ(b.size(), 1003);
	EXPECT_EQ(b1.top(), -999);
	EXPECT_EQ(b1.size(), 1003);
	for (int i = 0; i < 1000; i++) {
		a.pop();
		b.pop();
		b1.pop();
	}
	EXPECT_EQ(a.top(), 12);
	EXPECT_EQ(a.size(), 3);
	EXPECT_EQ(b.top(), 12);
	EXPECT_EQ(b.size(), 3);
	EXPECT_EQ(b1.top(), 12);
	EXPECT_EQ(b1.size(), 3);
}
