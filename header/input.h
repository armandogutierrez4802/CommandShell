#ifndef input_h
#define input_h

#include "commandLine.h"
#include "executable.h"
#include "connectors.h"
#include "or.h"
#include "and.h"
#include "semicolon.h"
#include "parenthesis.h"
#include <string>
#include <string.h>
#include <vector>

using namespace std;
class Input: public CommandLine  {
private:
	std::string userInput;
        //vector<std::string*> result;
	vector<char*> commandTokens;
	vector<char*> connectorTokens;
	vector<CommandLine*> commandObjects;
	vector<CommandLine*> connectorObjects;
public:
	Input(std::string userInput);
        bool execute();
};

#endif /* input_h */
