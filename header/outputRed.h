#ifndef outputred_h
#define outputred_h

#include "connectors.h"

class OutputRed : public Connectors  {
public:
	OutputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();
  
};

#endif /* outputred_h */
