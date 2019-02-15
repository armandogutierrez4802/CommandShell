#ifndef or_h
#define or_h

#include "connectors.h"

class Or: public Connectors  {
public:
        bool execute();
        void addLeftChild();
	void addRightChild();
};

#endif /* or_h */
