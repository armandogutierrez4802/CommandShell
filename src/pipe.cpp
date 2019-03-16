#include "../header/pipe.h"

Pipe::Pipe(CommandLine* leftChild, CommandLine* rightChild) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
        
bool Pipe::execute(int in, int out){
	//cout << "Beginning of Pipe" << endl;
	
	int originalIn = dup(0);
	int originalOut = dup(1);

	int fd[2];

	if(pipe(fd) == -1){
		perror("Error in pipe");
		return false;
	}
	
	//cout << "PIPE A" << endl;

	if(leftChild->execute(in,fd[1]) == false){
		return false;
	}

	//cout << "PIPE B" << endl;
	
	dup2(originalOut,1);
	close(fd[1]);

	//cout << "PIPE C" << endl;

	if(rightChild->execute(fd[0],out) == false){
		return false;
	}

	//cout << "PIPE D" << endl;
	dup2(originalIn,0);
	close(fd[0]);
	
	//cout << "End of pipe" << endl;

	return true;
}
