#include "gtest/gtest.h"
#include "../header/commandLine.h"
#include "../header/connectors.h"
#include "../header/and.h"
#include "../header/or.h"
#include "../header/semicolon.h"
#include "../header/executable.h"
#include "../header/input.h"
#include <fstream>

TEST(AndTests, ValidValid) {
	string firstCommandString = "ls";
        char* firstCommandCmp = new char[firstCommandString.length()+1];
        strcpy(firstCommandCmp, firstCommandString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,1);

	string secondCommandTokenOneString = "echo";
        string secondCommandTokenTwoString = "hello";

        char* secondCommandTokenOneCmp = new char[secondCommandTokenOneString.length()+1];
        strcpy(secondCommandTokenOneCmp, secondCommandTokenOneString.c_str());

        char* secondCommandTokenTwoCmp = new char[secondCommandTokenTwoString.length()+1];
        strcpy(secondCommandTokenTwoCmp, secondCommandTokenTwoString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondCommandTokenOneCmp);
        secondCommand.push_back(secondCommandTokenTwoCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,2);

	CommandLine* firstAnd = new And(firstExecutable, secondExecutable);
	
	EXPECT_EQ(true, firstAnd->execute(0,1));
}

TEST(AndTests, ValidInvalid) {
	string thirdCommandString = "ls";
        char* thirdCommandCmp = new char[thirdCommandString.length()+1];
        strcpy(thirdCommandCmp, thirdCommandString.c_str());

        std::vector<char*> thirdCommand;
        thirdCommand.push_back(thirdCommandCmp);
        CommandLine* thirdExecutable = new Executable(thirdCommand,1);

        string fourthCommandTokenOneString = "ech";
        string fourthCommandTokenTwoString = "hello";

        char* fourthCommandTokenOneCmp = new char[fourthCommandTokenOneString.length()+1];
        strcpy(fourthCommandTokenOneCmp, fourthCommandTokenOneString.c_str());

        char* fourthCommandTokenTwoCmp = new char[fourthCommandTokenTwoString.length()+1];
        strcpy(fourthCommandTokenTwoCmp, fourthCommandTokenTwoString.c_str());

        std::vector<char*> fourthCommand;
        fourthCommand.push_back(fourthCommandTokenOneCmp);
        fourthCommand.push_back(fourthCommandTokenTwoCmp);
        CommandLine* fourthExecutable = new Executable(fourthCommand,2);

        CommandLine* secondAnd = new And(thirdExecutable, fourthExecutable);

        EXPECT_EQ(false, secondAnd->execute(0,1));
}

TEST(AndTests, InvalidValid) {
        string fifthCommandString = "l";
        char* fifthCommandCmp = new char[fifthCommandString.length()+1];
        strcpy(fifthCommandCmp, fifthCommandString.c_str());

        std::vector<char*> fifthCommand;
        fifthCommand.push_back(fifthCommandCmp);
        CommandLine* fifthExecutable = new Executable(fifthCommand,1);

        string sixthCommandTokenOneString = "echo";
        string sixthCommandTokenTwoString = "hello";

        char* sixthCommandTokenOneCmp = new char[sixthCommandTokenOneString.length()+1];
        strcpy(sixthCommandTokenOneCmp, sixthCommandTokenOneString.c_str());

        char* sixthCommandTokenTwoCmp = new char[sixthCommandTokenTwoString.length()+1];
        strcpy(sixthCommandTokenTwoCmp, sixthCommandTokenTwoString.c_str());

        std::vector<char*> sixthCommand;
        sixthCommand.push_back(sixthCommandTokenOneCmp);
        sixthCommand.push_back(sixthCommandTokenTwoCmp);
        CommandLine* sixthExecutable = new Executable(sixthCommand,2);

        CommandLine* thirdAnd = new And(fifthExecutable, sixthExecutable);

        EXPECT_EQ(false, thirdAnd->execute(0,1));
}

