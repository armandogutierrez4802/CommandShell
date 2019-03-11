#include "../header/or.h"

Or::Or(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool Or::execute(int in, int out){
	return (leftChild->execute(in,out) || rightChild->execute(in,out));
}
