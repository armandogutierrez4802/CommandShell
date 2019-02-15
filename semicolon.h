#ifndef semicolon_h
#define semicolon_h

#include "commandLine.h"
#include <string>

class Semicolon: public Connectors  {
public:
        bool execute();
        void addLeftChild();
	void addRightChild();
};

#endif /* semicolon_h */
