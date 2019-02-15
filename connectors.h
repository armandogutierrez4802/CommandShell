#ifndef connectors_h
#define connectors_h

#include "commandLine.h"
#include <string>

class Connectors: public CommandLine  {
protected:
        CommandLine* leftChild;
	CommandLine* rightChild;
public:
        Connectors(CommandLine* leftChild, CommandLine* rightChild);
	bool execute();
        
};

#endif /* connectors_h */
