#include "input.h"


Input(std::string userInput){
	this->userInput = userInput;

}

bool Input::execute(){//Here we parse the string and make a tree out of objects
	std::string newUserInput = "";
	//this->userInput += "\0" //Do we need this or does every string end in /0 ??
	
	for(int i = 0; i < this->userInput.size(); i++){//Handle the comments and adding spaces before semicolon
		if(this->userInput[i] == '#'){
			break;
		} else{ 
			if(this->userInput[i+1] == " " && (i+1) != this->userInput.size()){
				newUserInput += " ";
			}
			newUserInput += this->userInput[i]; 
		}	
	}
	
	
	//Now our new user input string accounts for comments, and now everything is separated by a space
	
	
	//Now we build our tree as we tokenize
	
	char *token = strtok(newUserString," ");
    	while (token)
    	{
		//if token is command, then push_back onto commandTokens
		//if token is connector,
			//instantiate a command object with commandTokens and push_back it onto commandObjects
			//empty commandTokens???
			//If commandObjects size == 2 
				//then instantiate a connector by passing in the two commandObjects
				//Use if elses to determine what kind of connector it is (this is connectorTokens)
				//Push this new connector object onto connectorObjects
				//Empty the commandObjects vector
				//Move the connector Object into the commandObject list
				//Pop connector Object
				//Pop connectorTokens 
		
			//Push_back the connector on the connectorTokens 
		
		
			
				
		
		
		
		
		
		//Check size lists (command = 2 & connector = 1)
		//Assign first command as connectors left child and second command as connectors right child
		//CommandList should now be empty
		//Push the connector onto the commandClass
		
		//Need to check if it is a command or connector
		
		//If command, then instantiate a command object, then push that command object onto commandList
		//If connector, then instantiate a connector object and push that connector object onto connectorList
		
        	
        	token = strtok(NULL,delim);
	}

}

