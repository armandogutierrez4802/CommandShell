#include "../header/input.h"
#include <string>
#include <cstring>
#include <iostream>

Input::Input(std::string userInput){
    this->userInput = userInput;
}

bool Input::execute(int in, int out){//Here we parse the string and make a tree out of objects
    std::string newUserInput = "";
    bool openQuote = false;
    int countParen = 0;

    if(this->userInput[0] == '#'){
	return true;
    }
	
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

   
    string inputRedString = "<";
    string outputRedString = ">";
    string doubleOutputRedString = ">>";
    char* inputRedCmp = new char[inputRedString.length()+1];
    char* outputRedCmp = new char[outputRedString.length()+1];
    char* doubleOutputRedCmp = new char[doubleOutputRedString.length()+1];
    strcpy(inputRedCmp, inputRedString.c_str());
    strcpy(outputRedCmp, outputRedString.c_str());
    strcpy(doubleOutputRedCmp, doubleOutputRedString.c_str());

    string pipeString = "|";
    char* pipeCmp = new char[pipeString.length()+1];
    strcpy(pipeCmp, pipeString.c_str());


    int commandTokenLength;
    //Executable* leftChild;//For outputting and testing purposes
    //Executable* rightChild;//For outputting and testing purposes
    int tokenLength;

    //CommandLine* commandObjectTemp;//???This will be used if our command line ends with a closed paranthesis
//cout << "1 - BEFORE WHILE LOOP" << endl;	
//cout << "1" << endl;
	
    CommandLine* parObject;//This is used if our current token is closed () to move our connector over to CMO
    while (token)
    {
//cout << "OUR CURRENT TOKEN IS: " << token << endl;
//cout << "2" << endl;
	tokenLength = strlen(token);
	if(strcmp(token,openParCmp) == 0){//If token is an open parenthesis, push it on the CNT
		connectorTokens.push_back(token);
	}

	//If token is connector ******* IF OUR CONNECTOR IS AN OPEN PARENTHESIS, I THINK WE JUST PUSH IT ON THE CONNECTOR TOKENS
        //****IF OUR TOKEN IS A CLOSED PARANTHESIS, DO WE EVEN NEED TO PUSH IT ON THE CONNECTOR TOKENS STACK??? I DO NOT THINK SO B/C WHEN WE MOVE ON TO THE NEXT CONNECTOR,
        //	WON'T OUR PARANTHESIS OBJECT ALREADY BE IN COMMAND OBJECTS???
        //**** IF OPEN PARENTHESIS, THEN PUSH IT ON CONNECTOR TOKENS, IF CLOSED PARANTHESIS, THEN CREATE THE PARENTHESIS OBJECT
        //**** KEEP IN MIND THAT AN OPEN PARANTHESIS IS COULD BE FOLLOWED BY ANOTHER OPEN PAR, AND CLOSED PARANTHESIS CAN ALSO BE FOLLOWED BY ANOTHER
	else if(strcmp(token, semiCmp) == 0 || strcmp(token, andCmp) == 0 || strcmp(token, orCmp) == 0 
					 || strcmp(token,closeParCmp) == 0 || strcmp(token,inputRedCmp) == 0 || strcmp(token,outputRedCmp) == 0
					 || strcmp(token, doubleOutputRedCmp) == 0 || strcmp(token,pipeCmp) == 0){
            //instantiate a command object with commandTokens **** THIS DOES NOT WORK IF WE ARE AT || AND WE HAVE (echoo A && echo B) || (echo C && echo D)
            //*** YAAAASSSS--->>> DO THIS IF THE BACK OF CONNECTOR TOKENS IS NOT A CLOSED PARANTHESIS
	    //IN THIS CASE ^^  WE JUST NEED TO PUSH THE CONNECTOR TOKEN, IN THIS CASE THE ||
            //***  IT SEEMS LIKE THE CREATION OF THE OBJECT ONLY HAPPENS WHEN THE PARENTHESIS ARE NOT IN CONNECTOR TOKENS
//cout << "4" << endl;  
	    //Wait... what if it is just one command in a paranthesis, like (echo A)
	    // I forgot what this if statement below was for lmao
	    //** I THINK THIS IF STATEMENT IS WRONG ->if(strcmp(connectorTokens.back(), closeParCmp) != 0 &&||?? strcmp(connectorTokens.back(), openParCmp) != 0){//I'M THINKING &&
	    //** ^^Encapsulates next two lines of code..Maybe the little empty command token while loop 						      
	    if(commandTokens.size() != 0){	
		object = new Executable(commandTokens,commandTokens.size());	
            	//push_back it onto commandObjects **** LOOK AT COMMENTS FOR PREVIOUS SECTION BECAUSE SAME APPLIES
		commandObjects.push_back(object);
//cout << "5" << endl;
            	//empty commandTokens
            	while(commandTokens.size() != 0){
                	commandTokens.pop_back();
            	}
	    }	

//cout << "6" << endl;

//cout << "SIZE OF CONNECTOR TOKENS = " << connectorTokens.size() << endl;
	    //-----------***********Will probably need to instantiate commandObject temp with commandObject.back() here
	    	
	   // maybe not-> FOR THE NEXT BLOCK, WE SHOULD DO THIS IF THE BACK OF CNT IS A CLOSED PARANTHESIS!! WE SHOULD POP THE PARANTHESIS FIRST AND THEN INSTANTIATE CONNECTOR

						//**** We run into problems here when vector size = 3 with the paranthesis object, echo C, and echo D
						//	Only when our current token is closed parenthesis?? so maybe this needs to be a separate check
            //**** YAAASS-->>> WE ALSO NEED TO CHECK IF THE BACK OF THE CONNECTOR TOKENS IS ( OR NOT. THIS SHOULD HAPPEN WHEN ITS != OPEN PARENTHESIS
//            if((commandObjects.size() >= 2 && strcmp(connectorTokens.back(),openParCmp) != 0)||(strcmp(closeParCmp, token) == 0 && strcmp(connectorTokens.back(),closeParCmp) != 0)){
	    if(((commandObjects.size() >= 2 || strcmp(closeParCmp, token) == 0) && (strcmp(connectorTokens.back(),openParCmp)!=0&&strcmp(connectorTokens.back(),closeParCmp)!=0))
				|| (connectorTokens.size() != 0 && strcmp(connectorTokens.back(),openParCmp) == 0 && strcmp(closeParCmp, token) == 0)
				|| (connectorTokens.size() != 0 && strcmp(closeParCmp,connectorTokens.back()) == 0)){	
//cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;
//cout << "7" << endl;    //****^^^^^ >= 2 OR == 2???? May not matter i guess
		//then instantiate a connector by passing in the two commandObjects
                //Hint: use if elses to determine what kind of connector it is (this is connectorTokens)
//cout << "connectorTokens.size() = " << connectorTokens.size() << endl;
//cout << "connectorTokens.back() = " <<  connectorTokens.back() << endl;               
		
		if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(),openParCmp) == 0 && strcmp(closeParCmp, token) == 0){
			connectorTokens.pop_back();
		}	

		if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), closeParCmp) == 0){
			connectorTokens.pop_back();
		}

		if(connectorTokens.size() != 0 && (strcmp(connectorTokens.back(), orCmp) == 0)){//********* THIS WILL PROBABLY HAVE TO CHANGE TO connectorTokens.back() ****
     			//cout << "X" << endl;
			object = new Or(commandObjects.at(commandObjects.size()-2),commandObjects.back());//******For all these guys change .front() to .at(commandObjects.size()-1)
                } else if(connectorTokens.size() != 0 && (strcmp(connectorTokens.back(), andCmp) == 0)){
                    	//cout << "Y" << endl;
			object = new And(commandObjects.at(commandObjects.size()-2),commandObjects.back());
                } else if(connectorTokens.size() != 0 && (strcmp(connectorTokens.back(), semiCmp) == 0)){
			//cout << "Z" << endl;
                    	object = new Semicolon(commandObjects.at(commandObjects.size()-2),commandObjects.back());
                } else if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), inputRedCmp) == 0){
			object = new InputRed(commandObjects.at(commandObjects.size()-2),commandObjects.back());
		} else if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), outputRedCmp) == 0){
			object = new OutputRed(commandObjects.at(commandObjects.size()-2),commandObjects.back());
		} else if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), doubleOutputRedCmp) == 0){
			object = new DoubleOutputRed(commandObjects.at(commandObjects.size()-2),commandObjects.back());
                } else if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), pipeCmp) == 0){
			object = new Pipe(commandObjects.at(commandObjects.size()-2),commandObjects.back());
		}

                //Push this new connector object onto connectorObjects
                connectorObjects.push_back(object);
                //Empty the commandObjects vector ... *** Should this stay two pop backs??? *Leaning towards yes
                if(commandObjects.size() != 1){
                	commandObjects.pop_back();
                }
