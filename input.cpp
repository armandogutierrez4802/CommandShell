#include "input.h"


Input(std::string userInput){
	this->userInput = userInput;

}

bool Input::execute(){//Here we parse the string and make a tree out of objects
	std::string newUserString = "";
	//this->userInput += "\0"
	
	for(int i = 0; i < this->userInput.size(); i++){//Handle the comments from user input
		if(this->userInput[i] == '#'){
			break;
		} else{
			if(this->userInput[i+1] == '' && (i+1) != this->userInput.size()){
				
			}
			newUserString += this->userInput[i]; 
		}	
	}
	
	
	
	
	char *token = strtok(str," ");
    	while (token)
    	{
        	
        	token = strtok(NULL,delim);
	}

}

