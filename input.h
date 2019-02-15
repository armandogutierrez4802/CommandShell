#ifndef input_h
#define input_h

#include "commandLine.h"
#include <string>
#include <vector>

class Input: public CommandLine  {
protected:
        vector<std::string*> result;
	vector<CommandLine*> commandline;
	vector<CommandLine*> argList;
public:
        bool execute();
        std::string parse();
	void singleCommand();
	void createTree();
	void initShell();
};

#endif /* input_h */
