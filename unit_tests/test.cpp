#include "gtest/gtest.h"
#include "../header/commandLine.h"
#include "../header/connectors.h"
#include "../header/and.h"
#include "../header/or.h"
#include "../header/semicolon.h"
#include "../header/executable.h"
#include "../header/input.h"

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
	
	EXPECT_EQ(true, firstAnd->execute());
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

        EXPECT_EQ(false, secondAnd->execute());
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

        EXPECT_EQ(false, thirdAnd->execute());
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

        EXPECT_EQ(false, fourthAnd->execute());
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

        EXPECT_EQ(true, firstSemicolon->execute());
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

        EXPECT_EQ(true, secondSemicolon->execute());
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

        EXPECT_EQ(true, thirdSemicolon->execute());
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

        EXPECT_EQ(false, fourthSemicolon->execute());
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

        EXPECT_EQ(true, firstOr->execute());
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

        EXPECT_EQ(true, secondOr->execute());
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

        EXPECT_EQ(true, thirdOr->execute());
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

        EXPECT_EQ(false, fourthOr->execute());
}

TEST(ExecutableTests, OneArgument) {
	//First Test
	string commandString = "ls";
	char* commandCmp = new char[commandString.length()+1];
	strcpy(commandCmp, commandString.c_str());

	std::vector<char*> firstCommand;
	firstCommand.push_back(commandCmp);
	CommandLine* firstExecutable = new Executable(firstCommand,1);

	EXPECT_EQ(true, firstExecutable->execute());
	
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

        EXPECT_EQ(true, secondExecutable->execute());
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

        EXPECT_EQ(false, thirdExecutable->execute());
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

	EXPECT_EQ(true, executable->execute());
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

        EXPECT_EQ(false, executable->execute());
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

        EXPECT_EQ(true, executable->execute());
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

        EXPECT_EQ(false, executable->execute());
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

        EXPECT_EQ(true, executable->execute());
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

        EXPECT_EQ(false, executable->execute());
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

        EXPECT_EQ(true, executable->execute());
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

        EXPECT_EQ(false, executable->execute());
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

        EXPECT_EQ(true, executable->execute());
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

        EXPECT_EQ(false, executable->execute());
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

        EXPECT_EQ(true, executable->execute());
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

        EXPECT_EQ(false, executable->execute());
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

        EXPECT_EQ(true, executable->execute());
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

        EXPECT_EQ(false, executable->execute());
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

        EXPECT_EQ(true, executable->execute());
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

        EXPECT_EQ(false, executable->execute());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