TEST(AndTests, InvalidInvalid) {
        string seventhCommandString = "l";
        char* seventhCommandCmp = new char[seventhCommandString.length()+1];
        strcpy(seventhCommandCmp, seventhCommandString.c_str());

        std::vector<char*> seventhCommand;
        seventhCommand.push_back(seventhCommandCmp);
        CommandLine* seventhExecutable = new Executable(seventhCommand,1);

        string eighthCommandTokenOneString = "ech";
        string eighthCommandTokenTwoString = "hello";

        char* eighthCommandTokenOneCmp = new char[eighthCommandTokenOneString.length()+1];
        strcpy(eighthCommandTokenOneCmp, eighthCommandTokenOneString.c_str());

        char* eighthCommandTokenTwoCmp = new char[eighthCommandTokenTwoString.length()+1];
        strcpy(eighthCommandTokenTwoCmp, eighthCommandTokenTwoString.c_str());

        std::vector<char*> eighthCommand;
        eighthCommand.push_back(eighthCommandTokenOneCmp);
        eighthCommand.push_back(eighthCommandTokenTwoCmp);
        CommandLine* eighthExecutable = new Executable(eighthCommand,2);

        CommandLine* fourthAnd = new And(seventhExecutable, eighthExecutable);

        EXPECT_EQ(false, fourthAnd->execute(0,1));
}
TEST(SemicolonTests, ValidValid) {
	string firstCommandString = "ls";
        char* firstCommandCmp = new char[firstCommandString.length()+1];
        strcpy(firstCommandCmp, firstCommandString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,1);

        string secondCommandTokenOneString = "echo";
        string secondCommandTokenTwoString = "hello";

        char* secondCommandTokenOneCmp = new char[secondCommandTokenOneString.length()+1];
        strcpy(secondCommandTokenOneCmp, secondCommandTokenOneString.c_str());

        char* secondCommandTokenTwoCmp = new char[secondCommandTokenTwoString.length()+1];
        strcpy(secondCommandTokenTwoCmp, secondCommandTokenTwoString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondCommandTokenOneCmp);
        secondCommand.push_back(secondCommandTokenTwoCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,2);

        CommandLine* firstSemicolon = new Semicolon(firstExecutable, secondExecutable);

        EXPECT_EQ(true, firstSemicolon->execute(0,1));
}

TEST(SemicolonTests, ValidInvalid) {
	string thirdCommandString = "ls";
        char* thirdCommandCmp = new char[thirdCommandString.length()+1];
        strcpy(thirdCommandCmp, thirdCommandString.c_str());

        std::vector<char*> thirdCommand;
        thirdCommand.push_back(thirdCommandCmp);
        CommandLine* thirdExecutable = new Executable(thirdCommand,1);

        string fourthCommandTokenOneString = "echo";
        string fourthCommandTokenTwoString = "hello";

        char* fourthCommandTokenOneCmp = new char[fourthCommandTokenOneString.length()+1];
        strcpy(fourthCommandTokenOneCmp, fourthCommandTokenOneString.c_str());

        char* fourthCommandTokenTwoCmp = new char[fourthCommandTokenTwoString.length()+1];
        strcpy(fourthCommandTokenTwoCmp, fourthCommandTokenTwoString.c_str());

        std::vector<char*> fourthCommand;
        fourthCommand.push_back(fourthCommandTokenOneCmp);
        fourthCommand.push_back(fourthCommandTokenTwoCmp);
        CommandLine* fourthExecutable = new Executable(fourthCommand,2);

        CommandLine* secondSemicolon = new Semicolon(thirdExecutable, fourthExecutable);

        EXPECT_EQ(true, secondSemicolon->execute(0,1));
}

TEST(SemicolonTests, InvalidValid) {
	string fifthCommandString = "l";
        char* fifthCommandCmp = new char[fifthCommandString.length()+1];
        strcpy(fifthCommandCmp, fifthCommandString.c_str());

        std::vector<char*> fifthCommand;
        fifthCommand.push_back(fifthCommandCmp);
        CommandLine* fifthExecutable = new Executable(fifthCommand,1);

        string sixthCommandTokenOneString = "echo";
        string sixthCommandTokenTwoString = "hello";

        char* sixthCommandTokenOneCmp = new char[sixthCommandTokenOneString.length()+1];
        strcpy(sixthCommandTokenOneCmp, sixthCommandTokenOneString.c_str());

        char* sixthCommandTokenTwoCmp = new char[sixthCommandTokenTwoString.length()+1];
        strcpy(sixthCommandTokenTwoCmp, sixthCommandTokenTwoString.c_str());

        std::vector<char*> sixthCommand;
        sixthCommand.push_back(sixthCommandTokenOneCmp);
        sixthCommand.push_back(sixthCommandTokenTwoCmp);
        CommandLine* sixthExecutable = new Executable(sixthCommand,2);

        CommandLine* thirdSemicolon = new Semicolon(fifthExecutable, sixthExecutable);

        EXPECT_EQ(true, thirdSemicolon->execute(0,1));
}

