#include <gtest/gtest.h>
#include "Array.h"

struct TestFixtures : public testing::Test {
    Array<int>* newArr{};
    void SetUp() override {
        newArr = new Array<int>(3);
    }
    void TearDown() override {
        delete newArr;
    };
};

// Test default constructor
TEST(ArrayConstructor, DefaultConstructor) {
    Array<int> arr;
    EXPECT_EQ(arr.size, 0);
    EXPECT_EQ(arr.valueList, nullptr);
}

// Test parametric constructor with size
TEST(ArrayConstructor, ParametricConstructorWithSize) {
    Array<int> arr(5);
    EXPECT_EQ(arr.size, 5);
    EXPECT_NE(arr.valueList, nullptr);
}

// Test parametric constructor with value
TEST(ArrayConstructor, ParametricConstructorWithValue) {
    Array<int> arr(3, 7);
    for (size_t i = 0; i < arr.size; ++i) {
        EXPECT_EQ(arr.valueList[i], 7);
    }
}

// Test initializer list constructor
TEST(ArrayConstructor, InitializerListConstructor) {
    Array<int> arr = {1, 2, 3};
    EXPECT_EQ(arr.size, 3);
    EXPECT_NE(arr.valueList, nullptr);
    for (size_t i = 0; i < arr.size; ++i) {
        EXPECT_EQ(arr.valueList[i], i + 1);
    }
}

// Test vector constructor
TEST(ArrayConstructor, VectorConstructor) {
    std::vector<int> vec = {4, 5, 6};
    Array<int> arr(vec);
    EXPECT_EQ(arr.size, 3);
    EXPECT_NE(arr.valueList, nullptr);
    for (size_t i = 0; i < arr.size; ++i) {
        EXPECT_EQ(arr.valueList[i], vec[i]);
    }
}

// Test copy constructor
TEST(ArrayCopyConstructor, CopyConstructor) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2(arr1);
    EXPECT_EQ(arr2.size, 3);
    EXPECT_NE(arr2.valueList, nullptr);
    for (size_t i = 0; i < arr2.size; ++i) {
        EXPECT_EQ(arr2.valueList[i], arr1.valueList[i]);
    }
}

// Test copy assignment operator
TEST(ArrayCopyAssignment, CopyAssignmentOperator) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2;
    arr2 = arr1;
    EXPECT_EQ(arr2.size, 3);
    EXPECT_NE(arr2.valueList, nullptr);
    for (size_t i = 0; i < arr2.size; ++i) {
        EXPECT_EQ(arr2.valueList[i], arr1.valueList[i]);
    }
}

// Test move constructor
TEST(ArrayMoveConstructor, MoveConstructor) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2(std::move(arr1));
    EXPECT_EQ(arr2.size, 3);
    EXPECT_NE(arr2.valueList, nullptr);
    EXPECT_EQ(arr1.size, 0);
    EXPECT_EQ(arr1.valueList, nullptr);
}

// Test move assignment operator
TEST_F(TestFixtures, MoveAssignmentOperator) {
    newArr->setItem(0, 1);
    newArr->setItem(1, 2);
    newArr->setItem(2, 3);
    EXPECT_EQ(newArr->size, 3);
    Array<int> arr2;
    arr2 = std::move(*newArr);
    EXPECT_EQ(arr2.size, 3);
    EXPECT_NE(arr2.valueList, nullptr);
    EXPECT_EQ(newArr->size, 0);
    EXPECT_EQ(newArr->valueList, nullptr);
}

// Test getItem function
TEST(ArrayAccess, GetItem) {
    Array<int> arr = {1, 2, 3};
    EXPECT_EQ(arr.getItem(0), 1);
    EXPECT_EQ(arr.getItem(1), 2);
    EXPECT_EQ(arr.getItem(2), 3);
    EXPECT_THROW(arr.getItem(3), std::out_of_range);
}

// Test setItem function
TEST(ArrayAccess, SetItem) {
    Array<int> arr = {1, 2, 3};
    arr.setItem(1, 5);
    EXPECT_EQ(arr.getItem(1), 5);
    EXPECT_THROW(arr.setItem(3, 7), std::out_of_range);
}

// Test operator+
TEST(ArrayOperators, OperatorPlus) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2 = {4, 5, 6};
    Array<int> result = arr1 + arr2;
    EXPECT_EQ(result.size, 3);
    EXPECT_NE(result.valueList, nullptr);
    EXPECT_EQ(result.getItem(0), 5);
    EXPECT_EQ(result.getItem(1), 7);
    EXPECT_EQ(result.getItem(2), 9);
}

