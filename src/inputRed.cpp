#include "../header/inputRed.h"

InputRed::InputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool InputRed::execute(int in, int out){
	return true;
}