TEST(SemicolonTests, InvalidInvalid) {
	string seventhCommandString = "l";
        char* seventhCommandCmp = new char[seventhCommandString.length()+1];
        strcpy(seventhCommandCmp, seventhCommandString.c_str());

        std::vector<char*> seventhCommand;
        seventhCommand.push_back(seventhCommandCmp);
        CommandLine* seventhExecutable = new Executable(seventhCommand,1);

        string eighthCommandTokenOneString = "ech";
        string eighthCommandTokenTwoString = "hello";

        char* eighthCommandTokenOneCmp = new char[eighthCommandTokenOneString.length()+1];
        strcpy(eighthCommandTokenOneCmp, eighthCommandTokenOneString.c_str());

        char* eighthCommandTokenTwoCmp = new char[eighthCommandTokenTwoString.length()+1];
        strcpy(eighthCommandTokenTwoCmp, eighthCommandTokenTwoString.c_str());

        std::vector<char*> eighthCommand;
        eighthCommand.push_back(eighthCommandTokenOneCmp);
        eighthCommand.push_back(eighthCommandTokenTwoCmp);
        CommandLine* eighthExecutable = new Executable(eighthCommand,2);

        CommandLine* fourthSemicolon = new Semicolon(seventhExecutable, eighthExecutable);

        EXPECT_EQ(false, fourthSemicolon->execute(0,1));
}

TEST(OrTests, ValidValid) {
	string firstCommandString = "ls";
        char* firstCommandCmp = new char[firstCommandString.length()+1];
        strcpy(firstCommandCmp, firstCommandString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,1);

        string secondCommandTokenOneString = "echo";
        string secondCommandTokenTwoString = "hello";

        char* secondCommandTokenOneCmp = new char[secondCommandTokenOneString.length()+1];
        strcpy(secondCommandTokenOneCmp, secondCommandTokenOneString.c_str());

        char* secondCommandTokenTwoCmp = new char[secondCommandTokenTwoString.length()+1];
        strcpy(secondCommandTokenTwoCmp, secondCommandTokenTwoString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondCommandTokenOneCmp);
        secondCommand.push_back(secondCommandTokenTwoCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,2);

        CommandLine* firstOr = new Or(firstExecutable, secondExecutable);

        EXPECT_EQ(true, firstOr->execute(0,1));
}

TEST(OrTests, ValidInvalid) {
	string thirdCommandString = "ls";
        char* thirdCommandCmp = new char[thirdCommandString.length()+1];
        strcpy(thirdCommandCmp, thirdCommandString.c_str());

        std::vector<char*> thirdCommand;
        thirdCommand.push_back(thirdCommandCmp);
        CommandLine* thirdExecutable = new Executable(thirdCommand,1);

        string fourthCommandTokenOneString = "ech";
        string fourthCommandTokenTwoString = "hello";

        char* fourthCommandTokenOneCmp = new char[fourthCommandTokenOneString.length()+1];
        strcpy(fourthCommandTokenOneCmp, fourthCommandTokenOneString.c_str());

        char* fourthCommandTokenTwoCmp = new char[fourthCommandTokenTwoString.length()+1];
        strcpy(fourthCommandTokenTwoCmp, fourthCommandTokenTwoString.c_str());

        std::vector<char*> fourthCommand;
        fourthCommand.push_back(fourthCommandTokenOneCmp);
        fourthCommand.push_back(fourthCommandTokenTwoCmp);
        CommandLine* fourthExecutable = new Executable(fourthCommand,2);

        CommandLine* secondOr = new Or(thirdExecutable, fourthExecutable);

        EXPECT_EQ(true, secondOr->execute(0,1));
}

