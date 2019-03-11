#ifndef semicolon_h
#define semicolon_h

#include "connectors.h"

class Semicolon: public Connectors  {
public:
	Semicolon(CommandLine* leftChild, CommandLine* rightChild);
        bool execute(int in, int out);

};

#endif /* semicolon_h */
