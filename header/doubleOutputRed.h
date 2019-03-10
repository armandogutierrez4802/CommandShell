#ifndef doubleoutputred_h
#define doubleoutputred_h

#include "connectors.h"

class DoubleOutputRed : public Connectors  {
public:
	DoubleOutputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();
  
};

#endif /* doubleoutputred_h */
