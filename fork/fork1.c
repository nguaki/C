////////////////////////////////////////
// 
// April 20. 17
//
// fork1.c
//
// Demonstration of process ID that is returned to parent process
// and child process.
//
// OUTPUT:
// Hello there.
// Hello there.
// Hello there.
// Hello there.
// Hello there.
/////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    pid_t pid;
    
    pid = fork();
    if( pid > 0 ){
        fork();
        printf("Hello there.\n");
    }
    printf("Hello there.\n");
    return 0;
}