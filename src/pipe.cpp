#include "../header/pipe.h"

Pipe::Pipe(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool Pipe::execute(int in, int out){
	int fd[2];

	if(pipe(fd) == -1){
		perror("Error in pipe");
		return false;
	}

	if(leftChild->execute(in,fd[1]) == false){
		return false;
	}

	close(fd[1]);

	if(rightChild->execute(fd[0],out) == false){
		return false;
	}

	close(fd[0]);

	return true;
}
