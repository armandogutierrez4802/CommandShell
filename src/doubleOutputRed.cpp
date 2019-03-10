#include "../header/doubleOutputRed.h"

DoubleOutputRed::DoubleOutputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool DoubleOutputRed::execute(){
	return true;
}
