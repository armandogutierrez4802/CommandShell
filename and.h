#ifndef and_h
#define and_h

#include "connectors.h"

class And: public Connectors  {
public:
        bool execute();
        void addLeftChild();
	void addRightChild();
};

#endif /* and_h */
