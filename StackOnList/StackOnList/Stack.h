#pragma once
#ifndef STACK_H_
#define STACK_H_

template <class T>
class Stack {
public:

	void swap(Stack& other) {
		std::swap(top_, other.top_);
	}

	struct Node {
		T data = T();
		Node* next = nullptr;
	};

	Stack() = default;

	Stack(const Stack& other) : Stack() {
		Stack tmp;
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

	Stack(Stack&& other) noexcept : Stack() {
		swap(other);
	};

	Stack& operator= (const Stack& other) {
		if (this != other) {
			Stack tmp(other);
			swap(tmp);
		}
	}

	Stack& operator= (Stack&& other) noexcept {
		if (this != &other) {
			swap(other);
		}
		return *this;
	}

	~Stack() {
		Delete();
	}

	void push(T x) {
		Node* tmp = new Node{ x, top_ };
		top_ = tmp;
	}

	void pop() {
		Node* tmp = top_;
		top_ = top_->next;
		delete tmp;
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

#endif //STACK_H_