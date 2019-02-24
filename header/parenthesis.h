#ifndef and_h
#define and_h

#include "connectors.h"

class Parenthesis: public Connectors  {
public:
	Parenthesis(CommandLine* onlyChild);
        bool execute();
  
};

#endif /* and_h */
