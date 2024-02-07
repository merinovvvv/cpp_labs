#include "BinaryPlus.h"
#include "StackOnList.h"

Number* BinaryPlus::calcValue(StackOnList<Number*>& stack) const {
	Number* rightOperand = stack.pop();
	Number* leftOperand = stack.pop();
	return new Number((*leftOperand) + (*rightOperand));
}
