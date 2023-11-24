#pragma once
#ifndef RATIONAL_NUMBER_H_
#define RATIONAL_NUMBER_H_

#include <iostream>
#include <numeric>

template<class T>
class RationalNumber {
public:

	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const RationalNumber<U>& fraction);

	RationalNumber<T>& operator+();
	RationalNumber<T> operator+ (const RationalNumber<T>& other) const;
	friend RationalNumber<T> operator+ (const T& other, const RationalNumber<T>& fraction2);
	friend RationalNumber<T> operator+ (const RationalNumber<T>& fraction1, const T& other);

	RationalNumber<T>& operator- ();
	RationalNumber<T> operator- (const RationalNumber<T>& other) const;
	friend RationalNumber<T> operator- (const RationalNumber<T>& fraction1, const T& other);

	RationalNumber<T> operator* (const RationalNumber<T>& other) const;
	friend RationalNumber<T> operator* (const T& other, const RationalNumber<T>& fraction2);
	friend RationalNumber<T> operator* (const RationalNumber<T>& fraction1, const T& other);

	RationalNumber<T> operator/ (const RationalNumber<T>& other) const;
	friend RationalNumber<T> operator/ (const T& other, const RationalNumber<T>& fraction2);
	friend RationalNumber<T> operator/ (const RationalNumber<T>& fraction1, const T& other);

	RationalNumber<T>& operator+= (const RationalNumber<T>& other);
	RationalNumber<T>& operator-= (const RationalNumber<T>& other);
	RationalNumber<T>& operator*= (const RationalNumber<T>& other);
	RationalNumber<T>& operator/= (const RationalNumber<T>& other);


	bool operator== (const RationalNumber <T>& other) const;
	friend bool operator== (const T& other, const RationalNumber<T>& fraction2);
	friend bool operator== (const RationalNumber<T>& fraction1, const T& other);


	bool operator!= (const RationalNumber <T>& other) const;
	friend bool operator!= (const T& other, const RationalNumber<T>& fraction2);
	friend bool operator!= (const RationalNumber<T>& fraction1, const T& other);

	bool operator< (const RationalNumber <T>& other) const;
	friend bool operator< (const T& other, const RationalNumber<T>& fraction2);
	friend bool operator< (const RationalNumber<T>& fraction1, const T& other);

	bool operator> (const RationalNumber <T>& other) const;
	friend bool operator> (T& other, const RationalNumber<T>& fraction2);
	friend bool operator> (const RationalNumber<T>& fraction1, const T& other);

	bool operator<= (const RationalNumber <T>& other) const;
	friend bool operator<= (const T& other, const RationalNumber<T>& fraction2);
	friend bool operator<= (const RationalNumber<T>& fraction1, const T& other);


	bool operator>= (const RationalNumber <T>& other) const;
	friend bool operator>= (const T& other, const RationalNumber<T>& fraction2);
	friend bool operator>= (const RationalNumber<T>& fraction1, const T& other);

	RationalNumber<T>& operator= (const RationalNumber<T>& other);

	RationalNumber<T>& operator++ ();
	RationalNumber<T>& operator-- ();

	RationalNumber() : numerator_(0), denominator_(1) {}

	RationalNumber(T numerator, T denominator) : numerator_(numerator), denominator_(denominator) {
		try {
			if (denominator == 0) {
				throw std::invalid_argument("Denominator cannot be zero");
			}
			else if (denominator_ < 0 && numerator_ < 0) {
				// Убираем минус из знаменателя и числителя
				std::cout << "Minuses in both numerator and denominator.\n\n";
				numerator_ = -numerator_;
				denominator_ = -denominator_;
				std::cout << "The fraction looks like: " << numerator_ << '/' << denominator_ << '\n';
			}
			else if (denominator_ < 0 && numerator_ > 0) {
				// Переносим минус из знаменателя в числитель
				std::cout << "Wrong denominator, the minus will go to the numerator.\n";
				numerator_ = -numerator_;
				denominator_ = -denominator_;
				std::cout << "The fraction looks like: " << numerator_ << '/' << denominator_ << '\n';
			}
			if (numerator_ == 0)
			{
				std::cout << "Numerator equals to 0 -> denominator = 1.";
				denominator_ = 1;
			}
			reduction();
		}
		catch (const std::exception& e) {
			// Обработка исключения
			std::cerr << "Error during object creation: " << e.what() << std::endl;
			exit(0);
		}
	}

	~RationalNumber() = default;

	RationalNumber(const RationalNumber<T>& other);

	// Конструктор перемещения
	RationalNumber(RationalNumber<T>&& other) noexcept = default;

	// Оператор перемещения
	RationalNumber<T>& operator=(RationalNumber<T>&& other) noexcept = default;

