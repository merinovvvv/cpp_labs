#include <iostream>
#include <cstring>
#include "String.h"

String::String() {
	size = 0;
	capacity = 16;
	str = new char[capacity];
	str[0] = '\0';
}

String::String(const char* other) {
	size = strlen(other);
	str = new char[size + 1];
	for (size_t i = 0; i < size; ++i) {
		str[i] = other[i];
	}
	str[size] = '\0';
}

String::String(int count, char ch) {
	size = count;
	str = new char[count + 1];
	for (size_t i = 0; i < count; ++i) {
		str[i] = ch;
	}
	str[count] = '\0';
}


String::String(const String& other) {
	size = other.size;
	str = new char[size + 1];
	for (size_t i = 0; i < other.size; ++i) {
		str[i] = other.str[i];
	}
	str[size] = '\0';
}

String String::operator=(const String& other) {
	if (str != other.str) {
		if (str != nullptr) {
			delete[] str;
		}
		size = other.size;
		str = new char[other.size + 1];
		for (size_t i = 0; i < other.size; ++i) {
			str[i] = other.str[i];
		}
		str[size] = '\0';
	}
	return *this;
}

String::String(String&& other) noexcept {
	size = other.size;
	str = other.str;
	other.str = nullptr;
	other.size = 0;
}

String String::operator=(String&& other) noexcept {
	if (str != other.str) {
		delete[] str;
		size = other.size;
		str = other.str;
		other.str = nullptr;
		other.size = 0;
	}
	return *this;
}

String::~String() {
	if (str != nullptr) {
		delete[] str;
	}
}

int String::length() {
	return size;
}

bool String::empty() {
	return (!size) ? true : false;
}

const char* String::c_str() {
	return str;
}

char& String::operator[](int index) {
	if (index >= size || index < 0) {
		std::cout << "Index is out of bounds, exiting...";
		exit(0);
	}
	return str[index];
}

const char& String::operator[](int index) const {
	if (index >= size || index < 0) {
		std::cout << "Index is out of bounds, exiting...";
		exit(0);
	}
	return str[index];
}

char& String::front() {
	if (str == nullptr || size == 0) {
		std::cout << "The string is empty.";
		exit(0);
	}
	return str[0];
}

char& String::back() {
	if (str == nullptr || size == 0) {
		std::cout << "The string is empty.";
		exit(0);
	}
	return str[size - 1];
}


const char& String::front() const {
	if (str == nullptr) {
		std::cout << "The string is empty.";
	}
	return str[0];
}

const char& String::back() const {
	if (str == nullptr) {
		std::cout << "The string is empty.";
	}
	return str[size];
}

void String::reserve(int capacity) { //TODO
	if (capacity <= size) {
		return;
	}
	char* buffer = new char[capacity];
	if (str != nullptr) {
		for (size_t i = 0; i < size; ++i) {
			buffer[i] = str[i];
		}
		delete[] str;
	}
	str = buffer;
	size = capacity;
}

void String::push_back(char ch) {
	if (size + 1 <= capacity) {
		str[size] = ch;
	}
	else {
		capacity = capacity * 2;
		char* str2 = new char[capacity];
		for (size_t i = 0; i < size; ++i) {
			str2[i] = str[i];
		}
		delete[] str;
		str = str2;
		str[size] = ch;
	}
	++size;
}


void String::pop_back() {
	if (size > 0) {
		--size;
		str[size] = '\0';
	}
	else {
		std::cout << "The string is empty. Cannot pop_back().\n";
	}
}

void String::clear() {
	size = 0;
	if (str != nullptr) {
		str[size] = '\0';
	}
	else {
		std::cout << "The string is already empty.\n";
	}
}

bool String::insert(int index, const String& str) {
	if (index < 0 || index > size) {
		return false;
	}

	int newSize = size + str.size;
	char* buffer = new char[newSize + 1];

	for (size_t i = 0; i < index; ++i) {
		buffer[i] = this->str[i];
	}

	for (size_t i = 0; i < str.size; ++i, ++index) {
		buffer[index] = str[i];
	}

	for (size_t i = index - str.size; i < size; ++i) {
		buffer[index] = this->str[i];
		++index;
	}

	buffer[newSize] = '\0';
	delete[] this->str;
	this->str = buffer;
	size = newSize;

	return true;
}

