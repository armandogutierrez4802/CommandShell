#include "../header/inputRed.h"

InputRed::InputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool InputRed::execute(){
	return true;
}
