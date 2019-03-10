#ifndef inputred_h
#define inputred_h

#include "connectors.h"

class InputRed : public Connectors  {
public:
	InputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();
  
};

#endif /* inputred_h */