TEST(OrTests, InvalidValid) {
	string fifthCommandString = "l";
        char* fifthCommandCmp = new char[fifthCommandString.length()+1];
        strcpy(fifthCommandCmp, fifthCommandString.c_str());

        std::vector<char*> fifthCommand;
        fifthCommand.push_back(fifthCommandCmp);
        CommandLine* fifthExecutable = new Executable(fifthCommand,1);

        string sixthCommandTokenOneString = "echo";
        string sixthCommandTokenTwoString = "hello";

        char* sixthCommandTokenOneCmp = new char[sixthCommandTokenOneString.length()+1];
        strcpy(sixthCommandTokenOneCmp, sixthCommandTokenOneString.c_str());

        char* sixthCommandTokenTwoCmp = new char[sixthCommandTokenTwoString.length()+1];
        strcpy(sixthCommandTokenTwoCmp, sixthCommandTokenTwoString.c_str());

        std::vector<char*> sixthCommand;
        sixthCommand.push_back(sixthCommandTokenOneCmp);
        sixthCommand.push_back(sixthCommandTokenTwoCmp);
        CommandLine* sixthExecutable = new Executable(sixthCommand,2);

        CommandLine* thirdOr = new Or(fifthExecutable, sixthExecutable);

        EXPECT_EQ(true, thirdOr->execute(0,1));
}

TEST(OrTests, InvalidInvalid) {
	string seventhCommandString = "l";
        char* seventhCommandCmp = new char[seventhCommandString.length()+1];
        strcpy(seventhCommandCmp, seventhCommandString.c_str());

        std::vector<char*> seventhCommand;
        seventhCommand.push_back(seventhCommandCmp);
        CommandLine* seventhExecutable = new Executable(seventhCommand,1);

        string eighthCommandTokenOneString = "ech";
        string eighthCommandTokenTwoString = "hello";

        char* eighthCommandTokenOneCmp = new char[eighthCommandTokenOneString.length()+1];
        strcpy(eighthCommandTokenOneCmp, eighthCommandTokenOneString.c_str());

        char* eighthCommandTokenTwoCmp = new char[eighthCommandTokenTwoString.length()+1];
        strcpy(eighthCommandTokenTwoCmp, eighthCommandTokenTwoString.c_str());

        std::vector<char*> eighthCommand;
        eighthCommand.push_back(eighthCommandTokenOneCmp);
        eighthCommand.push_back(eighthCommandTokenTwoCmp);
        CommandLine* eighthExecutable = new Executable(eighthCommand,2);

        CommandLine* fourthOr = new Or(seventhExecutable, eighthExecutable);

        EXPECT_EQ(false, fourthOr->execute(0,1));
}

TEST(ExecutableTests, OneArgument) {
	//First Test
	string commandString = "ls";
	char* commandCmp = new char[commandString.length()+1];
	strcpy(commandCmp, commandString.c_str());

	std::vector<char*> firstCommand;
	firstCommand.push_back(commandCmp);
	CommandLine* firstExecutable = new Executable(firstCommand,1);

	EXPECT_EQ(true, firstExecutable->execute(0,1));
	
	//Second Test
	string secondTokenOneString = "echo";
	string secondTokenTwoString = "hello";

	char* secondTokenOneCmp = new char[secondTokenOneString.length()+1];
        strcpy(secondTokenOneCmp, secondTokenOneString.c_str());
	
	char* secondTokenTwoCmp = new char[secondTokenTwoString.length()+1];
        strcpy(secondTokenTwoCmp, secondTokenTwoString.c_str());
}

TEST(ExecutableTests, MultipleArguments) {
	string secondTokenOneString = "echo";
        string secondTokenTwoString = "hello";

        char* secondTokenOneCmp = new char[secondTokenOneString.length()+1];
        strcpy(secondTokenOneCmp, secondTokenOneString.c_str());

        char* secondTokenTwoCmp = new char[secondTokenTwoString.length()+1];
        strcpy(secondTokenTwoCmp, secondTokenTwoString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondTokenOneCmp);
        secondCommand.push_back(secondTokenTwoCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,2);

        EXPECT_EQ(true, secondExecutable->execute(0,1));
}

