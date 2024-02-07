#pragma once

#ifndef ARRAY_H
#define ARRAY_H
#include <initializer_list>
#include <vector>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

/*RVO, "оптимизация возвращаемого значения - return value "
 * "optimization".(до C++17)
 * Оптимизация возвращаемого значения является обязательной и больше
 * не рассматривается как пропуск копирования (с C++17);
 */

template <class T>
class Array {
public:
    Array() {
        spdlog::debug("Constructor default");
        valueList = nullptr;
        size = 0;
    }
    explicit Array(size_t n) {
        spdlog::debug("Constructor parametric with n");
        size = n;
        valueList = new T[size];
    }
    Array(size_t n, T value) {
        spdlog::debug("Constructor parametric with n and value");
        size = n;
        valueList = new T[size];
        for (int i = 0; i < size; ++i) {
            valueList[i] = value;
        }
    }

    Array(const std::initializer_list<T>& list) {
        spdlog::debug("Constructor parametric with initializer list");
        size = list.size();

        valueList = new T[size];
        size_t i = 0;
        for (auto& tmp : list) {
            valueList[i] = tmp;
            ++i;
        }
    }
    explicit Array(const std::vector<T>& list) {
        spdlog::debug("Constructor parametric is based on vector values");
        size = list.size();

        valueList = new T[size];
        size_t i = 0;
        for (auto& tmp : list) {
            valueList[i] = tmp;
            ++i;
        }
    }

    Array(const Array<T>& other) {
        spdlog::debug("Constructor copy");

        size = other.size;
        valueList = new T[size];
        for (size_t i = 0; i < size; ++i) {
            valueList[i] = other.getItem(i);
        }
    }
    Array<T>& operator=(const Array<T>& other) {
        spdlog::debug("Copy assignment operator");
        if (this != &other) {
            delete[] valueList; // Free the existing resource

            size = other.size;
            valueList = new T[size];
            for (size_t i = 0; i < size; ++i) {
                valueList[i] = other.getItem(i);
            }
        }
        return *this;
    }

    Array(Array<T>&& other) noexcept{
        spdlog::debug("Constructor move");
        size = other.size;
        valueList = other.valueList;

        other.size = 0;
        other.valueList = nullptr;
    }
    Array<T>& operator=(Array<T>&& other) noexcept{
        spdlog::debug("Move assignment operator");
        if (this != &other) {
            delete[] valueList; // Free the existing resource

            size = other.size;
            valueList = other.valueList;

            other.size = 0;
            other.valueList = nullptr;
        }
        return *this;
    }

    ~Array() {
        spdlog::debug("Destructor");
        if (valueList != nullptr) {
            delete[] valueList;
        }
    }

