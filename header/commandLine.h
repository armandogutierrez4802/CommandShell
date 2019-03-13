#include <iostream>
using namespace std;
#ifndef commandLine_h
#define commandLine_h

class CommandLine {
public:
    virtual bool execute(int in, int out) = 0;
    //virtual string stringify(){};
};

#endif /* commandLine_h */
