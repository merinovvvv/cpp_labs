#include "pch.h"
#include "../sem12/Matrix.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//TEST(MatrixTest, DefaultConstructor) {
//    Matrix matrix;
//    EXPECT_EQ(matrix.GetN(), 0);
//    EXPECT_EQ(matrix.GetM(), 0);
//    EXPECT_EQ(matrix.GetA(), nullptr);
//}
//
//TEST(MatrixTest, ParameterizedConstructorRandomValues) {
//    int n = 3;
//    int m = 4;
//    Matrix matrix(n, m);
//
//    EXPECT_EQ(matrix.GetN(), 3);
//    EXPECT_EQ(matrix.GetM(), 4);
//
//    // Check if all elements are within the valid range (0 to 100)
//    int** a = matrix.GetA();
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            EXPECT_GE(a[i][j], 0);
//            EXPECT_LE(a[i][j], 100);
//        }
//    }
//}
//
//TEST(MatrixTest, ParameterizedConstructorConstantValue) {
//    int n = 2;
//    int m = 3;
//    int k = 5;
//    Matrix matrix(n, m, k);
//
//    EXPECT_EQ(matrix.GetN(), 2);
//    EXPECT_EQ(matrix.GetM(), 3);
//
//    // Check if all elements are equal to the constant value k
//    int** a = matrix.GetA();
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            EXPECT_EQ(a[i][j], k);
//        }
//    }
//}
//
//TEST(MatrixTest, CopyConstructor) {
//    Matrix original(2, 3);
//    Matrix copy(original);
//
//    // Check if dimensions are the same
//    EXPECT_EQ(copy.GetN(), original.GetN());
//    EXPECT_EQ(copy.GetM(), original.GetM());
//
//    // Check if values are the same
//    int** originalA = original.GetA();
//    int** copyA = copy.GetA();
//    for (int i = 0; i < original.GetN(); ++i) {
//        for (int j = 0; j < original.GetM(); ++j) {
//            EXPECT_EQ(copyA[i][j], originalA[i][j]);
//        }
//    }
//}
//
//TEST(MatrixTest, MoveConstructor) {
//    Matrix original(2, 3);
//    Matrix moved(std::move(original));
//
//    // Check if dimensions are the same
//    EXPECT_EQ(moved.GetN(), 2);
//    EXPECT_EQ(moved.GetM(), 3);
//
//    // Check if original matrix is now empty
//    EXPECT_EQ(original.GetN(), 0);
//    EXPECT_EQ(original.GetM(), 0);
//    EXPECT_EQ(original.GetA(), nullptr);
//}
//
//TEST(MatrixTest, CopyAssignmentOperator) {
//    Matrix original(2, 3);
//    Matrix copy = original;
//
//    // Check if dimensions are the same
//    EXPECT_EQ(copy.GetN(), original.GetN());
//    EXPECT_EQ(copy.GetM(), original.GetM());
//
//    // Check if values are the same
//    int** originalA = original.GetA();
//    int** copyA = copy.GetA();
//    for (int i = 0; i < original.GetN(); ++i) {
//        for (int j = 0; j < original.GetM(); ++j) {
//            EXPECT_EQ(copyA[i][j], originalA[i][j]);
//        }
//    }
//}
//
//TEST(MatrixTest, MoveAssignmentOperator) {
//    Matrix original(2, 3);
//    Matrix moved = std::move(original);
//
//    // Check if dimensions are the same
//    EXPECT_EQ(moved.GetN(), 2);
//    EXPECT_EQ(moved.GetM(), 3);
//
//    // Check if original matrix is now empty
//    EXPECT_EQ(original.GetN(), 0);
//    EXPECT_EQ(original.GetM(), 0);
//    EXPECT_EQ(original.GetA(), nullptr);
//    }