    T getItem(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("index is out of range");
        }
        return valueList[index];
    }

    void setItem(size_t index, T value) {
        if (index >= size) {
            throw std::out_of_range("index is out of range");
        }
        valueList[index] = value;
    }

    //operators' overloads
    Array<T> operator+(const Array<T>& other) const {
        size_t newSize;
        if (size > other.size) {
            for (size_t i = other.size; i < size; ++i) {
                other.valueList[i] = 0;
            }
            newSize = size;
        }
        else {
            newSize = other.size;
            for (size_t i = size; i < other.size; ++i) {
                valueList[i] = 0;
            }
        }
        Array<T> res(newSize);
        for (size_t j = 0; j < newSize; ++j) {
            res.valueList[j] = valueList[j] + other.valueList[j];
        }

        return res;
    }

    Array<T> operator+(const T& other) const {
        Array res(size);
        for (size_t i = 0; i < size; ++i) {
            res.valueList[i] = valueList[i] + other;
        }
        return res;
    }

    Array<T> operator-(const Array<T>& other) const {
        size_t newSize;
        if (size > other.size) {
            for (size_t i = other.size; i < size; ++i) {
                other.valueList[i] = 0;
            }
            newSize = size;
        }
        else {
            newSize = other.size;
            for (size_t i = size; i < other.size; ++i) {
                valueList[i] = 0;
            }
        }
        Array res(newSize);
        for (size_t j = 0; j < newSize; ++j) {
            res.valueList[j] = valueList[j] - other.valueList[j];
        }
        return res;
    }

    Array<T> operator-(const T& other) const {
        Array res(size);
        for (size_t i = 0; i < size; ++i) {
            res.valueList[i] = valueList[i] - other;
        }
        return res;
    }
    Array<T> operator*(const T& other) const {
        Array res(size);
        for (size_t i = 0; i < size; ++i) {
            res.valueList[i] = valueList[i] * other;
        }
        return res;
    }
    Array<T> operator/(const T& other) const {
        Array res(size);
        for (size_t i = 0; i < size; ++i) {
            res.valueList[i] = valueList[i] / other;
        }
        return res;
    }
    Array<T>& operator=(const T& other) const {
        for (size_t i = 0; i < size; ++i) {
            valueList[i] = other;
        }
        return *this;
    }
    Array<T>& operator+=(const T& other) {
        for (size_t i = 0; i < size; ++i) {
            valueList[i] += other;
        }
        return *this;
    }

    Array<T>& operator-=(const T& other) {
        for (size_t i = 0; i < size; ++i) {
            valueList[i] -= other;
        }
        return *this;
    }

    Array<T>& operator*=(const T& other) {
        for (size_t i = 0; i < size; ++i) {
            valueList[i] *= other;
        }
        return *this;
    }

    Array<T>& operator/=(const T& other) {
        for (size_t i = 0; i < size; ++i) {
            valueList[i] /= other;
        }
        return *this;
    }

    bool operator==(const Array<T>& other) const {
        if (size == other.size) {
            bool isEqual = true;
            for (size_t i = 0; i < size; ++i) {
                if (valueList[i] != other.valueList[i]) {
                    isEqual = false;
                }
            }
            return isEqual;
        }
        else {
            return false;
        }
    }

    bool operator==(const T& other) const {
        bool isEqual = true;
        for (size_t i = 0; i < size; ++i) {
            if (valueList[i] != other) {
                isEqual = false;
            }
        }
        return isEqual;
    }
    bool operator!=(const Array<T>& other) const {
        if (size == other.size) {
            bool isNotEqual = true;
            for (size_t i = 0; i < size; ++i) {
                if (valueList[i] == other.valueList[i]) {
                    isNotEqual = false;
                }
            }
            return isNotEqual;
        }
        else {
            return true;
        }
    }

    bool operator!=(const T& other) const {
        bool isNotEqual = true;
        for (size_t i = 0; i < size; ++i) {
            if (valueList[i] == other) {
                isNotEqual = false;
            }
        }
        return isNotEqual;
    }

    bool operator<(const Array<T>& other) const {
        if (size == other.size) {
            for (size_t i = 0; i < size;) {
                if (valueList[i] < other.valueList[i]) {
                    return true;
                }
                else if (valueList[i] > other.valueList[i]) {
                    return false;
                }
                else {
                    i++;
                }
            }
        }
        else {
            throw std::invalid_argument ("The size of other is not equal to current.");
        }
    }
    bool operator>(const Array<T>& other) const {
        if (size == other.size) {
            for (size_t i = 0; i < size;) {
                if (valueList[i] > other.valueList[i]) {
                    return true;
                }
                else if (valueList[i] < other.valueList[i]) {
                    return false;
                }
                else {
                    i++;
                }
            }
        }
        else {
            throw std::invalid_argument ("The size of other is not equal to current.");
        }
    }
    bool operator<=(const Array<T>& other) const {
        if (size == other.size) {
            for (size_t i = 0; i < size;) {
                if (valueList[i] < other.valueList[i]) {
                    return true;
                }
                else if (valueList[i] > other.valueList[i]){
                    return false;
                }
                else {
                    i++;
                }
            }
            return true;
        }
        else {
            throw std::invalid_argument ("The size of other is not equal to current.");
        }
    }
    bool operator>=(const Array<T>& other) const {
        if (size == other.size) {
            for (size_t i = 0; i < size;) {
                if (valueList[i] > other.valueList[i]) {
                    return true;
                }
                else if (valueList[i] < other.valueList[i]){
                    return false;
                }
                else {
                    i++;
                }
            }
            return true;
        }
        else {
            throw std::invalid_argument ("The size of other is not equal to current.");
        }
    }

    Array<T>& operator++() {
        for (size_t i = 0; i < size; ++i) {
            valueList[i] += 1;
        }
        return *this;
    }
    Array<T> operator++(int) {
        Array<T> newArr = *this;
        for (size_t i = 0; i < size; ++i) {
            valueList[i] += 1;
        }
        return newArr;
    }

    Array<T>& operator--() {
        for (size_t i = 0; i < size; ++i) {
            valueList[i] -= 1;
        }
        return *this;
    }
    Array<T> operator--(int) const {
        Array<T> newArr = *this;
        for (size_t i = 0; i < size; ++i) {
            valueList[i] -= 1;
        }
        return newArr;
    }

    template <class U>
    friend std::ostream& operator<< (std::ostream& stream, const Array<U>& other) {
        for (size_t i = 0; i < other.size; ++i) {
            stream << other.valueList[i] << ' ';
        }
        return stream;
    }

    template <class U>
    friend std::istream& operator>>(std::istream& stream, Array<U>& other) {
        for (size_t i = 0; i < other.size; ++i) {
            stream >> other.valueList[i];
        }
        return stream;
    }

    // fields
    T* valueList;
    size_t size;
};
#endif // ARRAY_H