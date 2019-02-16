#include "input.h"
#include <string>


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
	char* orCmp = "||";
	char* andCmp = "&&";
	char* semiCmp = ";";
	CommandLine* object;
		
		
    	while (token)
    	{
		//if token is command, then push_back onto commandTokens
		if((std::strcmp(token, orCmp) != 0) || std::strcmp(token, andCmp) != 0) ||std::strcmp(token, semiCmp) != 0)){
			commandTokens.push_back(token);
		}
		else{//if token is connector,
			//instantiate a command object with commandTokens
			object = new Executable(commandTokens,commandTokens.size());
			//push_back it onto commandObjects
			commandObjects.push_back(object);
			//empty commandTokens???
			commandTokens.pop_back();
			commandTokens.pop_back();
			
			//If commandObjects size == 2 
			if(commandObjects.size() == 2){
				//then instantiate a connector by passing in the two commandObjects
				//Hint: use if elses to determine what kind of connector it is (this is connectorTokens)
				if((std::strcmp(token, orCmp) == 0)){
					object = new Or(commandObjects.front(),commandObjects.back());
				} else if((std::strcmp(token, andCmp) == 0)){
					object = new And(commandObjects.front(),commandObjects.back());
				} else if((std::strcmp(token, semiCmp) == 0)){
					object = new Semi(commandObjects.front(),commandObjects.back());
				}
				//Push this new connector object onto connectorObjects
				connectorObjects.push_back(object);
				//Empty the commandObjects vector
				commandObjects.pop_back();
				commandObjects.pop_back();
				//Move the connector Object into the commandObject list
				commandObjects.push_back(connectorObjects);
				//Pop connector Object
				connectorObjects.pop_back();
				//Pop connectorTokens 
				connectorTokens.pop_back();
			}
			//Push_back the connector on the connectorTokens 
			//LOL WAIT WHAT IS THIS???
			//Oh ya this is if we are at a connector, so now we push it before looping again
			connectorTokens.push_back(token);
		}

        	token = strtok(NULL," ");
	}

	//instantiate a command object with commandTokens and push_back it onto commandObjects
	//If commandObjects size == 2 
		//then instantiate a connector by passing in the two commandObjects
		//Use if elses to determine what kind of connector it is (this is connectorTokens)
		//Push this new connector object onto connectorObjects
		//Empty the commandObjects vector
		//Move the connector Object into the commandObject list
		//Pop connector Object
	//Pop connectorTokens
		
	
	//We now have our entire tree in the first element of our commandObjects
	
	
}

