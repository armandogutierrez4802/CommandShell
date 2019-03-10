#ifndef outputRed_h
#define outputRed_h

#include "connectors.h"

class OutputRed : public Connectors  {
public:
	OutputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();
  
};

#endif /* outputRed_h */