private:
	T numerator_;
	T denominator_;

	void reduction();

public:
	RationalNumber Sum(RationalNumber<T> other);
	RationalNumber Subtraction(RationalNumber<T> other);
	RationalNumber Division(RationalNumber<T> other);
	RationalNumber Multiplication(RationalNumber<T> other);
};

template <typename T>
RationalNumber<T>::RationalNumber(const RationalNumber<T>& other)
	: numerator_(other.numerator_), denominator_(other.denominator_) {}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator+ () {
	reduction();
	return *this;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator+ (const RationalNumber<T>& other) const {
	RationalNumber<T> result(*this);
	result.denominator_ = denominator_ * other.denominator_;
	result.numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
	result.reduction();
	return result;
}

template <typename T>
RationalNumber<T> operator+ (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber<T> fraction1;
	fraction1.numerator_ = other;
	fraction1.denominator_ = 1;
	return fraction1 + fraction2;
}

template <typename T>
RationalNumber<T> operator+ (const RationalNumber<T>& fraction1, const T& other) {
	RationalNumber<T> fraction2;
	fraction2.numerator_ = other;
	fraction2.denominator_ = 1;
	return fraction1 + fraction2;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator- () {
	numerator_ = -numerator_;

	return *this;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator- (const RationalNumber<T>& other) const {
	RationalNumber<T> result(*this);
	result.denominator_ = denominator_ * other.denominator_;
	result.numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
	result.reduction();
	return result;
}

template <typename T>
RationalNumber<T> operator- (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber<T> fraction1;
	fraction1.numerator_ = other;
	fraction1.denominator_ = 1;
	return fraction1 - fraction2;
}

template <typename T>
RationalNumber<T> operator- (const RationalNumber<T>& fraction1, const T& other) {
	RationalNumber<T> fraction2;
	fraction2.numerator_ = other;
	fraction2.denominator_ = 1;
	return fraction1 - fraction2;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator* (const RationalNumber<T>& other) const {
	RationalNumber<T> result(*this);
	result.denominator_ = denominator_ * other.denominator_;
	result.numerator_ = numerator_ * other.numerator_;
	result.reduction();
	return result;
}

template <typename T>
RationalNumber<T> operator* (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber<T> fraction1;
	fraction1.numerator_ = other;
	fraction1.denominator_ = 1;
	return fraction1 * fraction2;
}

template <typename T>
RationalNumber<T> operator* (const RationalNumber<T>& fraction1, const T& other) {
	RationalNumber<T> fraction2;
	fraction2.numerator_ = other;
	fraction2.denominator_ = 1;
	return fraction1 * fraction2;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator/ (const RationalNumber<T>& other) const {
	RationalNumber<T> result(*this);
	try {
		if (other.numerator_ == 0) {
			throw std::invalid_argument("Division by zero");
		}
		result.denominator_ = denominator_ * other.numerator_;
		result.numerator_ = numerator_ * other.denominator_;
		result.reduction();
	}
	catch (const std::exception& e) {
		// Обработка исключения
		std::cerr << "Error during division: " << e.what() << std::endl;
		exit(0);
	}
	return result;
}

template <typename T>
RationalNumber<T> operator/ (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber<T> fraction1;
	fraction1.numerator_ = other;
	fraction1.denominator_ = 1;
	return fraction1 / fraction2;
}

template <typename T>
RationalNumber<T> operator/ (const RationalNumber<T>& fraction1, const T& other) {
	try {
		if (other == 0) {
			throw std::invalid_argument("Division by zero");
			RationalNumber<T> fraction2;
			fraction2.numerator_ = other;
			fraction2.denominator_ = 1;
			return fraction1 / fraction2;
		}
	}
	catch (const std::exception& e) {
		// Обработка исключения
		std::cerr << "Error during division: " << e.what() << std::endl;
		exit(0);
	}

}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator+=(const RationalNumber<T>& other) {
	return *this = *this + other;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator-=(const RationalNumber<T>& other) {
	return *this = *this - other;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator*= (const RationalNumber<T>& other) {
	return *this = *this * other;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator/= (const RationalNumber<T>& other) {
	try {
		if (other.numerator_ == 0) {
			throw std::invalid_argument("Division by zero");
		}
		*this = *this / other;
	}
	catch (const std::exception& e) {
		// Обработка исключения
		std::cerr << "Error during division: " << e.what() << std::endl;
		exit(0);
	}
	return *this;
}

template <typename T>
bool RationalNumber<T>::operator== (const RationalNumber <T>& other) const {
	return (numerator_ == other.numerator_ && denominator_ == other.denominator_);
}

template <typename T>
bool operator== (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fr.numerator_ == fraction2.numerator_ && fr.denominator_ == fraction2.denominator_);
}

template <typename T>
bool operator== (const RationalNumber<T>& fraction1, const T& other) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fr.numerator_ == fraction1.numerator_ && fr.denominator_ == fraction1.denominator_);
}

template <typename T>
bool RationalNumber<T>::operator!= (const RationalNumber <T>& other) const {
	return !(*this == other);
}

template <typename T>
bool operator!= (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return !(fr == fraction2);
}

template <typename T>
bool operator!= (const RationalNumber<T>& fraction1, const T& other) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return !(fr == fraction1);
}

template <typename T>
bool RationalNumber<T>::operator< (const RationalNumber <T>& other) const {
	return (numerator_ * other.denominator_ < other.numerator_ * denominator_);
}

template <typename T>
bool operator< (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fr.numerator_ * fraction2.denominator_ < fraction2.numerator_ * fr.denominator_);
}

template <typename T>
bool operator< (const RationalNumber<T>& fraction1, const T& other) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fraction1.numerator_ * fr.denominator_ < fr.numerator_ * fraction1.denominator_);
}


template <typename T>
bool RationalNumber<T>::operator> (const RationalNumber <T>& other) const {
	return (numerator_ * other.denominator_ > other.numerator_ * denominator_);
}

template <typename T>
bool operator> (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fr.numerator_ * fraction2.denominator_ > fraction2.numerator_ * fr.denominator_);
}

