#include "../header/and.h"
And::And(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
	//cout << "Left Child of && Connector = " << leftChild << endl;
	//cout << "Right Child of && Connector = " << rightChild << endl;
}
        
bool And::execute(int in, int out){
	return (leftChild->execute(in,out) && rightChild->execute(in,out));
}
