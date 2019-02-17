#include "../header/semicolon.h"

Semicolon::Semicolon(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool Semicolon::execute(){
	leftChild->execute();
	if(rightChild->execute()){
		return true;
	} else{
		return false;
	}
}
