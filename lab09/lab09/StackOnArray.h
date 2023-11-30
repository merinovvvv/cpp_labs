//#pragma once
//#ifndef STACK_ON_ARRAY_H
//#define STACK_ON_ARRAY_H
//class StackOnList
//{
//public:
//	StackOnList();
//	~StackOnList();
//	StackOnList(const StackOnList& other) = default;
//	StackOnList& operator= (const StackOnList& other) = default;
//	StackOnList(StackOnList&& other) = default;
//	StackOnList& operator= (StackOnList&& moved) = default;
//
//	void push(int value);
//	int pop();
//private:
//	struct Node 
//	{
//		Node(): next_ (nullptr){}
//		Node(int key) : key_(key), next_(nullptr) {}
//		Node(int key, Node* next) : key_(key), next_(next){}
//		int key_;
//		Node* next_;
//	};
//	Node* top_;
//};
//
//StackOnList::StackOnList() : top_ (nullptr){} 
//StackOnList::~StackOnList() {
//	while (top_) {
//		pop();
//	}
//}
//void StackOnList::push(int value){
//	Node* tmp = new Node(value, top_);
//	top_ = tmp;
//}
//
//int StackOnList::pop() {
//	int result = top_->key_;
//	Node* tmp = top_;
//	top_ = top_->next_;
//	delete tmp;
//	return result;
//}
//
//
//
//
//#endif //STACK_ON_ARRAY_H