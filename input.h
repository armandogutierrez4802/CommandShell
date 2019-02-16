#ifndef input_h
#define input_h

#include "commandLine.h"
#include <string>
#include <vector>

class Input: public CommandLine  {
protected:
	std::string userInput;
        //vector<std::string*> result;
	vector<char*> commandTokens; 
	vector<char*> connectorTokens;
	vector<CommandLine*> commandObjects;
	vector<CommandLine*> connectObjects;
	vector<CommandLine*> tree;
public:
	Input(std::string userInput);
        bool execute();
        std::string parse();
	void singleCommand();
	void createTree();
	void initShell();
};

#endif /* input_h */
