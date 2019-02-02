#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;

int main(){
        char* args[3];
        string str1 = "Hello";
        string str2 = "World";
        args[0] = (char*) str1.c_str();
        args[1] = (char*) str2.c_str();
        args[2] = NULL;

        pid_t pid = fork();
        if(pid == 0){//Child process
                cout << "In the child" << endl;
                if(execvp(args[0],args) == -1){
                        perror("exec");
                }
        }

        if(pid > 0){//Parent process
                waitpid(pid,NULL);
                cout << "In the parent" << endl;

        }

}
