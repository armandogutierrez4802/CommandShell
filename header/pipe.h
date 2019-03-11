#ifndef pipe_h
#define pipe_h

#include "connectors.h"

class Pipe : public Connectors  {
public:
	Pipe(CommandLine* leftChild, CommandLine* rightChild);
        bool execute(int in, int out);
  
};

#endif /* pipe_h */
