#ifndef and_h
#define and_h

#include "connectors.h"

class And: public Connectors  {
public:
	And(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();
  
};

#endif /* and_h */
