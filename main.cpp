#include "commandLine.h"
#include "connectors.h"
#include "and.h"
#include "or.h"
#include "semicolon.h"
#include "executable.h"
#include "input.h"
#include <iostream>

using namespace std;
int main() {
	string userInput = "";
//	int continue;
//	while(continue){
	cout << "$ ";
	cin >> userInput;
	Input* object  = new Input(userInput);
//	}


}
