#include "../header/pipe.h"

Pipe::Pipe(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool Pipe::execute(){
	return true;
}
