#include "../header/outputRed.h"

OutputRed::OutputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool OutputRed::execute(int in, int out){
	string outputFile = rightChild->getFileName();
	out = open(outputFile.c_str(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	if(leftChild->execute(0,out)){
		close(out);
		return true;
	} else{
		close(out);
		return false;
	}		



}


