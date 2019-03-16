#include "../header/parenthesis.h"
#include <iostream>
Parenthesis::Parenthesis(CommandLine* onlyChild) {
	this->leftChild = onlyChild;
	this->rightChild = nullptr;
}
        
bool Parenthesis::execute(int in, int out){
	cout << "my () child is -> " << leftChild << endl;
	return leftChild->execute(in,out);
}



