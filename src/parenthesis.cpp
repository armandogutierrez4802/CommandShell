#include "../header/parenthesis.h"
#include <iostream>
Parenthesis::Parenthesis(CommandLine* onlyChild) {
	this->leftChild = onlyChild;
}
        
bool Parenthesis::execute(int in, int out){
	//cout << "my () child is -> " << leftChild << endl;
	return leftChild->execute(in,out);
}


/*
Notes on how to solve parenthesis:
- Since we can have multiple parenthesis, have the flag be an int, rather than a bool, and have countParen == 0 be check for push onto "real/final" tree
- Maybe when we come across the first parenthesis, we call a void function where we deal with all of the parenthesis in, and then return the final subtree
	-> This subtree may contain multiple parenthesis or none.

*/


