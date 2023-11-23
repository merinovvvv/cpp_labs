//#pragma once
//#ifndef OVERLOADS_H_
//#define OVERLOADS_H_
//#include <iostream>
//#include "RationalNumber.h"
//
//
//
//template <typename T>
//RationalNumber<T> operator+ (const RationalNumber<T>& fraction1, const RationalNumber<T>& fraction2) {
//	RationalNumber<T> result;
//	result.Sum(fraction1, fraction2);
//	return result;
//}
//
//template <typename T>
//RationalNumber<T> operator- (const RationalNumber<T>& fraction) {
//	return RationalNumber<T>(-fraction.numerator_, fraction.denominator_);
//}
//
//template <typename T>
//RationalNumber<T> operator- (const RationalNumber<T>& fraction1, const RationalNumber<T>& fraction2) {
//    RationalNumber<T> result;
//    result.Subtraction(fraction1, fraction2);
//    return result;
//}
//
//template <typename T>
//RationalNumber<T> operator* (const RationalNumber<T>& fraction1, const RationalNumber<T>& fraction2) {
//	RationalNumber<T> result;
//	result.Multiplication(fraction1, fraction2);
//	return result;
//}
//
//template <typename T>
//RationalNumber<T> operator/ (const RationalNumber<T>& fraction1, const RationalNumber<T>& fraction2) {
//	RationalNumber<T> result;
//	result.Division(fraction1, fraction2);
//	return result;
//}
//
//template <typename T>
//RationalNumber<T>& operator+= (RationalNumber<T>& fraction1, const RationalNumber<T>& fraction2) {
//	fraction1.Sum(fraction1, fraction2);
//	return fraction1;
//}
//
//template <typename T>
//RationalNumber<T>& operator-= (RationalNumber<T>& fraction1, const RationalNumber<T>& fraction2) {
//	fraction1.Subtraction(fraction1, fraction2);
//	return fraction1;
//}
//
//template <typename T>
//RationalNumber<T>& operator*= (RationalNumber<T>& fraction1, const RationalNumber<T>& fraction2) {
//	fraction1.Multiplication(fraction1, fraction2);
//	return fraction1;
//}
//
//template <typename T>
//RationalNumber<T>& operator/= (RationalNumber<T>& fraction1, const RationalNumber<T>& fraction2) {
//	fraction1.Division(fraction1, fraction2);
//	return fraction1;
//}
//
//template <typename T>
//bool operator== (RationalNumber <T>& fraction1, RationalNumber <T>& fraction2) {
//	if (fraction1.numerator_ == fraction2.numerator_ && fraction1.denominator_ == fraction2.denominator_) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//template <typename T>
//bool operator!= (RationalNumber <T>& fraction1, RationalNumber <T>& fraction2) {
//	if (fraction1.numerator_ == fraction2.numerator_ && fraction1.denominator_ == fraction2.denominator_) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}
//
//template <typename T>
//bool operator< (RationalNumber <T>& fraction1, RationalNumber <T>& fraction2) {
//	if (fraction1.numerator_ * fraction2.denominator_ < fraction2.numerator_ * fraction1.denominator_) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//template <typename T>
//bool operator> (RationalNumber <T>& fraction1, RationalNumber <T>& fraction2) {
//	if (fraction1.numerator_ * fraction2.denominator_ > fraction2.numerator_ * fraction1.denominator_) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//template <typename T>
//bool operator>= (RationalNumber <T>& fraction1, RationalNumber <T>& fraction2) {
//	if (fraction1.numerator_ == fraction2.numerator_ && fraction1.denominator_ == fraction2.denominator_ &&
//		fraction1.numerator_ * fraction2.denominator_ > fraction2.numerator_ * fraction1.denominator_) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//template <typename T>
//bool operator<= (RationalNumber <T>& fraction1, RationalNumber <T>& fraction2) {
//	if (fraction1.numerator_ == fraction2.numerator_ && fraction1.denominator_ == fraction2.denominator_ &&
//		fraction1.numerator_ * fraction2.denominator_ < fraction2.numerator_ * fraction1.denominator_) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//template <typename T>
//RationalNumber<T>& operator++ (RationalNumber<T>& fraction) {
//	RationalNumber<T> fraction2(1, 1);
//	fraction.Sum(fraction, fraction2);
//	return fraction;
//}
//
//template <typename T>
//RationalNumber<T>& RationalNumber<T>::operator--() {
//	RationalNumber<T> res(1, 1);
//	*this -= res;
//	return *this;
//}
//
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const RationalNumber <T>& fraction) {
//	os << fraction.numerator_ << "/" << fraction.denominator_;
//	return os;
//}
//#endif //OVERLOADS_H_