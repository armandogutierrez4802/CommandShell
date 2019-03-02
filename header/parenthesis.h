#ifndef parenthesis_h
#define parenthesis_h

#include "connectors.h"

class Parenthesis: public Connectors  {
public:
	Parenthesis(CommandLine* onlyChild);
        bool execute();
  
};

#endif /* parenthesis_h */
