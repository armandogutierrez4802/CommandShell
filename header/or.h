#ifndef or_h
#define or_h

#include "connectors.h"

class Or : public Connectors {
public:
	Or(CommandLine* leftChild, CommandLine* rightChild);
        bool execute(int in, int out);
};

#endif /* or_h */
