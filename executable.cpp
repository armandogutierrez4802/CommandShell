#include "executable.h"

Executable::Executable(vector<char*> cmTokens, int numArguments){
	this->cmTokens = cmTokens;
	this->numArguments = numArguments;
}

void Executable::display(){
	for(int i = 0; i < numArguments; i++){
		cout << cmTokens[i] << " ";	
	}
}

bool Executable::execute(){
	char* args[numArguments+1];
	bool returnValue;
	
	for(int i = 0; i < numArguments; i++){
		args[i] = cmTokens.at(i);
	}
	
	args[numArguments] = NULL;
		
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





