#pragma once
#ifndef STACK_ON_LIST_H_
#define STACK_ON_LIST_H_

template <class T>
class StackOnList {
public:

	void swap(StackOnList& other) {
		std::swap(top_, other.top_);
	}

	struct Node {
		T data = T();
		Node* next = nullptr;
	};

	StackOnList() = default;

	StackOnList(const StackOnList& other) : StackOnList() {
		StackOnList tmp;
		Node* tmp_top = other.top_;
		while (tmp_top != nullptr) {
			tmp.push(tmp_top->data);
			tmp_top = tmp_top->next;
		}

		tmp_top = tmp.top_;
		while (tmp_top != nullptr) {
			this->push(tmp_top->data);
			tmp_top = tmp_top->next;
		}
	}

	StackOnList(StackOnList&& other) noexcept : StackOnList() {
		swap(other);
	};

	StackOnList& operator= (const StackOnList& other) {
		if (this != other) {
			StackOnList tmp(other);
			swap(tmp);
		}
	}

	StackOnList& operator= (StackOnList&& other) noexcept {
		if (this != &other) {
			swap(other);
		}
		return *this;
	}

	~StackOnList() {
		Delete();
	}

	void push(T x) {
		Node* tmp = new Node{ x, top_ };
		top_ = tmp;
	}

	T pop() {
		T result = top_->data;
		Node* tmp = top_;
		top_ = top_->next;
		delete tmp;
		return result;
	}


	T& top() {
		if (top_ == nullptr) {
			throw std::runtime_error("top is nullptr.");
		}
		return top_->data;
	}

	T top() const {
		if (top_ == nullptr) {
			throw std::runtime_error("top is nullptr.");
		}
		return top_->data;
	}

	bool isEmpty() const {
		return top_ == nullptr;
	}

private:
	Node* top_ = nullptr;
	void Delete() {
		while (top_ != nullptr) {
			Node* temp = top_->next;
			delete top_;
			top_ = temp;
		}
	}

};

#endif //STACK_ON_LIST_H_