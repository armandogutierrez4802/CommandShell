#ifndef doubleOutputRed_h
#define doubleOutputRed_h

#include "connectors.h"

class DoubleOutputRed : public Connectors  {
public:
	DoubleOutputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();
  
};

#endif /* doubleOutputRed_h */