//cout << "9" << endl;
		commandObjects.pop_back();
//cout << "10" << endl;
		//****** WILL PROBABLY MAKE THE PARANETHESIS CONNECTOR HERE IF TOKEN IS A CLOSED PARENTHESIS
		if(strcmp(token,closeParCmp) == 0){
//cout << "11" << endl;
			parObject = new Parenthesis(connectorObjects.back());//This could be .at(0) too right lol
			connectorObjects.pop_back();
			connectorObjects.push_back(parObject);
//cout << "12" << endl;
		}
	
                //Move the connector Object into the commandObject list.....*** i changed this next line to .back instead of .at(0). Not sure if that matters
                commandObjects.push_back(connectorObjects.back());//**********If we are at a closed parenthesis than we need to push the new () object instead
                //Pop connector Object 
                connectorObjects.pop_back();
                //Pop connectorTokens ***** WILL PROBABLY KEEP HAVING TO POP BACK UNTIL WE REACH THE OPEN PARENTHESIS, WE WANT TO REMOVE THE OPEN PAREN BUT NOT WHATS BEFORE IT  
//cout << "13" << endl;

//cout << "connectorTokens.size() = " << connectorTokens.size() << endl;
//cout << "commandObjects.size() = " << commandObjects.size() << endl;
//*_*_*_*_*_*_*_*_*_*_* DOWN HERE!!!!!--------------------------------- MAYBE ONLY DO THESE TWO BLOCKS IF I AM AT A CLOSED PARANTHESIS OORRR ** MAKE WHILE AN IF **
//	     if(strcmp(token, closeParCmp) == 0){//**DO I NEED THIS IF???
		if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), openParCmp) != 0){// || strcmp(connectorTokens.back(),closeParCmp)!=0)){
			connectorTokens.pop_back();//*** WE MAY NEED TO POP CONNECTOR TOKENS UNTIL AN OPEN PARENTHESIS IS REACHED, THEN POP THE OPEN PARENTHESIS
		}
			
		if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), openParCmp) == 0){
			connectorTokens.pop_back();
		}
