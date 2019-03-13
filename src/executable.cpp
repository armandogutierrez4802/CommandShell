#include "../header/executable.h"
#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <string.h>

Executable::Executable(vector<char*> cmTokens, int numArguments){
	this->cmTokens = cmTokens;
	this->numArguments = numArguments;
	/*
	cout << "The elements in this newly created Executable object are ";
	for(int i = 0; i < numArguments; i++){
		cout << cmTokens.at(i) << " ";
	}
	cout << endl;
	*/
}

void Executable::setFileName(char* file){
	this->fileName = string(file);
}

string Executable::getFileName(){
	return this->fileName;
}

bool Executable::execute(int in, int out){
	char* args[numArguments+1];
	bool returnValue = true ;
	
	char quoteChar = '"';
	char *quoteCmp = &quoteChar;


	for(int i = 0; i < numArguments; i++){
//		if(strcmp(cmTokens.at(i),quoteCmp) != 0){
//			cout << cmTokens.at(i) << " IS GETTING ADDED TO ARGS[]" << endl;
			args[i] = cmTokens.at(i);
//		}
	}
	
	args[numArguments] = NULL;
	
	//Check for exit command
	char* exitValue = (char *)"exit";
	char* testValue = (char *)"test";
	char* leftBracket = (char *)"[";
	char* inputValue = *args;
	
        if(strcmp(inputValue, exitValue) == 0) {
                exit(0);
        }
	
	//Check for test command
	else if(strcmp(args[0], testValue) == 0) {
		struct stat buf;
		
		if(strcmp(args[1], "-e") == 0) {
			if(stat(args[2], &buf) == -1) {
                        	std::cout << "(False)" << std::endl;
				return false;
                	}
			std::cout << "(True)" << std::endl;
			return true;
		} else if(strcmp(args[1], "-f") == 0) {
			if(stat(args[2], &buf) == -1) {
				std::cout << "(False)" << std::endl;
                        	return false;
                	}
			if((buf.st_mode & S_IFMT) == S_IFREG) {
				std::cout << "(True)" << std::endl;
				return true;
			} else {
				std::cout << "(False)" << std::endl;
				return false;
			}
		} else if(strcmp(args[1], "-d") == 0) {
			if(stat(args[2], &buf) == -1) {
				std::cout << "(False)" << std::endl;
                        	return false;
                	}
			if((buf.st_mode & S_IFMT) == S_IFDIR) {
				std::cout << "(True)" << std::endl;
				return true;
			} else {
				std::cout << "(False)" << std::endl;
				return false;
			}
		} else {
			if(stat(args[1], &buf) == -1) {
				std::cout << "(False)" << std::endl;
                        	return false;
                	}
			std::cout << "(True)" << std::endl;
			return true;
		}
	}

	//Test for symbolic test command
	else if(strcmp(args[0], leftBracket) == 0 ) {
		struct stat buf;

		if(strcmp(args[1], "-e") == 0) {
			if(stat(args[2], &buf) == -1) {
				std::cout << "(False)" << std::endl;
                                return false;
                        }
			std::cout << "(True)" << std::endl;
			return true;	
		} else if(strcmp(args[1], "-f") == 0) {
			if(stat(args[2], &buf) == -1) {
				std::cout << "(False)" << std::endl;
                                return false;
                        }
			if((buf.st_mode & S_IFMT) == S_IFREG) {
				std::cout << "(True)" << std::endl;
				return true;
			} else {
				std::cout << "(False)" << std::endl;
				return false;
			}
		} else if(strcmp(args[1], "-d") == 0) {
			if(stat(args[2], &buf) == -1) {
				std::cout << "(False)" << std::endl;
                                return false;
                        }
			if((buf.st_mode & S_IFMT) == S_IFDIR) {
				std::cout << "(True)" << std::endl;
				return true;
			} else {
				std::cout << "(False)" << std::endl;
				return false;
			}
		} else {
			if(stat(args[1], &buf) == -1) {
				std::cout << "(False)" << std::endl;
                                return false;
                        }
			std::cout << "(True)" << std::endl;
			return true;
		}
	}

	pid_t pid = fork();
	if(pid == -1){
		perror("error in fork");
		exit(EXIT_FAILURE);
	} else if(pid == 0){//Child Process

		if(dup2(in,0) == -1){
			perror("Error in dup2 input");
			return false;
		}
		if(dup2(out,1) == -1){
			perror("Error in dup2 output");
			return false;
		}
		
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





