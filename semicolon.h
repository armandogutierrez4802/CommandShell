#ifndef semicolon_h
#define semicolon_h

#include "commandLine.h"

class Semicolon: public Connectors  {
public:
        bool execute();
        void addLeftChild();
	void addRightChild();
};

#endif /* semicolon_h */
