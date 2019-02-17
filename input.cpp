#include "input.h"
#include <string>
#include <cstring>
#include <iostream>

Input::Input(std::string userInput){
    this->userInput = userInput;
}

bool Input::execute(){//Here we parse the string and make a tree out of objects
    std::string newUserInput = "";
    for(int i = 0; i < this->userInput.size(); i++){//Handle the comments and adding spaces before semicolon
        if(this->userInput[i] == '#'){
            break;
        } else{
            if(this->userInput[i] == ';'){// && (i+1) != this->userInput.size()){
                newUserInput += ' ';
            }
            newUserInput += this->userInput[i];
        }
    }
    
    
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
    char* leftChild;//For outputting and testing purposes
    char* rightChild;//For outputting and testing purposes
    
    
    while (token)
    {
        //If token is connector
        if((strcmp(token, semiCmp)) == 0 || (strcmp(token, andCmp) == 0) || (strcmp(token, orCmp) == 0)){
            //instantiate a command object with commandTokens
            object = new Executable(commandTokens,commandTokens.size());
            
            cout << "Command Object ";
            for(int i = 0; i < commandTokens.size(); i++){
                cout << commandTokens.at(i) << " ";
            }
            cout << "was just created" << endl;
            
            //push_back it onto commandObjects
            commandObjects.push_back(object);
            
            
            
            
            
            //empty commandTokens
            while(commandTokens.size() != 0){
                commandTokens.pop_back();
            }
            
            //If commandObjects size == 2
            if(commandObjects.size() == 2){
                //then instantiate a connector by passing in the two commandObjects
                //Hint: use if elses to determine what kind of connector it is (this is connectorTokens)
                if((strcmp(token, orCmp) == 0)){
                    object = new Or(commandObjects.front(),commandObjects.back());
                } else if((strcmp(token, andCmp) == 0)){
                    object = new And(commandObjects.front(),commandObjects.back());
                } else if((strcmp(token, semiCmp) == 0)){
                    object = new Semicolon(commandObjects.front(),commandObjects.back());
                }
                
                cout << "Connector Object " << token << " was just created" << endl;
                cout << "Left Child = " <<  << endl;
                cout << "Right Child = " <<  << endl;
                 
                
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
            commandTokens.push_back(token);
        }
        token = strtok(NULL," ");
    }//end while loop
    
    //instantiate a command object with commandTokens
    //push_back it onto commandObjects
    object = new Executable(commandTokens,commandTokens.size());
    commandObjects.push_back(object);

    //If commandObjects size == 2
    if(commandObjects.size() == 2){
        //then instantiate a connector by passing in the two commandObjects
        //Use if elses to determine what kind of connector it is (this is connectorTokens)
        cout << token << endl;
        cout << "A" << endl;
        if((strcmp(connectorTokens.at(0), orCmp) == 0)){
            cout << "B" << endl;
            object = new Or(commandObjects.front(),commandObjects.back());
        } else if((strcmp(connectorTokens.at(0), andCmp) == 0)){
            cout << "C" << endl;
            object = new And(commandObjects.front(),commandObjects.back());
        } else if((strcmp(connectorTokens.at(0), semiCmp) == 0)){
            cout << "D" << endl;
            object = new Semicolon(commandObjects.front(),commandObjects.back());
        }
        cout << "E" << endl;
        
        cout << "Connector Object " << token << " was just created" << endl;
        cout << "Left Child = " <<  << endl;
        cout << "Right Child = " <<  << endl;
        
        //Push this new connector object onto connectorObjects
        connectorObjects.push_back(object);
        //Empty the commandObjects vector
        commandObjects.pop_back();
        commandObjects.pop_back();
        //Move the connector Object into the commandObject list
        commandObjects.push_back(connectorObjects.at(0));
        //Pop connector Object
        connectorObjects.pop_back();
    }
    //Pop connectorTokens
    connectorTokens.pop_back();
    
    //We now have our entire tree in the first element of our commandObjects
    commandObjects[0]->execute();
    
    
    
}
