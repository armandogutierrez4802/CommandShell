#ifndef doubleOutputRed_h
#define doubleOutputRed_h

#include "connectors.h"

class DoubleOutputRed : public Connectors  {
public:
	DoubleOutputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute(int in, int out);
	void setFileName(char * file);
        string getFileName();  
};

#endif /* doubleOutputRed_h */
