#include <iostream>
#include "String.h"

int main() {
    String s1("Hello");
    String s2("World");
    const char* c_str = "Hello";

    // Проверка операторов сравнения для String
    if (s1 == s2) {
        std::cout << "s1 is equal to s2.\n";
    }
    else {
        std::cout << "s1 is not equal to s2.\n";
    }

    if (s1 != s2) {
        std::cout << "s1 is not equal to s2.\n";
    }
    else {
        std::cout << "s1 is equal to s2.\n";
    }

    if (s1 < s2) {
        std::cout << "s1 is less than s2.\n";
    }
    else {
        std::cout << "s1 is not less than s2.\n";
    }

    // Проверка операторов сравнения для const char* и String
    if (c_str == s1) {
        std::cout << "cstr is equal to s1.\n";
    }
    else {
        std::cout << "cstr is not equal to s1.\n";
    }

    if (c_str != s1) {
        std::cout << "cstr is not equal to s1.\n";
    }
    else {
        std::cout << "cstr is equal to s1.\n";
    }

    if (c_str < s1) {
        std::cout << "cstr is less than s1.\n";
    }
    else {
        std::cout << "cstr is not less than s1.\n";
    }
    String a;
    std::cin >> a;
    std::cout <<'\n' << a;

    return 0;
}