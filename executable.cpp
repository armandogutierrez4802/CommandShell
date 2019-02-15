#include "executable.h"

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
	bool returnValue;
	
	while((pos = s.find(delimiter)) != std::string::npos){
		token = s.substr(0,pos);
		args[i] = (char*)token.c_str();	
		s.erase(0,pos + delimiter.length());
		i++;
	}	
	
	args[i] = NULL;
		
	pid_t pid = fork();
	if(pid == -1){
		perror("error in fork");
	} else if(pid == 0){//Child Process
		if(execvp(args[0], args) == -1){
		returnValue = false;
		perror("error in execvp");
		exit(1);
		}
	} else if(pid > 0){//Parent Process
		int status;
		if(waitpid(pid,&status,0) == -1){//Pause Parent
          		perror("Error in parent wait");
		}
	}
	return returnValue;
}





