# CS 100 Programming Project
Winter 2019\
Armando Gutierrez 861213968\
Nhat Nguyen 862119873

# Introduction
This project involves implementing a RShell, a basic command shell written in C++ that satisfies the following criterias: 
1. Print command prompts.
2. Read in command lines. Distinguishing between executables, arguments, connectors, and commands.
3. Execute commands using fork, execvp, waitpid.
4. Handles additional commands such as test.
5. Able to account for quotes and precedence.

In addition, this project will be implemented using the composite pattern as the core design principle.

# Diagram
![UML Diagram](https://github.com/cs100/assignment-cs_100_aa_assignment_1/blob/master/Images/Assignment_3_UML.png)

# Classes
* CommandLine
  * Serves as the primary interface that classes in the composite pattern inherit from. Implements the execute function that subclasses must implement.
* Executable
  * Handles the execution of commands such as: fork, execvp, waitpid, test, and exit. fork() is called and the corresponding pid is stored in variable "pid". If the pid value is -1, an error is thrown, and exit(EXIT_FAILURE) is called. A pid value of 0 indicates that the current process is a child process, and execvp is called on the command. If the return value of execvp is -1, then an error is thrown, and exit(EXIT_FAILURE) is called. If a value greater than 0 is detected, then the current process is a parent process, and waitpid() is called to pause the parent process. If exit(EXIT_FAILURE) has been called, then the return value is set to false.
* Connector
  * *And*\
Has two private member variables: leftChild and rightChild (Base pointers). And handles two commands, in which the following command is executed only if the first command (leftChild) is successfully completed.
  * *Or*\
Has two private member variables: leftChild and rightChild (Base pointers). Or handles two commands, in which the following command is executed only if the first command (leftChild) fails.
  * *Semicolon*\
Has two private member variables: leftChild and rightChild (Base pointers). Semicolon handles two commands, in which the following command is executed regardless if the first is successfully completed or fails.
  * *Parenthesis*\
Has one private member variable leftChild (Base pointer). Parenthesis handles one command, in which leftChild contains the subtree of the expression enclosed by parenthesis. 
* Input
  * Converts a user inputted string and parses the string, distinguishing between connectors, commands, quotes, and parenthesis. A tree is then constructed using vectors of char pointers and CommandLine pointers. Execute is then called on the root node, executing the entire tree. 
# Prototypes/Research
The purpose of the prototype is to apply what we have researched and learned about the functions waitpid(), execvp() and fork(). The execvp() function takes in two arguments. The first of which is the name of the file that is going to be executed. Once the first argument is loaded into the caller's address space and over-writes the program, then the second argument will be provided to the program right before it executes. The fork() function creats an identical process to the one being ran. The two processes are called the Child and the Parent. These two processes will run simultaneously unless a wait() function is called. The waitpid() function, if called in the parent process, will cause the parent process to wait until the specified, usually once the child process is terminated. \
These functions will be useful in our assignment because our connectors determine how two variables on either side of it will relate to one another. Depending on whether the connector is and &&, ||, or semicolon, we may or many not want/need to execute the parent process by the results of execution of the child process.

# Development and Testing Roadmap
### Tasks to be completed:
##### Class implementations:
1. CommandLine
2. Executable
3. Input
4. Connector
5. And
6. Or
7. Semicolon
8. Parenthesis
##### Unit and Integration tests:
1. CommandLine Unit Test
2. Executable Unit Test
3. And Unit Test
4. Or Unit Test
5. Semicolon Unit Test
6. Input Integration Test
7. Parenthesis Integration Test
