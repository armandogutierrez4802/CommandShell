#ifndef connector_h
#define connector_h

#include "commandLine.h"

class Connectors: public CommandLine  {
protected:
        CommandLine* leftChild;
	CommandLine* rightChild;
	CommandLine* command;
public:
        bool execute();
        virtual void addLeftChild();
	virtual void addRightChild();
	virtual void addCommand();
};

#endif /* connector_h */
