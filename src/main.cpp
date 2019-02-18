#include "../header/commandLine.h"
#include "../header/connectors.h"
#include "../header/and.h"
#include "../header/or.h"
#include "../header/semicolon.h"
#include "../header/executable.h"
#include "../header/input.h"
#include <iostream>

using namespace std;
int main() {
	string userInput = "";
//	int continue;
//	while(continue){
	cout << "$ ";
	getline(cin,userInput);
	Input* object  = new Input(userInput);
	object->execute();
//	}
//	cout << "THIS IS THE END OF THE PROGRAM" << endl;

}
