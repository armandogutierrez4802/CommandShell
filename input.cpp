#include "input.h"


Input(std::string userInput){
	this->userInput = userInput;

}

bool Input::execute(){//Here we parse the string and make a tree out of objects
	char *token = strtok(str," ");
    	while (token)
    	{
        	
        	token = strtok(NULL,delim);
	}

}

