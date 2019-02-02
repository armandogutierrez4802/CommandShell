#include "unistd.h"
#include "sys/types.h"
#include "sys/wait.h"

int main() {
    pid_t pid;
    int status;
    
    char* cmdLine[3] = { ;
    cmdLine[0] = "cd";
    cmdLine[1] = "..";
    cmdLine[2] = NULL;
    
    pid = fork();
    if(pid == 0) {
        execvp("cd", cmdLine);
    } else {
        wp = waitpid(pid, &status, 0);
        execvp("cd", cmdLine);
    }
}