TEST(ExecutableTests, InvalidInput) {
	string thirdTokenOneString = "ech";
        string thirdTokenTwoString = "hello";

        char* thirdTokenOneCmp = new char[thirdTokenOneString.length()+1];
        strcpy(thirdTokenOneCmp, thirdTokenOneString.c_str());

        char* thirdTokenTwoCmp = new char[thirdTokenTwoString.length()+1];
        strcpy(thirdTokenTwoCmp, thirdTokenTwoString.c_str());

        std::vector<char*> thirdCommand;
        thirdCommand.push_back(thirdTokenOneCmp);
        thirdCommand.push_back(thirdTokenTwoCmp);
        CommandLine* thirdExecutable = new Executable(thirdCommand,2);

        EXPECT_EQ(false, thirdExecutable->execute(0,1));
}


TEST(ExecutableTests, existTestValid) {
	string tokenOneString = "test";
	string tokenTwoString = "-e";
	string tokenThreeString = "src/input.cpp";

	char* tokenOneCmp = new char[tokenOneString.length()+1];
	strcpy(tokenOneCmp, tokenOneString.c_str());

	char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

	char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

	std::vector<char*> command;
	command.push_back(tokenOneCmp);
	command.push_back(tokenTwoCmp);
	command.push_back(tokenThreeCmp);

	CommandLine* executable = new Executable(command,3);

	EXPECT_EQ(true, executable->execute(0,1));
}

TEST(ExecutableTests, existTestInvalid) {
        string tokenOneString = "test";
        string tokenTwoString = "-e";
        string tokenThreeString = "src/inpt.cpp";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);

        CommandLine* executable = new Executable(command,3);

        EXPECT_EQ(false, executable->execute(0,1));
}

TEST(ExecutableTests, fileTestValid) {
        string tokenOneString = "test";
        string tokenTwoString = "-f";
        string tokenThreeString = "src/executable.cpp";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);

        CommandLine* executable = new Executable(command,3);

        EXPECT_EQ(true, executable->execute(0,1));
}

TEST(ExecutableTests, fileTestInvalid) {
        string tokenOneString = "test";
        string tokenTwoString = "-f";
        string tokenThreeString = "src/";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);

        CommandLine* executable = new Executable(command,3);

        EXPECT_EQ(false, executable->execute(0,1));
}

TEST(ExecutableTests, dirTestValid) {
        string tokenOneString = "test";
        string tokenTwoString = "-d";
        string tokenThreeString = "src/";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);

        CommandLine* executable = new Executable(command,3);

        EXPECT_EQ(true, executable->execute(0,1));
}

TEST(ExecutableTests, dirTestInvalid) {
        string tokenOneString = "test";
        string tokenTwoString = "-d";
        string tokenThreeString = "src/executable.cpp";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);

        CommandLine* executable = new Executable(command,3);

        EXPECT_EQ(false, executable->execute(0,1));
}

TEST(ExecutableTests, defaultTestValid) {
        string tokenOneString = "test";
        string tokenTwoString = "src/";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);

        CommandLine* executable = new Executable(command,2);

        EXPECT_EQ(true, executable->execute(0,1));
}

TEST(ExecutableTests, defaultTestInvalid) {
        string tokenOneString = "test";
        string tokenTwoString = "sc/";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());
        
        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);

        CommandLine* executable = new Executable(command,2);

        EXPECT_EQ(false, executable->execute(0,1));
}

TEST(ExecutableTests, symExistTestValid) {
        string tokenOneString = "[";
        string tokenTwoString = "-e";
        string tokenThreeString = "src/input.cpp";
	string tokenFourString = "]";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());
	
	char* tokenFourCmp = new char[tokenFourString.length()+1];
	strcpy(tokenFourCmp, tokenFourString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);
	command.push_back(tokenFourCmp);

        CommandLine* executable = new Executable(command,4);

        EXPECT_EQ(true, executable->execute(0,1));
}

