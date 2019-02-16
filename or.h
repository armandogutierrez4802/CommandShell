#ifndef or_h
#define or_h

#include "connectors.h"

class Or : public Connectors {
public:
	Or(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();
};

#endif /* or_h */
