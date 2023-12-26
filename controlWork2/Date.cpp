#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <memory>
#include <exception>
#include <sstream>
#include <ctime>

#include "Date.h"


Date::Date() : day_(1), month_(1), year_(0) {}
Date::Date(int year, int month, int day) {
	year_ = year;
	month_ = month;
	day_ = day;
}
Date::Date(const Date& other) : day_(other.day_), month_(other.month_), year_(other.year_) {
	log_ = spdlog::get("DateLogger");
}

Date::~Date() = default;

Date& Date::operator=(const Date& other) {
	spdlog::info("DateLogger");
	if (this != &other) {
		day_ = other.day_;
		month_ = other.month_;
		year_ = other.year_;
	}
	return *this;
}

Date& Date::operator=(Date&& other) noexcept {
	if (this != &other) {
		day_ = other.day_;
		month_ = other.month_;
		year_ = other.year_;
		log_ = std::move(other.log_);
		other.log_ = nullptr;
	}
	return *this;
}

int Date::age() const noexcept {
	std::time_t now = std::time(nullptr);
	std::tm* local_time = std::localtime(&now);
	Date today(local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday);

	return this->age(today);
}

int Date::age(const Date& date) const noexcept {
	int age = 0;
	age += daysInMonth(year_, month_) - day_ + 1;
	for (int i = month_ + 1; i <= 12; ++i) {
		age += daysInMonth(year_, i);
	}
	for (int i = year_ + 1; i < date.year_; ++i) {
		if (isLeapYear(i)) {
			age += 366;
		}
		else {
			age += 365;
		}
	}
	for (int i = 1; i < date.month_; ++i) {
		age += daysInMonth(year_, i);
	}
	age += date.day_;

	return age;
}




int Date::day() const noexcept {
	return day_;
}

int Date::month() const noexcept {
	return month_;
}

int Date::year() const noexcept {
	return year_;
}

bool Date::isLeapYear(int year) noexcept {
	if (year % 4 != 0) {
		return false;
	}
	else if (year % 100 != 0) {
		return true;
	}
	else if (year % 400 != 0) {
		return false;
	}
	else {
		return true;
	}
}

int Date::daysInMonth(int year, int month) noexcept {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (isLeapYear(year)) {
			return 29;
		}
		else {
			return 28;
		}
	default:
		return 0;
	}
}


Date Date::operator+(int days) const {
	Date result(*this);

	result.day_ += days;

	while (result.day_ > Date::daysInMonth(result.year_, result.month_)) {
		result.day_ -= Date::daysInMonth(result.year_, result.month_);
		result.month_++;
		if (result.month_ > 12) {
			result.month_ = 1;
			result.year_++;
		}
	}

	return result;
}

Date Date::operator-(int days) const {
	Date result(*this);

	result.day_ -= days;

	while (result.day_ < 1) {
		result.month_--;
		if (result.month_ < 1) {
			result.month_ = 12;
			result.year_--;
		}
		result.day_ += Date::daysInMonth(result.year_, result.month_);
	}

	return result;
}

bool Date::operator==(const Date& other) const {
	return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
}

bool Date::operator!=(const Date& other) const {
	return !(*this == other);
}

bool Date::operator<(const Date& other) const {
	return std::tie(year_, month_, day_) < std::tie(other.year_, other.month_, other.day_);
}

bool Date::operator>(const Date& other) const {
	return std::tie(year_, month_, day_) > std::tie(other.year_, other.month_, other.day_);
}

bool Date::operator<=(const Date& other) const {
	return !(other < *this);
}

bool Date::operator>=(const Date& other) const {
	return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << date.toString();
	return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
	char delimiter;
	is >> date.year_ >> delimiter >> date.month_ >> delimiter >> date.day_;
	return is;
}

std::string Date::toString() const noexcept {
	std::ostringstream oss;
	oss << year_ << "-" << month_ << "-" << day_;
	return oss.str();
}