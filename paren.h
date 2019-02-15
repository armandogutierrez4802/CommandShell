#ifndef paren_h
#define paren_h

#include "connectors.h"

class Parenthesis: public CommandLine  {
public:
        bool execute();
        void addLeftChild();
	void addRightChild();
	void addCommand();
};

#endif /* paren_h */
