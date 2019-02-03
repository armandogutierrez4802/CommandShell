# CS 100 Programming Project
Winter 2019\
Armando Gutierrez 861213968\
Nhat Nguyen 862119873

# Introduction
This project involves implementing a RShell, a basic command shell written in C++ that satisfies the following criterias: 
1. Print command prompts.
2. Read in command lines. Distinguishing between executables, arguments, connectors, and commands.
3. Execute commands using fork, execvp, waitpid.

In addition, this project will be implemented using the composite pattern as the core design principle.

# Diagram
![UML Diagram](https://github.com/cs100/assignment-cs_100_aa_assignment_1/blob/master/Images/Assignment_1_UML.jpeg?raw=true)

# Classes
* Base
  * Serves as the primary interface that classes in the composite pattern inherit from. Implements two functions that each subclass must implement: Print() and ReadLine().
* Command
  * Handles the execution of commands such as: fork, execvp, and waitpid.
* Connector
  * *And*\
Has two private member variables: leftChild and rightChild (Base pointers). And handles two commands, in which the following command is executed only if the first command (leftChild) is successfully completed.
  * *Or*\
Has two private member variables: leftChild and rightChild (Base pointers). Or handles two commands, in which the following command is executed only if the first command (leftChild) fails.
  * *Semicolon*\
Has two private member variables: leftChild and rightChild (Base pointers). Semicolon handles two commands, in which the following command is executed regardless if the first is successfully completed or fails.
* Command Line
  * Holds multiple commands seperated by connectors that is to be executed.
# Prototypes/Research
The purpose of the prototype is to apply what we have researched and learned about the functions waitpid(), execvp() and fork(). The execvp() function takes in two arguments. The first of which is the name of the file that is going to be executed. Once the first argument is loaded into the caller's address space and over-writes the program, then the second argument will be provided to the program right before it executes. The fork() function creats an identical process to the one being ran. The two processes are called the Child and the Parent. These two processes will run simultaneously unless a wait() function is called. The waitpid() function, if called in the parent process, will cause the parent process to wait until the specified, usually once the child process is terminated. \
These functions will be useful in our assignment because our connectors determine how two variables on either side of it will relate to one another. Depending on whether the connector is and &&, ||, or semicolon, we may or many not want/need to execute the parent process by the results of execution of the child process.

# Development and Testing Roadmap
### Tasks to be completed:
##### Class implementations:
1. Base
2. Command
3. Connector
4. Command Line
5. And
6. Or
7. Semicolon
##### Unit and Integration tests:
1. Command Unit Test
2. Connector Unit Test and Integration Test
3. Command Line Unit and Integration Test
4. And Unit Test
5. Or Unit Test
6. Semicolon Unit Test

