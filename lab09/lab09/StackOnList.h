#ifndef STACK_ON_LIST_H_
#define STACK_ON_LIST_H_

#include <exception>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

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
		int key_;
		Node* next_;
		Node() : next_(nullptr) {
			spdlog::trace("Node default costr.");
		}
		Node(int key) : key_(key), next_(nullptr) {
			spdlog::trace("Node costr with nullptr.");

		}
		Node(int key, Node* next) : key_(key), next_(next) {
			spdlog::trace("Node costr.");
		}
	};
	Node* top_;
	static std::shared_ptr<spdlog::logger> logger;
};
std::shared_ptr<spdlog::logger> StackOnList::logger = spdlog::basic_logger_mt("stackOnList-logger", "logs/basic-log.txt");

StackOnList::StackOnList() : top_(nullptr) {
	logger->debug("Stack is created");
}
StackOnList::~StackOnList() {
	while (top_) {
		pop();
	}
}
void StackOnList::push(int value) {
	logger->trace("StackOnList::push.");
	Node* tmp = new Node(value, top_);
	top_ = tmp;

	logger->debug("The {0} has been pushed to {1}.", value, tmp->key_);
}

int StackOnList::pop() {
	int result = top_->key_;
	Node* tmp = top_;
	top_ = top_->next_;
	delete tmp;
	return result;
}

bool StackOnList::isEmpty() const {
	return (top_ == nullptr);
}

int StackOnList::top() const {
	if (!top_) {
		logger->warn("No elements.");
		throw std::logic_error ("No elements in stack.");
	}
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