#include "../header/input.h"
#include <string>
#include <cstring>
#include <iostream>

Input::Input(std::string userInput){
    this->userInput = userInput;
}

bool Input::execute(){//Here we parse the string and make a tree out of objects
    std::string newUserInput = "";
    bool openQuote = false;
    int countParen = 0;
    for(int i = 0; i < this->userInput.size(); i++){//Checking that there are an even amount of parenthesis
	if(userInput[i] == '('){
		countParen++;
	}
	if(userInput[i] == ')'){
                countParen--;
        }
    }

    if(countParen != 0){//Exit program if uneven parenthesis
	cout << "Error: uneven number of parenthesis" << endl;
	return false;
    }

    countParen = 0;//Set it back equal to zero in order to use it during tree construction

    for(int i = 0; i < this->userInput.size(); i++){//Handle the comments and adding spaces before semicolon & parenthesis
        if(this->userInput[i] == '#'){
            break;
        } else{
            if(this->userInput[i] == ';' || this->userInput[i] == '"' || this->userInput[i] == '(' || this->userInput[i] == ')'){
                newUserInput += ' ';
            }
	    
            newUserInput += this->userInput[i];
	    
	    if(this->userInput[i] == '"' || this->userInput[i] == '(' || this->userInput[i] == ')'){
		newUserInput += " ";	
	    }
        }
    }
    
//	cout << "newUserInput = " << newUserInput << endl;

    
   
    //Now our new user input string accounts for comments, and now everything is separated by a space
    
    //Now we build our tree as we tokenize
    char *c = new char [newUserInput.length()+1];
    strcpy(c, newUserInput.c_str());
    char *token = strtok(c," ");
    string orString = "||";
    string andString = "&&";
    string semiString = ";";
    
    char* orCmp = new char[orString.length()+1];
    strcpy(orCmp, orString.c_str());
    
    char* andCmp = new char[andString.length()+1];
    strcpy(andCmp, andString.c_str());
    
    char* semiCmp = new char[semiString.length()+1];
    strcpy(semiCmp, semiString.c_str());
    
    CommandLine* object;
    
    char quoteChar = '"';
    char *quoteCmp = &quoteChar;//new char[quoteString.length()+1];
    //strcpy(quoteCmp, quoteString.s_str());
    
    string openParString = "(";
    string closeParString = ")";
    char* openParCmp = new char[openParString.length()+1];
    char* closeParCmp = new char[closeParString.length()+1];
    strcpy(openParCmp, openParString.c_str());
    strcpy(closeParCmp, closeParString.c_str());


    int commandTokenLength;
    //Executable* leftChild;//For outputting and testing purposes
    //Executable* rightChild;//For outputting and testing purposes
    int tokenLength;
    
    while (token)
    {
	tokenLength = strlen(token);

	

	//If token is connector ******* IF OUR CONNECTOR IS AN OPEN PARENTHESIS, I THINK WE JUST PUSH IT ON THE CONNECTOR TOKENS
        //****IF OUR TOKEN IS A CLOSED PARANTHESIS, DO WE EVEN NEED TO PUSH IT ON THE CONNECTOR TOKENS STACK??? I DO NOT THINK SO B/C WHEN WE MOVE ON TO THE NEXT CONNECTOR,
        //	WON'T OUR PARANTHESIS OBJECT ALREADY BE IN COMMAND OBJECTS???
        //**** IF OPEN PARENTHESIS, THEN PUSH IT ON CONNECTOR TOKENS, IF CLOSED PARANTHESIS, THEN CREATE THE PARENTHESIS OBJECT
        //**** KEEP IN MIND THAT AN OPEN PARANTHESIS IS ALWAYS FOLLOWED BY A COMMAND, CLOSED PARANTHESIS ARE ALWAYS FOLLOWED BY A CONNECTOR
	if((strcmp(token, semiCmp) == 0 || strcmp(token, andCmp) == 0 || strcmp(token, orCmp) == 0 
		|| strcmp(token,openParCmp) == 0 || strcmp(token,closeParCmp) == 0) && openQuote == false){
            //instantiate a command object with commandTokens **** THIS DOES NOT WORK IF WE ARE AT || AND WE HAVE (echoo A && echo B) || (echo C && echo D)
            object = new Executable(commandTokens,commandTokens.size());//*** MAYBE ONLY DO THIS IF THE BACK OF CONNECTOR TOKENS IS NOT A CLOSED PARANTHESIS
									//OTHERWISE WE JUST NEED TO PUSH THE CONNECTOR TOKEN, IN THIS CASE THE ||
            								//***  IT SEEMS LIKE THE CREATION OF THE OBJECT ONLY HAPPENS WHEN THE PARENTHESIS ARE NOT IN CONNECTOR TOKENS
            	
            
            
            //push_back it onto commandObjects **** LOOK AT COMMENTS FOR PREVIOUS SECTION BECAUSE SAME APPLIES
            commandObjects.push_back(object);
           
            
            //empty commandTokens
            while(commandTokens.size() != 0){
                commandTokens.pop_back();
            }
            				
						//**** We run into problems here when vector size = 3 with the paranthesis object, echo C, and echo D
            //If commandObjects size == 2 ****** WE ALSO NEED TO CHECK IF THE BACK OF THE CONNECTOR TOKENS IS ( OR NOT. THIS SHOULD HAPPEN WHEN ITS != OPEN PARENTHESIS
            if(commandObjects.size() == 2){// && openQuote == false){//No need for this openQuote check b/c we wouldn't be in here if it was true
                //then instantiate a connector by passing in the two commandObjects
                //Hint: use if elses to determine what kind of connector it is (this is connectorTokens)
                if((strcmp(connectorTokens.at(0), orCmp) == 0)){//********* THIS WILL PROBABLY HAVE TO CHANGE TO connectorTokens.back() ****
                	//cout << "X" << endl; 
			object = new Or(commandObjects.front(),commandObjects.back());
                } else if((strcmp(connectorTokens.at(0), andCmp) == 0)){
                    	//cout << "Y" << endl;
			object = new And(commandObjects.front(),commandObjects.back());
                } else if((strcmp(connectorTokens.at(0), semiCmp) == 0)){
			//cout << "Z" << endl;
                    	object = new Semicolon(commandObjects.front(),commandObjects.back());
                }

                
                //Push this new connector object onto connectorObjects
                connectorObjects.push_back(object);
                //Empty the commandObjects vector
                commandObjects.pop_back();
                commandObjects.pop_back();

		
		//****** WILL PROBABLY MAKE THE PARANETHESIS CONNECTOR HERE IF TOKEN IS A CLOSED PARENTHESIS

                //Move the connector Object into the commandObject list
                commandObjects.push_back(connectorObjects.at(0));//If we are at a closed parenthesis than we need to push the new () object instead
                //Pop connector Object 
                connectorObjects.pop_back();
                //Pop connectorTokens ***** WILL PROBABLY KEEP HAVING TO POP BACK UNTIL WE REACH THE OPEN PARENTHESIS, WE WANT TO REMOVE THE OPEN PAREN BUT NOT WHATS BEFORE IT
                connectorTokens.pop_back();//*** WE MAY NEED TO POP CONNECTOR TOKENS UNTIL AN OPEN PARENTHESIS IS REACHED, THEN POP THE OPEN PARENTHESIS
		}
		//Push_back the connector on the connectorTokens
		//LOL WAIT WHAT IS THIS???
		//Oh ya this is if we are at a connector, so now we push it before looping again
		connectorTokens.push_back(token);//***** DO WE NEED TO DO THIS IF IT IS OUR CURRENT TOKEN IS A CLOSED PARANTHESIS? I DO NOT THINK SO(WRONG!)
						//^^ ACTUALLY WE MAY NEED TO TO MAKE SURE THAT WE DO NOT CREATE ON OBJECT WHEN THE NEXT CURRENT TOKEN IS A CONNECTOR!!!
	}
        //else token is command, then push_back onto commandTokens
        else{



            commandTokens.push_back(token);
	    

	}
        token = strtok(NULL," ");
   }//end while loop
    
    
    //We are always gauranteed to need to create a command object for our last command to execute
    //instantiate a command object with commandTokens
    //push_back it onto commandObjects
    // ***** WE ONLY NEED TO DO THIS IF COMMAND OBJECTS SIZE IS NOT 2....OR IF OUR COMMAND TOKENS IS NOT EMPTY
    object = new Executable(commandTokens,commandTokens.size());
    commandObjects.push_back(object);
   /*
    cout << "Command Object ";
	for(int i = 0; i < commandTokens.size(); i++){
             cout << commandTokens.at(i) << " ";
        }
    cout << "was just created" << endl; 
    */

    //empty commandTokens
    while(commandTokens.size() != 0){
    	commandTokens.pop_back();
    }

    //If commandObjects size == 2 
   	//**************check the last open quote here??? and then set it to false???
	 if(commandObjects.size() == 2 && openQuote == false){//Do we need this openQuote check??
        //then instantiate a connector by passing in the two commandObjects
        //Use if elses to determine what kind of connector it is (this is connectorTokens)
        cout << "A" << endl;
        if((strcmp(connectorTokens.at(0), orCmp) == 0)){// ****** AGAIN WE WILL PROBABLY HAVE TO CHANGE THIS TO CONNECTOR TOKENS.BACK()
            //cout << "B" << endl;
            object = new Or(commandObjects.front(),commandObjects.back());
        } else if((strcmp(connectorTokens.at(0), andCmp) == 0)){
            //cout << "C" << endl;
            object = new And(commandObjects.front(),commandObjects.back());
        } else if((strcmp(connectorTokens.at(0), semiCmp) == 0)){
            //cout << "D" << endl;
            object = new Semicolon(commandObjects.front(),commandObjects.back());
        }

        
        //Push this new connector object onto connectorObjects
        connectorObjects.push_back(object);
        //Empty the commandObjects vector
        //cout << " CMO SIZE = " << commandObjects.size() << "*" << endl;
        commandObjects.pop_back();
        commandObjects.pop_back();
        //Move the connector Object into the commandObject list
        commandObjects.push_back(connectorObjects.at(0));
       // cout << " CMO SIZE = " << commandObjects.size() << "**" << endl;
	//Pop connector Object
	//cout << " CNO SIZE = " << connectorObjects.size() << "**" << endl;
        connectorObjects.pop_back();
    }
    
    //cout << " CNT SIZE = " << connectorTokens.size() << "**" << endl;
    //Pop connectorTokens
    // *** POP BACK UNTIL EMPTY
    connectorTokens.pop_back();
    
    
    //cout << "FINAL COMMAND OBJECTS SIZE = " << commandObjects.size() << endl;
    //We now have our entire tree in the first element of our commandObjects
    commandObjects.at(0)->execute();
    
}
