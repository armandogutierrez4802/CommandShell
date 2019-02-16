#ifndef executable_h
#define executable_h

#include "commandLine.h"
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

class Executable: public CommandLine  {
private:
	vector<char*> cmTokens;
	int numArguments;
	//std::string temp;
	//char** charArg;
public:
	Executable(vector<char*> cmTokens, int numArguments);
	bool execute();
	//void createArgList(string);
};

#endif /* executable_h */
