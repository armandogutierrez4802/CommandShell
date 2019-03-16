#include "../header/outputRed.h"

OutputRed::OutputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool OutputRed::execute(int in, int out){
	string outputFile = rightChild->getFileName();
	out = open(outputFile.c_str(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	int originalOut = dup(1);

	if(leftChild->execute(in,out)){//Im changing 0 to in
		dup2(originalOut,1);
		close(out);
		return true;
	} else{
		dup2(originalOut,1);
		close(out);
		return false;
	}		



}


