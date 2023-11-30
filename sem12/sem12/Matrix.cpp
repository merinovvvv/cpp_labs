#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

#include "Matrix.h"

// ���������� ��������� ����� ����� ���������� min � max
// ��������������, ��� ������� srand() ��� ��������
int RandomNumber(int min, int max)
{
    srand(time(NULL));
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // ���������� ������������ ��������� ����� � ����� ���������
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Matrix::Matrix() {
    n_ = 0;
    m_ = 0;
    a_ = nullptr;
}
Matrix::~Matrix() {
    // �������� � ���������� ���������� ����������

    for (int i = 0; i < n_; i++) {
        delete[] a_[i];
    }
    delete[] a_;
}
Matrix::Matrix(const int n, const int m) {
    n_ = n;
    m_ = m;

    // �������� � ���������� ���������� ����������
    a_ = new int* [n_];
    for (int i = 0; i < n_; i++) {
        a_[i] = new int[m_];
    }

    std::srand(100); // start value for generator 100
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < m_; j++) {
            a_[i][j] = (int)(RandomNumber(0, 100));
        }
    }
    show();
}
Matrix::Matrix(const int n, const int m, const int k) {
    n_ = n;
    m_ = m;

    // �������� � ���������� ���������� ����������
    a_ = new int* [n_];
    for (int i = 0; i < n_; i++) {
        a_[i] = new int[m_];
    }

    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < m_; j++) {
            a_[i][j] = k;
        }
    }
    if (k != 0) {
        show();
    }
}

int Matrix::GetN() {
    return n_;
}
int Matrix::GetM() {
    return m_;
}

int** Matrix::GetA() {
    return a_;
}

struct Student
{
    std::string name_;
    int age_ = 0;
} stud;



void Matrix::show() {
    std::cout << "Matrix (" << n_ << " x " << m_ << "):\n";
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < m_; j++) {
            std::cout << a_[i][j] << " ";
        }
        std::cout << '\n';
        // ������ � ����� �������������� ����� ������������� ����������� ���������� ��������� Man
        stud.name_ = "Ivan Ivanov";
        // ������ � ����� �������������� ����� ������ �� ���������� ��������� Student
        Student& ref = stud;
        ref.age_ = 18;

        // ������ � ����� �������������� ����� ��������� �� ���������� ��������� Man
        Student* ptr = &stud;
        (*ptr).age_ = 18;
        ptr->age_ = 18;
    }
};


