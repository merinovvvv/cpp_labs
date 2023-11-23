#pragma once
#ifndef RATIONAL_NUMBER_H_
#define RATIONAL_NUMBER_H_

#include <iostream>

template<class T>
class RationalNumber {
public:

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const RationalNumber<U>& fraction);

    RationalNumber<T>& operator+();
    RationalNumber<T> operator+ (const RationalNumber<T>& other) const;
    friend RationalNumber<T> operator+ (const T& other, const RationalNumber<T>& fraction2);

    RationalNumber<T>& operator- ();
    RationalNumber<T> operator- (const RationalNumber<T>& other) const;
    friend RationalNumber<T> operator- (const T& other, const RationalNumber<T>& fraction2);

    RationalNumber<T> operator* (const RationalNumber<T>& other) const;
    friend RationalNumber<T> operator* (const T& other, const RationalNumber<T>& fraction2);

    RationalNumber<T> operator/ (const RationalNumber<T>& other) const;
    friend RationalNumber<T> operator/ (const T& other, const RationalNumber<T>& fraction2);

    RationalNumber<T>& operator+= (const RationalNumber<T>& other);
    RationalNumber<T>& operator-= (const RationalNumber<T>& other);
    RationalNumber<T>& operator*= (const RationalNumber<T>& other);
    RationalNumber<T>& operator/= (const RationalNumber<T>& other);


    bool operator== (const RationalNumber <T>& other) const;
    friend bool operator== (const T& other, const RationalNumber<T>& fraction2);

    bool operator!= (const RationalNumber <T>& other) const;
    friend bool operator!= (const T& other, const RationalNumber<T>& fraction2);

    bool operator< (const RationalNumber <T>& other) const;
    friend bool operator< (const T& other, const RationalNumber<T>& fraction2);

    bool operator> (const RationalNumber <T>& other) const;
    friend bool operator> (T& other, const RationalNumber<T>& fraction2);

    bool operator<= (const RationalNumber <T>& other) const;
    friend bool operator<= (const T& other, const RationalNumber<T>& fraction2);

    bool operator>= (const RationalNumber <T>& other) const;
    friend bool operator>= (const T& other, const RationalNumber<T>& fraction2);

    RationalNumber<T>& operator= (const RationalNumber<T>& other);

    RationalNumber<T>& operator++ ();
    RationalNumber<T>& operator-- ();

    RationalNumber() : numerator_(0), denominator_(1) {}

    RationalNumber(T numerator_, T denominator_);

    ~RationalNumber() = default;

    RationalNumber(const RationalNumber<T>& other);


private:
    T numerator_;
    T denominator_;

    void reduction();
    T gcd(T a, T b);

public:
    RationalNumber Sum(RationalNumber<T> other) ;
    RationalNumber Subtraction(RationalNumber<T> other) ;
    RationalNumber Division(RationalNumber<T> other) ;
    RationalNumber Multiplication(RationalNumber<T> other) ;
};

template <typename T>
RationalNumber<T>::RationalNumber(const RationalNumber<T>& other)
    : numerator_(other.numerator_), denominator_(other.denominator_) {
}

template <typename T>
T RationalNumber<T>::gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


template <typename T>
RationalNumber<T>& RationalNumber<T>::operator+ () {
    reduction();
    return *this;
}

//template <typename T>
//RationalNumber<T> RationalNumber<T>::operator+ (const RationalNumber<T>& other) const {
//    RationalNumber<T> result;
//    result.Sum(other);
//    return result;
//}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator+ (const RationalNumber<T>& other) const {
    auto temp = *this;
    return temp += other;
}

