#include "../header/executable.h"
#include <cstring>

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
	bool returnValue = true ;
	for(int i = 0; i < numArguments; i++){
		args[i] = cmTokens.at(i);
	}
	
	args[numArguments] = NULL;
	
	char* exitValue = (char *)"exit";
	char* inputValue = *args;
	std::cout << inputValue << std::endl;
        if(strcmp(inputValue, exitValue) == 0) {
                exit(0);
        }
	
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
		if(WEXITSTATUS(status) != 0) {
          		returnValue = false;
       		}
	}
	return returnValue;
}





