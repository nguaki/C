#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main (int argc, char *argBB[]) {

    int C3, waitVal, waitVal2, ps;
    C3 = fork(); 
    
    if(C3 < 0)
    {
        printf("Fork failed");
        exit(1);
    }

    if(C3 != 0)
    {
        printf("\nPid = %d Code DD: created proccess Pid = %d (code CC)\n", getpid(), C3);
    }
    if( C3 == 0 )
    {
        if( execv("CC", 0) == -1 ){
            printf("\nexecv failed\n");
            exit(0);
        }
    }


    ps = fork();
    if(ps < 0)
    {
        printf("Fork failed");
        exit(1);
    }

    if(ps != 0)
    {
        printf("\nPid = %d Code DD: created proccess Pid = %d (code ps)\n", getpid(), ps);
    }

    if( ps == 0 )
    {
        char command[50];
        strcpy(command, "ps -u username");
        system(command);    
        exit(11);
        kill(ps, SIGKILL);//KILL PROCCESS PS HERE
    }

    waitVal = wait(&waitVal2);

    if(waitVal == ps)
    {
        printf("\nPid= %d Code DD: process Pid = %d terminated\n", getpid(), ps);
        printf("\nPid = %d Code DD: killing process Pid = %d\n", getpid(), C3);
        kill(C3, SIGKILL);
        printf("\nPid= %d Code DD: process Pid = %d terminated\n", getpid(), C3);
        printf("\nPid = %d Code DD: terminating\n", getpid());
        exit(7);
    }

    return 0;



}
