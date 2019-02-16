#ifndef semicolon_h
#define semicolon_h

#include "commandLine.h"

class Semicolon: public Connectors  {
public:
	Semicolon(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();

};

#endif /* semicolon_h */