//	     }
//cout << "14" << endl;
//cout << "connectorTokens.size() = " << connectorTokens.size() << endl;
	
            }//End big if( (x && y) || (z || w) )

	  
	    
//cout << "END OF BIG IF" << endl;
		//Push_back the connector on the connectorTokens
		connectorTokens.push_back(token);//***** DO WE NEED TO DO THIS IF IT IS OUR CURRENT TOKEN IS A CLOSED PARANTHESIS? I DO NOT THINK SO(WRONG!)
						//^^ ACTUALLY WE MAY NEED TO TO MAKE SURE THAT WE DO NOT CREATE ON OBJECT WHEN THE NEXT CURRENT TOKEN IS A CONNECTOR!!!
	
	}
        //else token is command, then push_back onto commandTokens
        else{
	//cout << "2 - JUST PUSHED A COMMAND TOKEN" << endl;
            commandTokens.push_back(token);
	}
        token = strtok(NULL," ");
   }//end while loop
   
//cout << "***AFTER WHILE***" << endl;
/*
cout << "CMT SIZE = " << commandTokens.size() << endl;
cout << "CNT SIZE = " << connectorTokens.size() << endl;
cout << "CMO SIZE = " << commandObjects.size() << endl;
cout << "CNO SIZE = " << connectorObjects.size() << endl;
*/


//cout << "15" << endl;
//cout << "connectorTokens.size() = " << connectorTokens.size() << endl;
//cout << "is back of CNT == )? " << strcmp(connectorTokens.back(), closeParCmp) << endl;
//cout << "MEH?" << endl;
//  if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), closeParCmp) != 0){//********* THIS IS SUPER IMPORTANT TO KNOW HOW TO IMPLEMENT THE WHILE LOOP ABOVE
//    cout << "am i in big if?" << endl;
    //We are always gauranteed to need to create a command object for our last command to execute
    //instantiate a command object with commandTokens
    //push_back it onto commandObjects`
    // ***** WE ONLY NEED TO DO THIS IF COMMAND OBJECTS SIZE IS NOT 2....OR *** YAAAS -->>> IF OUR COMMAND TOKENS IS NOT EMPTY
  if(commandTokens.size() != 0){  //**Create a command object if we have stuff in our CMT
    object = new Executable(commandTokens,commandTokens.size());
    commandObjects.push_back(object);
   
//cout << "16" << endl;
    //empty commandTokens
    while(commandTokens.size() != 0){
    	commandTokens.pop_back();
    }
  }

