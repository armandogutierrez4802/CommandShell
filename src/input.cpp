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
    for(int i = 0; i < this->userInput.size(); i++){//Handle the comments and adding spaces before semicolon
        if(this->userInput[i] == '#'){
            break;
        } else{
            if(this->userInput[i] == ';' || this->userInput[i] == '"'){// && (i+1) != this->userInput.size()){
                newUserInput += ' ';
            }
            newUserInput += this->userInput[i];
	    
	    if(this->userInput[i] == '"'){
		newUserInput += " ";
	    }
        }
    }
    
	//cout << "newUserInput = " << newUserInput << endl;

     
   
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

	//If token is an Open Paranthesis
	if(strcmp(token, openParCmp) == 0){
	
	}

	 //If token is an Close Paranthesis
	 if(strcmp(token, closeParCmp) == 0){
	 
	}
	
	//If token is a quote
	if(strcmp(token, quoteCmp) == 0 && openQuote == false){
		openQuote = true;
	} else if (strcmp(token, quoteCmp) == 0 && openQuote == true){
		openQuote = false;
	}//If token is connector
        else if((((strcmp(token, semiCmp)) == 0 || (strcmp(token, andCmp) == 0) || (strcmp(token, orCmp) == 0))) && openQuote == false){
            //instantiate a command object with commandTokens
            object = new Executable(commandTokens,commandTokens.size());
            
            
            
            //TESTING BLOCK OPEN
	    //This is to tell us what command object we created
            /*
	    cout << "Command Object ";
            for(int i = 0; i < commandTokens.size(); i++){
                cout << commandTokens.at(i) << " ";
            }
            cout << "was just created" << endl;
            */
	    //TESTING BLOCK CLOSE
            
            
            //push_back it onto commandObjects
            commandObjects.push_back(object);
            
            
            //TESTING BLOCK OPEN
	    //This is how we know if our ommand is on the left or right side of the connector
            /*
	    if(commandObjects.size() == 1){
		cout << "We declared the left child" << endl;
                leftChild = new Executable(commandTokens,commandTokens.size());
            } else if(commandObjects.size() == 2){
		cout << "We declared the right child" << endl;
                rightChild = new Executable(commandTokens,commandTokens.size());
            }    
	    */
            //TESTING BLOCK CLOSE
	               
            
            
            //empty commandTokens
            while(commandTokens.size() != 0){
                commandTokens.pop_back();
            }
            
            //If commandObjects size == 2
            if(commandObjects.size() == 2){// && openQuote == false){//No need for this openQuote check b/c we wouldn't be in here if it was true
                //then instantiate a connector by passing in the two commandObjects
                //Hint: use if elses to determine what kind of connector it is (this is connectorTokens)
                if((strcmp(connectorTokens.at(0), orCmp) == 0)){
                	//cout << "X" << endl; 
			object = new Or(commandObjects.front(),commandObjects.back());
                } else if((strcmp(connectorTokens.at(0), andCmp) == 0)){
                    	//cout << "Y" << endl;
			object = new And(commandObjects.front(),commandObjects.back());
                } else if((strcmp(connectorTokens.at(0), semiCmp) == 0)){
			//cout << "Z" << endl;
                    	object = new Semicolon(commandObjects.front(),commandObjects.back());
                }
                
                //TESTING BLOCK OPEN
		/*
                cout << "Connector Object " << token << " was just created" << endl;
                cout << "Left Child = ";
        	leftChild->display();
		cout << endl;
        	cout << "Right Child = ";       
     	   	rightChild->display();
		cout << endl;
		*/
                //TESTING BLOCK CLOSE
                
                //Push this new connector object onto connectorObjects
                connectorObjects.push_back(object);
                //Empty the commandObjects vector
                commandObjects.pop_back();
                commandObjects.pop_back();
                //Move the connector Object into the commandObject list
                commandObjects.push_back(connectorObjects.at(0));
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
        //else token is command, then push_back onto commandTokens
        else{


	    if(openQuote == true){
		commandTokens.at(commandTokens.size()-1) += ' ';
		for(int i = 0; i < tokenLength; i++){ 
			commandTokens.at(commandTokens.size()-1) += token[i];	
		}

	    } else{
            	commandTokens.push_back(token);
	    }


	    //--------------------OLD OPEN QUOTES BLOCK OPEN----------------------------------

	    //cout << "BEFORE THE OPEN QUOTES CHECK" << endl;
	    //cout << commandTokens.at(0)[0] << " ?= " << quoteCmp[0];
 	    //NEED TO CHECK THE BEGGINNING OF EEEVVERY TOKEN
 	    //cout << "SIZE OF COMMANDTOKENS = " << commandTokens.size() << endl;
	
	    
	    //int tokenLength = strlen(commandTokens.at(1));
	    //cout << "TOKEN LENGTH = " << tokenLength << endl;    
	    	    

	    //If the first character in the first element is a quote, then set openQuote = true
	    /*
	    for(int i = 0; i < commandTokens.size(); i++){	
		commandTokenLength = strlen(commandTokens.at(i));
		cout<< "COMMAND TOKEN LENGTH = " << commandTokenLength << endl;
		cout << "commandTokens.at(i)[commandTokenLength] =  " << commandTokens.at(i)[commandTokenLength-1] << endl;
		if(commandTokens.at(i)[0] == quoteCmp[0]){
	    		//cout << "INSIDE OPEN QUOTES" << endl;
			//cout << "commandTokens.at( " << i << ")[0] == " << commandTokens.at(i)[0] <<endl;
			openQuote = true;
	    	}//Else if the last character in the last element is a quote then set openQuote = false
      		else if(commandTokens.at(i)[commandTokenLength-1] == quoteCmp[0]){
			cout << "DO I EVER GO IN HERE???" << endl;
			openQuote = false;
		}
	    }
           */

	
	   /*
	   //The above code simplified!!!!
	   commandTokenLength = strlen(commandTokens.at(commandTokens.size()-1));
	   cout << "CommandTokenLength = " << commandTokenLength << endl;
	   if(commandTokens.at(0)[0] == quoteCmp[0]){
		openQuote = true;
	   }
	
	   if(commandTokens.at(commandTokens.size()-1)[commandTokenLength] == quoteCmp[0]){
		cout << "AAAHHHH" << endl;
		openQuote = false;
	   }
	   */

	   //--------------------OLD OPEN QUOTES BLOCK CLOSE----------------------------------


	}
        token = strtok(NULL," ");
   }//end while loop
    
    
    //We are always gauranteed to need to create a command object for our last command to execute
    //instantiate a command object with commandTokens
    //push_back it onto commandObjects
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
   // cout << "AFTER THE WHILE LOOP THE VALUE OF OUR OPENQUOTE = " <<  openQuote << endl;
   	//**************check the last open quote here??? and then set it to false???
	 if(commandObjects.size() == 2 && openQuote == false){//Do we need this openQuote check??
        //then instantiate a connector by passing in the two commandObjects
        //Use if elses to determine what kind of connector it is (this is connectorTokens)
        cout << "A" << endl;
        if((strcmp(connectorTokens.at(0), orCmp) == 0)){
            //cout << "B" << endl;
            object = new Or(commandObjects.front(),commandObjects.back());
        } else if((strcmp(connectorTokens.at(0), andCmp) == 0)){
            //cout << "C" << endl;
            object = new And(commandObjects.front(),commandObjects.back());
        } else if((strcmp(connectorTokens.at(0), semiCmp) == 0)){
            //cout << "D" << endl;
            object = new Semicolon(commandObjects.front(),commandObjects.back());
        }
        
        //TESTING BLOCK OPEN
	/*
        cout << "Connector Object " << token << " was just created" << endl;
        cout << "Left Child = ";
	leftChild->display();
        cout << "Right Child = ";
	rightChild->display();
	*/
        //TESTING BLOCK CLOSE
        
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
    connectorTokens.pop_back();
    
    
    //cout << "FINAL COMMAND OBJECTS SIZE = " << commandObjects.size() << endl;
    //We now have our entire tree in the first element of our commandObjects
    commandObjects.at(0)->execute();
    
    
    
}