TEST(ExecutableTests, symExistTestInvalid) {
        string tokenOneString = "[";
        string tokenTwoString = "-e";
        string tokenThreeString = "src/inpt.cpp";
	string tokenFourString = "]";
	
        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

	char* tokenFourCmp = new char[tokenFourString.length()+1];
	strcpy(tokenFourCmp, tokenFourString.c_str());
        
	std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);
	command.push_back(tokenFourCmp);

        CommandLine* executable = new Executable(command,4);

        EXPECT_EQ(false, executable->execute(0,1));
}

TEST(ExecutableTests, symFileTestValid) {
        string tokenOneString = "[";
        string tokenTwoString = "-f";
        string tokenThreeString = "src/executable.cpp";
	string tokenFourString = "]";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

	char* tokenFourCmp = new char[tokenFourString.length()+1];
	strcpy(tokenFourCmp, tokenFourString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);
	command.push_back(tokenFourCmp);

        CommandLine* executable = new Executable(command,4);

        EXPECT_EQ(true, executable->execute(0,1));
}

TEST(ExecutableTests, symFileTestInvalid) {
        string tokenOneString = "[";
        string tokenTwoString = "-f";
        string tokenThreeString = "src/";
	string tokenFourString = "]";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

	char* tokenFourCmp = new char[tokenFourString.length()+1];
	strcpy(tokenFourCmp, tokenFourString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);
	command.push_back(tokenFourCmp);

        CommandLine* executable = new Executable(command,4);

        EXPECT_EQ(false, executable->execute(0,1));
}

TEST(ExecutableTests, symDirTestValid) {
        string tokenOneString = "[";
        string tokenTwoString = "-d";
        string tokenThreeString = "src/";
	string tokenFourString = "]";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

	char* tokenFourCmp = new char[tokenFourString.length()+1];
	strcpy(tokenFourCmp, tokenFourString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);
	command.push_back(tokenFourCmp);

        CommandLine* executable = new Executable(command,4);

        EXPECT_EQ(true, executable->execute(0,1));
}

