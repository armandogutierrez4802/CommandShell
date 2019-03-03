#include "../header/executable.h"
#include <cstring>
#include <iostream>

Executable::Executable(vector<char*> cmTokens, int numArguments){
	this->cmTokens = cmTokens;
	this->numArguments = numArguments;
}

bool Executable::execute(){
	char* args[numArguments+1];
	bool returnValue = true ;
	
	/*
	//Take out the quotes!
	char  quoteChar = '"';
	char* quoteCmp = &quoteChar;
	char* newCommand;
	int commandTokenLength;
	for(int i = 0; i < numArguments; i++){//check every command in vector
		commandTokenLength = strlen(cmTokens.at(i));//Length of command
		if(quoteCmp[0] == cmTokens.at(i)[0]){//First character is a quote
			for(int j = 1; j < commandTokenLength; j++){
				newCommand += cmTokens.at(i)[j];
				cout << "X = " << cmTokens.at(i)[j] << endl;
			} 
			cmTokens.at(i) = newCommand;
			cout << "*Command Token at i = " << cmTokens.at(i) << endl;
		} else if(quoteCmp[0] == cmTokens.at(i)[commandTokenLength]){//Should the index be CTL - 1 ???
			for(int j = 0; j < commandTokenLength - 1; j++){
				newCommand += cmTokens.at(i)[j];
				cout << "Y = " << cmTokens.at(i)[j] << endl;
			}
			cmTokens.at(i) = newCommand;
			cout << "**Command Token at i = " << cmTokens.at(i) << endl;
		}
	}

	*/

	for(int i = 0; i < numArguments; i++){
		args[i] = cmTokens.at(i);
	}
	
	args[numArguments] = NULL;
	
	//Check for exit command
	char* exitValue = (char *)"exit";
	char* inputValue = *args;
	
        if(strcmp(inputValue, exitValue) == 0) {
                exit(0);
        }
	
	/*
	//Check for test command
	char* testValue = (char *)"test";
	
	if(strcmp(args[0], testValue) == 0) {
		struct stat buf;
		if(stat(args[2], &buf) == -1) {
			return false;	
		}
		
		if(strcmp(args[1], "-f") == 0) {
			return (buf.st_mode & S_IFMT) == S_IFREG);
		} else if(strcmp(args[1], "-d") == 0) {
			return (buf.st_mode & S_IFMT) == S_IFDIR);
		} else {
			return true;
		}
	}
	*/
	
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




