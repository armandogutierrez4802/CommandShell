#include "../header/semicolon.h"

Semicolon::Semicolon(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool Semicolon::execute(int in, int out){
	leftChild->execute(in,out);

	cout << "WHAT IS GOING ON HERE??????" << endl;

	if(rightChild->execute(in,out)){
		return true;
	} else{
		return false;
	}
}