template <typename T>
bool operator> (const RationalNumber<T>& fraction1, const T& other) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fraction1.numerator_ * fr.denominator_ > fr.numerator_ * fraction1.denominator_);
}

template <typename T>
bool RationalNumber<T>::operator<= (const RationalNumber <T>& other) const {
	return (*this < other || *this == other);
}

template <typename T>
bool operator<= (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fr < fraction2 || fr == fraction2);
}

template <typename T>
bool operator<= (const RationalNumber<T>& fraction2, const T& other) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fraction2 < fr || fr == fraction2);
}

template <typename T>
bool RationalNumber<T>::operator>= (const RationalNumber <T>& other) const {
	return (*this > other || *this == other);
}

template <typename T>
bool operator>= (const T& other, const RationalNumber<T>& fraction2) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fr > fraction2 || fr == fraction2);
}

template <typename T>
bool operator>= (const RationalNumber<T>& fraction2, const T& other) {
	RationalNumber <T> fr;
	fr.numerator_ = other;
	fr.denominator_ = 1;
	return (fraction2 > fr || fr == fraction2);
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator++ () {
	RationalNumber <T> res;
	res.numerator_ = denominator_;
	res.denominator_ = denominator_;
	return *this = *this + res;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator-- () {
	RationalNumber <T> res;
	res.numerator_ = denominator_;
	res.denominator_ = denominator_;
	return *this = *this - res;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const RationalNumber<U>& fraction) {
	os << fraction.numerator_ << "/" << fraction.denominator_;
	return os;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator= (const RationalNumber<T>& other) {
	if (this != &other) {
		numerator_ = other.numerator_;
		denominator_ = other.denominator_;
	}
	return *this;
}

template <typename T>
void RationalNumber<T>::reduction() {
	T g = std::gcd(denominator_, numerator_);
	denominator_ /= g;
	numerator_ /= g;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::Sum(RationalNumber<T> other) {
	return *this + other;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::Subtraction(RationalNumber<T> other) {
	return *this - other;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::Division(RationalNumber<T> other) {
	return *this * other;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::Multiplication(RationalNumber<T> other) {
	return *this / other;
}
#endif // RATIONAL_NUMBER_H_
