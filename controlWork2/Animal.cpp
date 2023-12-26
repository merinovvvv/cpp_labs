#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS
#include "spdlog/spdlog.h"

#include <string>
#include <sstream>

#include "Date.h"
#include "Animal.h"


Animal::Animal(std::string nickName, Date dateOfBirth)
    : dateOfBirth_(dateOfBirth), log_(spdlog::get("animalLog")) {
    log_->trace("Animal Ctor");

    nickName_ = new char[nickName.size() + 1];
    std::strcpy(nickName_, nickName.c_str());
}

Animal::Animal(const Animal& other)
    : nickName_(new char[std::strlen(other.nickName_) + 1]), dateOfBirth_(other.dateOfBirth_) {
    std::strcpy(nickName_, other.nickName_);
    log_ = other.log_;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        delete[] nickName_;
        nickName_ = new char[std::strlen(other.nickName_) + 1];
        std::strcpy(nickName_, other.nickName_);

        dateOfBirth_ = other.dateOfBirth_;
        log_ = other.log_;
    }
    return *this;
}

Animal::Animal(Animal&& other)
    : nickName_(other.nickName_), dateOfBirth_(other.dateOfBirth_), log_(std::move(other.log_)) {
    other.nickName_ = nullptr;
}

Animal& Animal::operator=(Animal&& other) {
    if (this != &other) {
        delete[] nickName_;

        nickName_ = other.nickName_;
        dateOfBirth_ = other.dateOfBirth_;
        log_ = std::move(other.log_);

        other.nickName_ = nullptr;
    }
    return *this;
}

Animal::~Animal() {
    log_->debug("Animal Dtor");

    delete[] nickName_;
}

std::string Animal::name() const noexcept {
    return std::string(nickName_);
}

Date Animal::dateOfBirth() const noexcept {
    return dateOfBirth_;
}

int Animal::age() const noexcept {
    return dateOfBirth_.age();
}

int Animal::age(const Date& date) const noexcept {
    return dateOfBirth_.age(date);
}

std::string Animal::toString() const noexcept {
    return "Animal: " + std::string(nickName_) + ", Date of Birth: " + dateOfBirth_.toString();
}