template <typename T>
RationalNumber<T> operator+ (const T& other, const RationalNumber<T>& fraction2) {
    RationalNumber<T> result;
    result.Sum(fraction2);
    return result;
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
    RationalNumber<T> result;
    result.Subtraction(fraction2);
    return result;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator* (const RationalNumber<T>& other) const {
    auto temp = *this;
    return temp *= other;
}

template <typename T>
RationalNumber<T> operator* (const T& other, const RationalNumber<T>& fraction2) {
    RationalNumber<T> result;
    result.Multiplication(fraction2);
    return result;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::operator/ (const RationalNumber<T>& other) const {
    auto temp = *this;
    return temp /= other;
}

template <typename T>
RationalNumber<T> operator/ (const T& other, const RationalNumber<T>& fraction2) {
    RationalNumber<T> result;
    result.Division(fraction2);
    return result;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator+=(const RationalNumber<T>& other) {
    denominator_ = denominator_ * other.denominator_;
    numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_ / other.denominator_;
    reduction();
    return *this;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator-=(const RationalNumber<T>& other) {
    denominator_ = denominator_ * other.denominator_;
    numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_ / other.denominator_;
    reduction();
    return *this;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator*= (const RationalNumber<T>& other) {
    this->denominator_ = denominator_ * other.denominator_;
    this->numerator_ = numerator_ * other.numerator_;
    this->reduction();
    return *this;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator/= (const RationalNumber<T>& other) {
    this->denominator_ = denominator_ * other.numerator_;
    this->numerator_ = numerator_ * other.denominator_;
    this->reduction();
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
bool RationalNumber<T>::operator!= (const RationalNumber <T>& other) const {
    return !(numerator_ == other.numerator_ && denominator_ == other.denominator_);
}

template <typename T>
bool operator!= (const T& other, const RationalNumber<T>& fraction2) {
    RationalNumber <T> fr;
    fr.numerator_ = other;
    fr.denominator_ = 1;
    return !(fr.numerator_ == fraction2.numerator_ && fr.denominator_ == fraction2.denominator_);
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
bool RationalNumber<T>::operator<= (const RationalNumber <T>& other) const {
    return (*this < other || *this == other);
}

template <typename T>
bool operator<= (const T& other, const RationalNumber<T>& fraction2) {
    RationalNumber <T> fr;
    fr.numerator_ = other;
    fr.denominator_ = 1;
    return ((fr.numerator_ * fraction2.denominator_ < fraction2.numerator_ * fr.denominator_)
        || (fr.numerator_ == fraction2.numerator_ && fr.denominator_ == fraction2.denominator_));
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
    return (fr.numerator_ * fraction2.denominator_ > fraction2.numerator_ * fr.denominator_
        || fr.numerator_ == fraction2.numerator_ && fr.denominator_ == fraction2.denominator_);
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator++ () {
    RationalNumber <T> res;
    res.numerator_ = 1;
    res.denominator_ = 1;
    this->Sum(res);
    return *this;
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator-- () {
    RationalNumber <T> res;
    res.numerator_ = 1;
    res.denominator_ = 1;
    this->Subtraction(res);
    return *this;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const RationalNumber<U>& fraction) {
    os << fraction.numerator_ << "/" << fraction.denominator_;
    return os;
}



template <typename T>
RationalNumber<T>::RationalNumber(T numerator, T denominator) : numerator_(numerator), denominator_(denominator) {
    reduction();
}

template <typename T>
RationalNumber<T>& RationalNumber<T>::operator= (const RationalNumber<T>& other){
    if (this != &other) {
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
    }
    return *this;
}

template <typename T>
void RationalNumber<T>::reduction() {
    T g = gcd(denominator_, numerator_);
    denominator_ /= g;
    numerator_ /= g;
}

//template <typename T>
//RationalNumber<T> RationalNumber<T>::Sum(RationalNumber<T> other) {
//    T resDen = denominator_ * other.denominator_;
//    T resNum = numerator_ * other.denominator_ + other.numerator_ * denominator_;
//    RationalNumber<T> res(resNum, resDen);
//
//    res.reduction();
//    *this += res;
//    return *this;
//}

template <typename T>
RationalNumber<T> RationalNumber<T>::Sum(RationalNumber<T> other)  {
    return *this + other;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::Subtraction(RationalNumber<T> other)  {
    return *this - other;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::Division(RationalNumber<T> other)  {
    this->denominator_ = denominator_ * other.numerator_;
    this->numerator_ = numerator_ * other.denominator_;
    this->reduction();
    return *this;
}

template <typename T>
RationalNumber<T> RationalNumber<T>::Multiplication(RationalNumber<T> other)  {
    this->denominator_ = denominator_ * other.numerator_;
    this->numerator_ = numerator_ * other.denominator_;
    this->reduction();
    return *this;
}
#endif // RATIONAL_NUMBER_H_
