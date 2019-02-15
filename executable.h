#ifndef executable_h
#define executable_h

#include "commandLine.h"
#include <string>

class Executable: public CommandLine  {
private:
	std::string argument;
	int numArg;
	std::string temp;
	char** charArg;
public:
	Executable(string argument, int numArguments)
	bool execute();
	//void createArgList(string);
};

#endif /* executable_h */
