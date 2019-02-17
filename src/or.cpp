#include "../header/or.h"

Or::Or(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool Or::execute(){
	return (leftChild->execute() || rightChild->execute());
}
