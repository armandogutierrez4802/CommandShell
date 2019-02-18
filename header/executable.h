#ifndef executable_h
#define executable_h

#include "commandLine.h"
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
class Executable: public CommandLine  {
private:
	vector<char*> cmTokens;
	int numArguments;
public:
	Executable(vector<char*> cmTokens, int numArguments);
	bool execute();
};

#endif /* executable_h */
