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

# Development and Testing Roadmap