//cout << "17" << endl;
    //***** IN THE CASE THAT OUR LINE ENDS WITH A CLOSED PARANTHESIS, 
    // WE SHOULD POP THE CLOSED PARENTHESIS, AND CREATE... whaaaa
    //If commandObjects size == 2 
	if(commandObjects.size() == 2){// *** Should we make this >= two??? ---> NO, I DON'T THINK SO, WE CAN PROBABLY HANDLE THIS IN THE WHILE LOOP
        	//then instantiate a connector by passing in the two commandObjects
        	//Use if elses to determine what kind of connector it is (this is connectorTokens)
 		
		//_*_*_*_*_*_*_*_*_*_*_* THIS IS WHAT FIXED THE LAST TEST CASE
		while(strcmp(connectorTokens.back(), closeParCmp) == 0 || strcmp(connectorTokens.back(), openParCmp) == 0){
			connectorTokens.pop_back();
		}

        	if(connectorTokens.size() != 0 && (strcmp(connectorTokens.back(), orCmp) == 0)){// ****** AGAIN WE WILL PROBABLY HAVE TO CHANGE THIS TO CONNECTOR TOKENS.BACK()
            		//cout << "B" << endl;
            		object = new Or(commandObjects.at(commandObjects.size()-2),commandObjects.back());
        	} else if(connectorTokens.size() != 0 && (strcmp(connectorTokens.back(), andCmp) == 0)){
            		//cout << "C" << endl;
            		object = new And(commandObjects.at(commandObjects.size()-2),commandObjects.back());
        	} else if(connectorTokens.size() != 0 && (strcmp(connectorTokens.back(), semiCmp) == 0)){
            		//cout << "D" << endl;
            		object = new Semicolon(commandObjects.at(commandObjects.size()-2),commandObjects.back());
        	} else if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), inputRedCmp) == 0){
                        object = new InputRed(commandObjects.at(commandObjects.size()-2),commandObjects.back());
                } else if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), outputRedCmp) == 0){
                        object = new OutputRed(commandObjects.at(commandObjects.size()-2),commandObjects.back());
                } else if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), doubleOutputRedCmp) == 0){
                        object = new DoubleOutputRed(commandObjects.at(commandObjects.size()-2),commandObjects.back());
                } else if(connectorTokens.size() != 0 && strcmp(connectorTokens.back(), pipeCmp) == 0){
                        object = new Pipe(commandObjects.at(commandObjects.size()-2),commandObjects.back());
                }



//cout << "18" << endl;
        	//Push this new connector object onto connectorObjects
        	connectorObjects.push_back(object);
        	//Empty the commandObjects vector
        	//cout << " CMO SIZE = " << commandObjects.size() << "*" << endl;
        	commandObjects.pop_back();
        	commandObjects.pop_back();
        	//Move the connector Object into the commandObject list
        	commandObjects.push_back(connectorObjects.at(0));
        	//cout << " CMO SIZE = " << commandObjects.size() << "**" << endl;
		//Pop connector Object
		//cout << " CNO SIZE = " << connectorObjects.size() << "**" << endl;
        	connectorObjects.pop_back();
    	}
//cout << "19" << endl;
//  }// **** END THE IF STATEMENT THAT CHECKS IF OUR CNT.BACK() IS A CLOSED ()

//cout << "OUTSIDE IF" << endl;
    //cout << " CNT SIZE = " << connectorTokens.size() << "**" << endl;
    //Pop connectorTokens
    // *** POP BACK UNTIL EMPTY
    while(connectorTokens.size() != 0){
    	connectorTokens.pop_back();
    }
//cout << "20" << endl;
/*
cout << "CMT SIZE = " << commandTokens.size() << endl;
cout << "CNT SIZE = " << connectorTokens.size() << endl;
cout << "CMO SIZE = " << commandObjects.size() << endl;
cout << "CNO SIZE = " << connectorObjects.size() << endl;
*/
//cout << "MY TREE IS : " << commandObjects.at(0) << endl;
    //We now have our entire tree in the first element of our commandObjects
    commandObjects.at(0)->execute();
//cout << "21" << endl;   
}

