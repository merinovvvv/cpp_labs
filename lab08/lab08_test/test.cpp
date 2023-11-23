#include "pch.h"
#include "../lab08/RationalNumber.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(RationalNumberTest, AdditionOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(1, 4);

    RationalNumber<int> result = fraction1 + fraction2;

    EXPECT_EQ(result, RationalNumber<int>(3, 4));
}

TEST(RationalNumberTest, SubtractionOperator) {
    RationalNumber<int> fraction1(3, 4);
    RationalNumber<int> fraction2(1, 4);

    RationalNumber<int> result = fraction1 - fraction2;

    EXPECT_EQ(result, RationalNumber<int>(1, 2));
}

TEST(RationalNumberTest, MultiplicationOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(2, 3);

    RationalNumber<int> result = fraction1 * fraction2;

    EXPECT_EQ(result, RationalNumber<int>(1, 3));
}

TEST(RationalNumberTest, DivisionOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(3, 4);

    RationalNumber<int> result = fraction1 / fraction2;

    EXPECT_EQ(result, RationalNumber<int>(2, 3));
}


TEST(RationalNumberTest, EqualityOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(2, 4);

    bool res = (fraction1 == fraction2);

    EXPECT_EQ(res, true);
}

TEST(RationalNumberTest, InequalityOperator) {
    RationalNumber<int> fraction1(3, 4);
    RationalNumber<int> fraction2(1, 2);

    bool res = (fraction1 != fraction2);

    EXPECT_EQ(res, true);
}

TEST(RationalNumberTest, LessThanOperator) {
    RationalNumber<int> fraction1(1, 3);
    RationalNumber<int> fraction2(1, 2);

    bool res = (fraction1 < fraction2);

    EXPECT_EQ(res, true);

}

TEST(RationalNumberTest, GreaterThanOperator) {
    RationalNumber<int> fraction1(5, 6);
    RationalNumber<int> fraction2(2, 3);

    bool res = (fraction1 > fraction2);

    EXPECT_EQ(res, true);
}

TEST(RationalNumberTest, LessThanOrEqualOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(3, 4);

    bool res = (fraction1 <= fraction2);

    EXPECT_EQ(res, true);
}

TEST(RationalNumberTest, GreaterThanOrEqualOperator) {
    RationalNumber<int> fraction1(5, 6);
    RationalNumber<int> fraction2(10, 12);

    bool res = (fraction1 >= fraction2);

    EXPECT_EQ(res, true);
}

TEST(RationalNumberTest, AssignmentOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(3, 4);

    fraction1 = fraction2;

    EXPECT_EQ(fraction1, fraction2);
}

TEST(RationalNumberTest, CompoundAdditionOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(3, 4);

    fraction1 += fraction2;

    EXPECT_EQ(fraction1, RationalNumber<int>(11, 12));
}

TEST(RationalNumberTest, CompoundSubtractionOperator) {
    RationalNumber<int> fraction1(3, 4);
    RationalNumber<int> fraction2(1, 4);

    fraction1 -= fraction2;

    EXPECT_EQ(fraction1, RationalNumber<int>(1, 2));
}

TEST(RationalNumberTest, CompoundMultiplicationOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(2, 3);

    fraction1 *= fraction2;

    EXPECT_EQ(fraction1, RationalNumber<int>(1, 3));
}

TEST(RationalNumberTest, CompoundDivisionOperator) {
    RationalNumber<int> fraction1(1, 2);
    RationalNumber<int> fraction2(3, 4);

    fraction1 /= fraction2;

    EXPECT_EQ(fraction1, RationalNumber<int>(2, 3));
}

TEST(RationalNumberTest, PreIncrementOperator) {
    RationalNumber<int> fraction(1, 2);

    ++fraction;

    EXPECT_EQ(fraction, RationalNumber<int>(3, 2));
}

TEST(RationalNumberTest, PreDecrementOperator) {
    RationalNumber<int> fraction(3, 2);

    --fraction;

    EXPECT_EQ(fraction, RationalNumber<int>(1, 2));
}

TEST(RationalNumberTest, OutputStreamOperator) {
    RationalNumber<int> fraction(3, 4);

    std::ostringstream oss;
    oss << fraction;

    EXPECT_EQ(oss.str(), "3/4");
}

