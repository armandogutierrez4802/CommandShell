#include "../header/and.h"
And::And(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool And::execute(){
	return (leftChild->execute() && rightChild->execute());
}
