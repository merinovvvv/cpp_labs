#pragma once

#ifndef DATE_H
#define DATE_H

#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <iostream>
#include <tuple>
#include <cstdint>

class Date {
public:
    Date();
    Date(int year, int month = 1, int day = 1);
    Date (const Date& other);
    Date (Date&& other) = default;
    Date& operator= (const Date& other);
    Date& operator= (Date&& other) noexcept;
    ~Date();
   

    Date operator+(int days) const;
    Date operator-(int days) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;

    friend std::istream& operator>>(std::istream& is, Date& date);
// TODO перегрузить операторы сравнения


    int day() const noexcept; // возвращает день
    int month() const noexcept;
    int year() const noexcept;
    int age() const noexcept; // возраст существа, на сегодня, если *this - дата отсчета
    int age(const Date& date) const noexcept; // возраст существа, на date, если *this - дата отсчета
 

    static bool isLeapYear(int year)  noexcept;
    static int daysInMonth(int year, int month) noexcept; //количество дней в месяце
    std::string toString() const noexcept;

private:
    int day_;
    int month_;
    int year_;

    std::shared_ptr<spdlog::logger> log_;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};

#endif //DATE_H