bool String::insert(int index, const char* str, int count) {
	if (index < 0 || index > size) {
		return false;
	}

	int newSize = size + count;
	char* buffer = new char[newSize + 1];

	for (size_t i = 0; i < index; ++i) {
		buffer[i] = this->str[i];
	}

	for (size_t i = 0; i < count; ++i, ++index) {
		buffer[index] = str[i];
	}

	for (size_t i = index - count; i < size; ++i) {
		buffer[index] = this->str[i];
		++index;
	}

	buffer[newSize] = '\0';
	delete[] this->str;
	this->str = buffer;
	size = newSize;

	return true;
}

bool String::erase(int index, int count) {

	if (index < 0 || index >= size || count <= 0) {
		return false;
	}
		
	int deleteCount = std::min(count, size - index);
	int newSize = size - deleteCount;

	char* buffer = new char[newSize + 1];
	for (size_t i = 0; i < index; ++i) {
		buffer[i] = str[i];
	}
	for (size_t i = index + deleteCount, j = index; i < size; ++i, ++j) {
		buffer[j] = str[i];
	}
	buffer[newSize] = '\0';
	delete[] str;
	str = buffer;
	size = newSize;

	return true;
}

String String::operator+ (const String& other) {
	int newSize = size + other.size;
	char* newBuffer = new char[newSize + 1];

	for (size_t i = 0; i < size; ++i) {
		newBuffer[i] = str[i];
	}

	for (size_t j = 0; j < other.size; ++j) {
		newBuffer[size + j] = other.str[j];
	}

	newBuffer[newSize] = '\0';

	String result(newBuffer);

	delete[] newBuffer;

	return result;
}


String& String::operator+=(const String& other) {
	if (&other != this) {
		*this = *this + other;
	}
	return *this;
}


int String::compare(const String& str) const {
	for (size_t i = 0; i < size && i < str.size; ++i) {
		if (this->str[i] > str.str[i]) {
			return 1;
		}
		else if (this->str[i] < str.str[i]) {
			return -1;
		}
	}
	if (size < str.size) {
		return -1;
	}
	if (size > str.size) {
		return 1;
	}
	return 0;
}

int String::compare(const char* str) const {
	size_t i = 0;
	for (i; i < size && str[i] != '\0'; ++i) {
		if (this->str[i] > str[i]) {
			return 1;
		}
		else if (this->str[i] < str[i]) {
			return -1;
		}
	}

	/*if (size < i) {
		return -1;
	}
	else if (size > i || str[i] != '\0') {
		return 1;
	}
	else {
		return 0;
	}*/

	if (i == size) {
		return 0;
	}

	if (size > i) {
		return 1;
	}

	return -1;
}


// Перегрузка операторов сравнения для String и const char*
bool String::operator==(const char* other) const {
	return compare(other) == 0;
}

bool String::operator!=(const char* other) const {
	return compare(other) != 0;
}

bool String::operator<(const char* other) const {
	return compare(other) == -1;
}

bool String::operator<=(const char* other) const {
	return compare(other) != 1;
}

bool String::operator>(const char* other) const {
	return compare(other) == 1;
}

bool String::operator>=(const char* other) const {
	return compare(other) != -1;
}

// Перегрузка операторов сравнения для String
bool String::operator==(const String& other) const {
	return compare(other) == 0;
}

bool String::operator!=(const String& other) const {
	return compare(other) != 0;
}

bool String::operator<(const String& other) const {
	return compare(other) == -1;
}

bool String::operator<=(const String& other) const {
	return compare(other) != 1;
}

bool String::operator>(const String& other) const {
	return compare(other) == 1;
}

bool String::operator>=(const String& other) const {
	return compare(other) != -1;
}

// Перегрузка операторов сравнения для const char* и String
bool operator==(const char* str, const String& other) {
	return other.compare(str) == 0;
}

bool operator!=(const char* str, const String& other) {
	return other.compare(str) != 0;
}

bool operator<(const char* str, const String& other) {
	return other.compare(str) == -1;
}

bool operator<=(const char* str, const String& other) {
	return other.compare(str) != 1;
}

bool operator>(const char* str, const String& other) {
	return other.compare(str) == -1;
}

bool operator>=(const char* str, const String& other) {
	return other.compare(str) != 1;
}