// Test operator-
TEST(ArrayOperators, OperatorMinus) {
    Array<int> arr1 = {4, 5, 6};
    Array<int> arr2 = {1, 2, 3};
    Array<int> result = arr1 - arr2;
    EXPECT_EQ(result.size, 3);
    EXPECT_NE(result.valueList, nullptr);
    EXPECT_EQ(result.getItem(0), 3);
    EXPECT_EQ(result.getItem(1), 3);
    EXPECT_EQ(result.getItem(2), 3);
}

// Test operator*
TEST(ArrayOperators, OperatorMultiply) {
    Array<int> arr = {1, 2, 3};
    Array<int> result = arr * 2;
    EXPECT_EQ(result.size, 3);
    EXPECT_NE(result.valueList, nullptr);
    EXPECT_EQ(result.getItem(0), 2);
    EXPECT_EQ(result.getItem(1), 4);
    EXPECT_EQ(result.getItem(2), 6);
}

// Test operator/
TEST(ArrayOperators, OperatorDivide) {
    Array<int> arr = {4, 6, 8};
    Array<int> result = arr / 2;
    EXPECT_EQ(result.size, 3);
    EXPECT_NE(result.valueList, nullptr);
    EXPECT_EQ(result.getItem(0), 2);
    EXPECT_EQ(result.getItem(1), 3);
    EXPECT_EQ(result.getItem(2), 4);
}

// Test operator==
TEST(ArrayOperators, OperatorEqual) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2 = {1, 2, 3};
    EXPECT_TRUE(arr1 == arr2);

    Array<int> arr3 = {4, 5, 6};
    EXPECT_FALSE(arr1 == arr3);
}

// Test operator!=
TEST(ArrayOperators, OperatorNotEqual) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2 = {1, 2, 3};
    EXPECT_FALSE(arr1 != arr2);

    Array<int> arr3 = {4, 5, 6};
    EXPECT_TRUE(arr1 != arr3);
}

// Test operator<
TEST(ArrayOperators, OperatorLessThan) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2 = {4, 5, 6};
    EXPECT_TRUE(arr1 < arr2);

    Array<int> arr3 = {0, 2, 3};
    EXPECT_FALSE(arr1 < arr3);
}

// Test operator>
TEST(ArrayOperators, OperatorGreaterThan) {
    Array<int> arr1 = {4, 5, 6};
    Array<int> arr2 = {1, 2, 3};
    EXPECT_TRUE(arr1 > arr2);

    Array<int> arr3 = {7, 5, 6};
    EXPECT_FALSE(arr1 > arr3);
}

// Test operator<=
TEST(ArrayOperators, OperatorLessThanOrEqual) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2 = {4, 5, 6};
    EXPECT_TRUE(arr1 <= arr2);

    Array<int> arr3 = {1, 2, 3};
    EXPECT_TRUE(arr1 <= arr3);

    Array<int> arr4 = {0, 2, 3};
    EXPECT_FALSE(arr1 <= arr4);
}

// Test operator>=
TEST(ArrayOperators, OperatorGreaterThanOrEqual) {
    Array<int> arr1 = {4, 5, 6};
    Array<int> arr2 = {1, 2, 3};
    EXPECT_TRUE(arr1 >= arr2);

    Array<int> arr3 = {4, 5, 6};
    EXPECT_TRUE(arr1 >= arr3);

    Array<int> arr4 = {7, 5, 6};
    EXPECT_FALSE(arr1 >= arr4);
}

// Test operator+
TEST(ArrayOperators, OperatorPlusElementWise) {
    Array<int> arr1 = {1, 2, 3};
    Array<int> arr2 = {4, 5, 6};
    Array<int> result = arr1 + arr2;
    EXPECT_EQ(result.size, 3);
    EXPECT_NE(result.valueList, nullptr);
    EXPECT_EQ(result.getItem(0), 5);
    EXPECT_EQ(result.getItem(1), 7);
    EXPECT_EQ(result.getItem(2), 9);
}

// Test operator-
TEST(ArrayOperators, OperatorMinusElementWise) {
    Array<int> arr1 = {4, 5, 6};
    Array<int> arr2 = {1, 2, 3};
    Array<int> result = arr1 - arr2;
    EXPECT_EQ(result.size, 3);
    EXPECT_NE(result.valueList, nullptr);
    EXPECT_EQ(result.getItem(0), 3);
    EXPECT_EQ(result.getItem(1), 3);
    EXPECT_EQ(result.getItem(2), 3);
}

