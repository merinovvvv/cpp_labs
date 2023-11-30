#pragma once
#ifndef STACK_ON_LIST_H_
#define STACK_ON_LIST__H
class StackOnList
{
public:
	StackOnList();
	~StackOnList();
	StackOnList(const StackOnList& other);
	StackOnList& operator= (const StackOnList& other) = default;
	StackOnList(StackOnList&& other) = default;
	StackOnList& operator= (StackOnList&& moved) = default;

	void push(int value);
	int pop();
	int top() const;
	bool isEmpty() const;
private:
	struct Node
	{
		Node() : next_(nullptr) {}
		Node(int key) : key_(key), next_(nullptr) {}
		Node(int key, Node* next) : key_(key), next_(next) {}
		int key_;
		Node* next_;
	};
	Node* top_;
};

StackOnList::StackOnList() : top_(nullptr) {}
StackOnList::~StackOnList() {
	while (top_) {
		pop();
	}
}
void StackOnList::push(int value) {
	Node* tmp = new Node(value, top_);
	top_ = tmp;
}

int StackOnList::pop() {
	int result = top_->key_;
	Node* tmp = top_;
	top_ = top_->next_;
	delete tmp;
	return result;
}

bool StackOnList::isEmpty() const{
	return (top_ == nullptr);
}

int StackOnList::top() const {
	return top_->key_;
}

StackOnList::StackOnList(const StackOnList& other) :StackOnList() {
	StackOnList tmp;
	Node* currentTop = other.top_;
	while (currentTop) {
		tmp.push(currentTop->key_);
		currentTop = currentTop->next_;
	}
	currentTop = tmp.top_;
	while (!tmp.isEmpty()) {
		(*this).push(tmp.pop()); //may be without *this
	}
}

#endif //STACK_ON_LIST_H_