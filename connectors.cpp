#include "connectors.h"

Connectors::Connectors(CommandLine* leftChild, CommandLine* rightChild){	
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}

virtual bool Connectors::execute(){}
