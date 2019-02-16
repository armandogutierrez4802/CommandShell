#include "connectors.h"

Connectors::Connectors(CommandLine* leftChild, CommandLine* rightChild){	
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}

 bool Connectors::execute(){}
