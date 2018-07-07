#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>    
#include <string.h>    
#include <sys/wait.h>
#include <errno.h>

int main() {

    char *args[2] = {"DD", NULL};
    int D, waitVal3, waitVal4, rc, waitStatus;
    D = fork();
    if ( D == -1 )
    {
        printf("fork failed\n");
       exit(1);
    }
    if(D == 0)
    {
       // ORIG: execv("DD", args);
       rc = execv("/some/path/to/DD", args);
       printf("execv failed: errno: %d\n", errno);
       exit(1);
    }
    if(D != 0)
    {
    printf("\nPid = %d Code AA: created proccess Pid = %d (code DD)\n", getpid(), D);
    }


    waitVal4 = wait(&waitStatus);
    waitVal3 = (waitVal4);
       //ORIGINALLY - NEVER ENTERS THIS CONDITION
    printf("WAIT VAL: %d", waitVal3);
    if(waitVal3 == D)
    {
    printf("\nPid = %d Code AA: process Pid = %d terminated\n", getpid(), D);

    }
    return 0;

}