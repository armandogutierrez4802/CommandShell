#include "../header/outputRed.h"

OutputRed::OutputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool OutputRed::execute(int in, int out){
	//string outputFile = ???;
	out = open(outputFile.c_str(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	return leftChild->execute(0,out);
}
