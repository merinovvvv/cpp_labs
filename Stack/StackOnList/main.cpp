#include <iostream>
#include "StackOnList.h"

int main() {
	try {
		StackOnList<int> s;
		s.push(3);
		s.pop();
		s.top() = 5;
		std::cout << s.top() << "\n";
	}
	catch (std::runtime_error& ex) {
		std::cerr << ex.what();
	}
	return 0;
}