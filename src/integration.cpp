#include "../header/commandLine.h"
#include "../header/connectors.h"
#include "../header/and.h"
#include "../header/or.h"
#include "../header/semicolon.h"
#include "../header/executable.h"
#include "../header/input.h"
#include <string>
#include <iostream>

int main(int argv, char** argc) {
        std::string input = "";
        for(int i = 1; i < argv; i++) {
                input += argc[i];
		input += " ";
        }
	std::cout << "Input: " << input << std::endl;
	Input *object = new Input(input);
	object->execute(0,1);
}