// Test operator<<
TEST(ArrayOperators, OperatorStreamInsertion) {
    Array<int> arr = {1, 2, 3};
    std::ostringstream oss;
    oss << arr;
    EXPECT_EQ(oss.str(), "1 2 3 ");
}

// Test operator>>
TEST(ArrayOperators, OperatorStreamExtraction) {
    Array<int> arr(3);
    std::istringstream iss("4 5 6");  // Input string with whitespaces
    iss >> arr;

    EXPECT_EQ(arr.size, 3);
    EXPECT_EQ(arr.getItem(0), 4);
    EXPECT_EQ(arr.getItem(1), 5);
    EXPECT_EQ(arr.getItem(2), 6);
}


// Test operator+=
TEST(ArrayOperators, OperatorPlusEqual) {
    Array<int> arr1 = {1, 2, 3};
    arr1 += 2;
    EXPECT_EQ(arr1.size, 3);
    EXPECT_EQ(arr1.getItem(0), 3);
    EXPECT_EQ(arr1.getItem(1), 4);
    EXPECT_EQ(arr1.getItem(2), 5);
}

// Test operator-=
TEST(ArrayOperators, OperatorMinusEqual) {
    Array<int> arr1 = {4, 5, 6};
    arr1 -= 2;
    EXPECT_EQ(arr1.size, 3);
    EXPECT_EQ(arr1.getItem(0), 2);
    EXPECT_EQ(arr1.getItem(1), 3);
    EXPECT_EQ(arr1.getItem(2), 4);
}

// Test operator*=
TEST(ArrayOperators, OperatorMultiplyEqual) {
    Array<int> arr = {1, 2, 3};
    arr *= 2;
    EXPECT_EQ(arr.size, 3);
    EXPECT_EQ(arr.getItem(0), 2);
    EXPECT_EQ(arr.getItem(1), 4);
    EXPECT_EQ(arr.getItem(2), 6);
}

// Test operator/=
TEST(ArrayOperators, OperatorDivideEqual) {
    Array<int> arr = {4, 6, 8};
    arr /= 2;
    EXPECT_EQ(arr.size, 3);
    EXPECT_EQ(arr.getItem(0), 2);
    EXPECT_EQ(arr.getItem(1), 3);
    EXPECT_EQ(arr.getItem(2), 4);
}

TEST(ArrayOperators, PrefixIncrement) {
    Array<int> arr = {1, 2, 3};
    Array<int> result = ++arr;

    EXPECT_EQ(arr.getItem(0), 2);
    EXPECT_EQ(arr.getItem(1), 3);
    EXPECT_EQ(arr.getItem(2), 4);

    EXPECT_EQ(result.size, 3);
    EXPECT_EQ(result.getItem(0), 2);
    EXPECT_EQ(result.getItem(1), 3);
    EXPECT_EQ(result.getItem(2), 4);
}

// Test postfix increment operator ++
TEST(ArrayOperators, PostfixIncrement) {
    Array<int> arr = {1, 2, 3};
    Array<int> result = arr++;

    EXPECT_EQ(arr.getItem(0), 2);
    EXPECT_EQ(arr.getItem(1), 3);
    EXPECT_EQ(arr.getItem(2), 4);

    EXPECT_EQ(result.size, 3);
    EXPECT_EQ(result.getItem(0), 1);
    EXPECT_EQ(result.getItem(1), 2);
    EXPECT_EQ(result.getItem(2), 3);
}

// Test prefix decrement operator --
TEST(ArrayOperators, PrefixDecrement) {
    Array<int> arr = {4, 5, 6};
    Array<int> result = --arr;

    EXPECT_EQ(arr.getItem(0), 3);
    EXPECT_EQ(arr.getItem(1), 4);
    EXPECT_EQ(arr.getItem(2), 5);

    EXPECT_EQ(result.size, 3);
    EXPECT_EQ(result.getItem(0), 3);
    EXPECT_EQ(result.getItem(1), 4);
    EXPECT_EQ(result.getItem(2), 5);
}

// Test postfix decrement operator --
TEST(ArrayOperators, PostfixDecrement) {
    Array<int> arr = {4, 5, 6};
    Array<int> result = arr--;

    EXPECT_EQ(arr.getItem(0), 3);
    EXPECT_EQ(arr.getItem(1), 4);
    EXPECT_EQ(arr.getItem(2), 5);

    EXPECT_EQ(result.size, 3);
    EXPECT_EQ(result.getItem(0), 4);
    EXPECT_EQ(result.getItem(1), 5);
    EXPECT_EQ(result.getItem(2), 6);
}

