#include "../header/outputRed.h"

OutputRed::OutputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool OutputRed::execute(int in, int out){
	return true;
}
