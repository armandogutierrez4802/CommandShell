#include "../header/inputRed.h"

InputRed::InputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool InputRed::execute(int in, int out){
	//string inputFile = ???;
	in = open(inputFile.c_str(),O_RDONLY);

	return leftChild->execute(in,1);
}
