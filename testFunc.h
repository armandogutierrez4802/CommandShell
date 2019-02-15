#ifndef testFunc_h
#define testFunc_h

#include "commandLine.h"
#include <string>

class TestFunc: public CommandLine  {
private:
        std::string input;
        int numArg;
        std::string arg;
        std::string temp;
	int flag;
public:
        bool execute();
        void createArgList(string);
};

#endif /* testFunc_h */
