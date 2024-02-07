#pragma once
#ifndef STACK_ON_ARRAY_H
#define STACK_ON_ARRAY_H

#include <initializer_list>
#include <cassert>
#include <vector>

template<class T>
class StackOnArray {
public:
	StackOnArray();
	~StackOnArray();
	StackOnArray(const std::initializer_list<T>& list);
	StackOnArray(const StackOnArray& other);
	StackOnArray& operator=(const StackOnArray& other);
	StackOnArray(StackOnArray&& moved);
	StackOnArray& operator=(StackOnArray&& moved);
	bool operator== (const StackOnArray& other);

	void push(const T& value);
	T pop();
	T& top();
	bool isEmpty();
	size_t size();
private:
	T* array_;
	T top_;
	size_t capacity_;
};

template<class T>
StackOnArray<T>::StackOnArray()
{
	capacity_ = 10;
	array_ = new T[capacity_];
	top_ = -1;
}

template<class T>
StackOnArray<T>::~StackOnArray()
{
	delete[] array_;
}

template<class T>
void StackOnArray<T>::push(const T& value)
{
	if (top_ == capacity_ - 1) {
		T* new_arr = new T[2 * capacity_];
		for (int i = 0; i <= top_; ++i) {
			new_arr[i] = array_[i];
		}
		delete[] array_;
		array_ = new_arr;
		capacity_ *= 2;
	}
	array_[++top_] = value;
}

template<class T>
T& StackOnArray<T>::top()
{
	assert(top_ != -1 && "No elements in stack");
	return array_[top_];
}

template<class T>
T StackOnArray<T>::pop()
{
	assert(top_ != -1 && "No elements in stack");
	T tmp = array_[top_];
	top_--;
	return tmp;
}

template<class T>
bool StackOnArray<T>::isEmpty()
{
	return (top_ == -1);
}

template<class T>
size_t StackOnArray<T>::size()
{
	return (top_ + 1);
}

template<class T>
StackOnArray<T>::StackOnArray(const std::initializer_list<T>& list) :StackOnArray()
{
	for (const auto element : list) {
		push(element);
	}
}

template<class T>
StackOnArray<T>::StackOnArray(const StackOnArray& other) :StackOnArray()
{
	capacity_ = other.capacity_;
	top_ = other.top_;
	T* tmp = new T[capacity_];
	for (size_t i = 0; i <= top_; i++) {
		tmp[i] = other.array_[i];
	}
	array_ = tmp;
}

template<class T>
StackOnArray<T>& StackOnArray<T>::operator=(const StackOnArray& other)
{
	capacity_ = other.capacity_;
	top_ = other.top_;
	T* tmp = new T[capacity_];
	for (size_t i = 0; i <= top_; i++) {
		tmp[i] = other.array_[i];
	}
	array_ = tmp;
}

template<class T>
StackOnArray<T>::StackOnArray(StackOnArray&& moved) :StackOnArray()
{
	capacity_ = moved.capacity_;
	top_ = moved.top_;
	T* tmp = new T[capacity_];
	for (size_t i = 0; i <= top_; i++) {
		tmp[i] = moved.array_[i];
	}
	while (!moved.isEmpty()) {
		moved.pop();
	}
	array_ = tmp;
}

template<class T>
StackOnArray<T>& StackOnArray<T>::operator=(StackOnArray&& moved)
{
	capacity_ = moved.capacity_;
	top_ = moved.top_;
	T* tmp = new T[capacity_];
	for (size_t i = 0; i <= top_; i++) {
		tmp[i] = moved.array_[i];
	}
	while (!moved.isEmpty()) {
		moved.pop();
	}
	array_ = tmp;
}

template<class T>
bool StackOnArray<T>::operator== (const StackOnArray& other)
{
	if (other.top_ != top_) {
		return false;
	}
	else {
		for (size_t i = 0; i <= top_; ++i) {
			if (array_[i] != other.array_[i]) {
				return false;
			}
		}
	}
	return true;
}
#endif // STACK_ON_ARRAY_H