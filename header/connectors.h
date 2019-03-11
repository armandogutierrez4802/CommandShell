#ifndef connectors_h
#define connectors_h

#include "commandLine.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

class Connectors: public CommandLine  {
protected:
        CommandLine* leftChild;
	CommandLine* rightChild;
public:
	Connectors();
        //Connectors(CommandLine* leftChild, CommandLine* rightChild);
	bool execute(int in, int out);
        
};

#endif /* connectors_h */
