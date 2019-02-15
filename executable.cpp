#include "executable.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

Executable::Executable(string argument, int numArguments){
	this->arg = argument;
	this->numArg = numArguments;
}

bool Executable:execute(){
	char* args[numArg+1];
	string delimiter = " ";
	size_t pos = 0;
	string token;
	int i = 0;
	
	while((pos = s.find(delimiter)) != std::string::npos){
		token = s.substr(0,pos);
		args[i] = (char*)token.c_str();	
		s.erase(0,pos + delimiter.length());
		i++;
	}	
	
	args[i] = NULL;

}