TEST(ExecutableTests, symDirTestInvalid) {
        string tokenOneString = "[";
        string tokenTwoString = "-d";
        string tokenThreeString = "src/executable.cpp";
	string tokenFourString = "]";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

        char* tokenThreeCmp = new char[tokenThreeString.length()+1];
        strcpy(tokenThreeCmp, tokenThreeString.c_str());

	char* tokenFourCmp = new char[tokenFourString.length()+1];
	strcpy(tokenFourCmp, tokenFourString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
        command.push_back(tokenThreeCmp);
	command.push_back(tokenFourCmp);

        CommandLine* executable = new Executable(command,4);

        EXPECT_EQ(false, executable->execute(0,1));
}

TEST(ExecutableTests, symDefaultTestValid) {
        string tokenOneString = "[";
        string tokenTwoString = "src/";
	string tokenThreeString = "]";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());

	char* tokenThreeCmp = new char[tokenThreeString.length()+1];
	strcpy(tokenThreeCmp, tokenThreeString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
	command.push_back(tokenThreeCmp);

        CommandLine* executable = new Executable(command,3);

        EXPECT_EQ(true, executable->execute(0,1));
}

TEST(ExecutableTests, symDefaultTestInvalid) {
        string tokenOneString = "[";
        string tokenTwoString = "sc/";
	string tokenThreeString = "]";

        char* tokenOneCmp = new char[tokenOneString.length()+1];
        strcpy(tokenOneCmp, tokenOneString.c_str());

        char* tokenTwoCmp = new char[tokenTwoString.length()+1];
        strcpy(tokenTwoCmp, tokenTwoString.c_str());
	
	char* tokenThreeCmp = new char[tokenThreeString.length()+1];
	strcpy(tokenThreeCmp, tokenThreeString.c_str());

        std::vector<char*> command;
        command.push_back(tokenOneCmp);
        command.push_back(tokenTwoCmp);
	command.push_back(tokenThreeCmp);

        CommandLine* executable = new Executable(command,3);

        EXPECT_EQ(false, executable->execute(0,1));
}

TEST(ParenthesisTests, Valid) {
        string firstCommandString = "ls";
        char* firstCommandCmp = new char[firstCommandString.length()+1];
        strcpy(firstCommandCmp, firstCommandString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,1);

        CommandLine* paren = new Parenthesis(firstExecutable);

        EXPECT_EQ(true, paren->execute(0,1));
}

TEST(ParenthesisTests, Invalid) {
        string firstCommandString = "l";
        char* firstCommandCmp = new char[firstCommandString.length()+1];
        strcpy(firstCommandCmp, firstCommandString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,1);

        CommandLine* paren = new Parenthesis(firstExecutable);

        EXPECT_EQ(false, paren->execute(0,1));
}

TEST(OutputRedTests, execute) {
        string firstCommandTokenOneString = "echo";
        string firstCommandTokenTwoString = "hello";

        char* firstCommandTokenOneCmp = new char[firstCommandTokenOneString.length()+1];
        strcpy(firstCommandTokenOneCmp, firstCommandTokenOneString.c_str());

        char* firstCommandTokenTwoCmp = new char[firstCommandTokenTwoString.length()+1];
        strcpy(firstCommandTokenTwoCmp, firstCommandTokenTwoString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandTokenOneCmp);
        firstCommand.push_back(firstCommandTokenTwoCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,2);
  
        string secondCommandTokenOneString = "output.txt";

        char* secondCommandTokenOneCmp = new char[secondCommandTokenOneString.length()+1];
        strcpy(secondCommandTokenOneCmp, secondCommandTokenOneString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondCommandTokenOneCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,1);

        secondExecutable->setFileName(secondCommandTokenOneCmp);
        CommandLine* output = new OutputRed(firstExecutable, secondExecutable);

        output->execute(0,1);

        ifstream s("output.txt");
        string out((istreambuf_iterator<char>(s)), (istreambuf_iterator<char>()));
        EXPECT_EQ("hello\n", out);

        output->execute(0,1);
}


TEST(DoubleOutputRedTests, execute) {
	string firstCommandTokenOneString = "echo";
	string firstCommandTokenTwoString = "hello";

        char* firstCommandTokenOneCmp = new char[firstCommandTokenOneString.length()+1];
        strcpy(firstCommandTokenOneCmp, firstCommandTokenOneString.c_str());

	char* firstCommandTokenTwoCmp = new char[firstCommandTokenTwoString.length()+1];
        strcpy(firstCommandTokenTwoCmp, firstCommandTokenTwoString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandTokenOneCmp);
	firstCommand.push_back(firstCommandTokenTwoCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,2);

        string secondCommandTokenOneString = "output.txt";

        char* secondCommandTokenOneCmp = new char[secondCommandTokenOneString.length()+1];
        strcpy(secondCommandTokenOneCmp, secondCommandTokenOneString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondCommandTokenOneCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,1);

	secondExecutable->setFileName(secondCommandTokenOneCmp);
        CommandLine* output = new DoubleOutputRed(firstExecutable, secondExecutable);
       
	output->execute(0,1);

	ifstream s("output.txt");
	string out((istreambuf_iterator<char>(s)), (istreambuf_iterator<char>()));
	EXPECT_EQ("hello\nhello\n", out);
}

TEST(InputRedTests, execute) {
	string firstCommandTokenOneString = "cat";

        char* firstCommandTokenOneCmp = new char[firstCommandTokenOneString.length()+1];
        strcpy(firstCommandTokenOneCmp, firstCommandTokenOneString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandTokenOneCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,1);

        string secondCommandTokenOneString = "names.txt";

        char* secondCommandTokenOneCmp = new char[secondCommandTokenOneString.length()+1];
        strcpy(secondCommandTokenOneCmp, secondCommandTokenOneString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondCommandTokenOneCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,1);

        secondExecutable->setFileName(secondCommandTokenOneCmp);
        CommandLine* input = new InputRed(firstExecutable, secondExecutable);
	testing::internal::CaptureStdout();
        input->execute(0,1);
        string out = testing::internal::GetCapturedStdout();

        EXPECT_EQ("Armando Gutierrez, 861213968, aguti037@ucr.edu\nNhat Nguyen, 862119873, nnguy176@ucr.edu\n", out);
}

TEST(PipeTests, upperToLower) {
	string firstCommandTokenOneString = "cat";
	string firstCommandTokenTwoString = "names.txt";

        char* firstCommandTokenOneCmp = new char[firstCommandTokenOneString.length()+1];
        strcpy(firstCommandTokenOneCmp, firstCommandTokenOneString.c_str());

	char* firstCommandTokenTwoCmp = new char[firstCommandTokenTwoString.length()+1];
        strcpy(firstCommandTokenTwoCmp, firstCommandTokenTwoString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandTokenOneCmp);
	firstCommand.push_back(firstCommandTokenTwoCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,2);

        string secondCommandTokenOneString = "tr";
	string secondCommandTokenTwoString = "A-Z";
	string secondCommandTokenThreeString = "a-z";

        char* secondCommandTokenOneCmp = new char[secondCommandTokenOneString.length()+1];
        strcpy(secondCommandTokenOneCmp, secondCommandTokenOneString.c_str());

	char* secondCommandTokenTwoCmp = new char[secondCommandTokenTwoString.length()+1];
        strcpy(secondCommandTokenTwoCmp, secondCommandTokenTwoString.c_str());

	char* secondCommandTokenThreeCmp = new char[secondCommandTokenThreeString.length()+1];
        strcpy(secondCommandTokenThreeCmp, secondCommandTokenThreeString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondCommandTokenOneCmp);
	secondCommand.push_back(secondCommandTokenTwoCmp);
	secondCommand.push_back(secondCommandTokenThreeCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,3);
        
	secondExecutable->setFileName(secondCommandTokenOneCmp);
	CommandLine* pipe = new Pipe(firstExecutable, secondExecutable);
	testing::internal::CaptureStdout();
        pipe->execute(0,1);
        string out = testing::internal::GetCapturedStdout();

        EXPECT_EQ("armando gutierrez, 861213968, aguti037@ucr.edu\nnhat nguyen, 862119873, nnguy176@ucr.edu\n", out);
}

TEST(PipeTests, lowerToUpper) {
	string firstCommandTokenOneString = "cat";
        string firstCommandTokenTwoString = "names.txt";

        char* firstCommandTokenOneCmp = new char[firstCommandTokenOneString.length()+1];
        strcpy(firstCommandTokenOneCmp, firstCommandTokenOneString.c_str());

        char* firstCommandTokenTwoCmp = new char[firstCommandTokenTwoString.length()+1];
        strcpy(firstCommandTokenTwoCmp, firstCommandTokenTwoString.c_str());

        std::vector<char*> firstCommand;
        firstCommand.push_back(firstCommandTokenOneCmp);
        firstCommand.push_back(firstCommandTokenTwoCmp);
        CommandLine* firstExecutable = new Executable(firstCommand,2);

        string secondCommandTokenOneString = "tr";
        string secondCommandTokenTwoString = "a-z";
        string secondCommandTokenThreeString = "A-Z";

        char* secondCommandTokenOneCmp = new char[secondCommandTokenOneString.length()+1];
        strcpy(secondCommandTokenOneCmp, secondCommandTokenOneString.c_str());

        char* secondCommandTokenTwoCmp = new char[secondCommandTokenTwoString.length()+1];
        strcpy(secondCommandTokenTwoCmp, secondCommandTokenTwoString.c_str());

        char* secondCommandTokenThreeCmp = new char[secondCommandTokenThreeString.length()+1];
        strcpy(secondCommandTokenThreeCmp, secondCommandTokenThreeString.c_str());

        std::vector<char*> secondCommand;
        secondCommand.push_back(secondCommandTokenOneCmp);
        secondCommand.push_back(secondCommandTokenTwoCmp);
        secondCommand.push_back(secondCommandTokenThreeCmp);
        CommandLine* secondExecutable = new Executable(secondCommand,3);

        secondExecutable->setFileName(secondCommandTokenOneCmp);
        CommandLine* pipe = new Pipe(firstExecutable, secondExecutable);
        testing::internal::CaptureStdout();
        pipe->execute(0,1);
        string out = testing::internal::GetCapturedStdout();

        EXPECT_EQ("ARMANDO GUTIERREZ, 861213968, AGUTI037@UCR.EDU\nNHAT NGUYEN, 862119873, NNGUY176@UCR.EDU\n", out);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

