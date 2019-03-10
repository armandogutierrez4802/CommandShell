#ifndef inputRed_h
#define inputRed_h

#include "connectors.h"

class InputRed : public Connectors  {
public:
	InputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute();
  
};

#endif /* inputRed_h */
