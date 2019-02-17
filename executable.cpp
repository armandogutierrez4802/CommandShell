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
	
	for(int i = 0; i < numArguments; i++){
		args[i] = cmTokens.at(i);
	}
	
	args[numArguments] = NULL;
		
	pid_t pid = fork();
	if(pid == -1){
		perror("error in fork");
		exit(EXIT_FAILURE);
	} else if(pid == 0){//Child Process
		if(execvp(args[0], args) == -1){	
			perror("error in execvp");
			exit(EXIT_FAILURE);
		}
	} else if(pid > 0){//Parent Process
		int status;
		if(waitpid(pid,&status,0) == -1){//Pause Parent
          		perror("Error in parent wait");
		}
	}
	return true;
}





