#ifndef inputRed_h
#define inputRed_h

#include "connectors.h"

class InputRed : public Connectors  {
public:
	InputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute(int in, int out);
  
};

#endif /* inputRed_h */
