#include "../header/doubleOutputRed.h"

DoubleOutputRed::DoubleOutputRed(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool DoubleOutputRed::execute(int in, int out){
	string outputFile = rightChild->getFileName();
	out = open(outputFile.c_str(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

    	return leftChild->execute(0,out);
}

void setFileName(char* file){

}

string getFileName(){

}
