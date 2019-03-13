#ifndef outputRed_h
#define outputRed_h

#include "connectors.h"

class OutputRed : public Connectors  {
public:
	OutputRed(CommandLine* leftChild, CommandLine* rightChild);
        bool execute(int in, int out);
	void setFileName(char * file);
        string getFileName(); 
};

#endif /* outputRed_h */
