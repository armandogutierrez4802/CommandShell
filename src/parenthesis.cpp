#include "../header/parenthesis.h"
#include <iostream>
Parenthesis::Parenthesis(CommandLine* onlyChild) {
	this->leftChild = onlyChild;
	this->rightChild = nullptr;
}
        
bool Parenthesis::execute(int in, int out){
	//cout << "my () in = " << in << endl;
	//cout << "my () out = " << out << endl;
	if(leftChild->execute(in,out)){
		//cout << "After () execute true" << endl;
		return true;
	} else{
		//cout << "After () execute false" << endl;
		return false;
	}

}

