#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

int main() {

    char *args[2] = {"DD", NULL};
    int  waitVal3, waitVal4, rc, waitStatus;
    pid_t D;
    
    D = fork();
    if ( D == -1 )
    {
        printf("fork failed\n");
       exit(1);
    }
    
    if(D != 0)
    {
        printf("\nPid = %d Code AA: created proccess Pid = %d (code DD)\n", getpid(), D);
    }

    if(D == 0)
    {
       // ORIG: execv("DD", args);
      if( execv("/home/ubuntu/workspace/C/DD", args) == -1 ){
          printf("execv failed: errno: %d\n", errno);
          exit(1);
      } else {
          printf("Running DD executable ...\n");
      }
      
      if( waitpid( D, &waitStatus, 0 ) == -1 ){
          printf("Error waiting child process.\n");
          exit(1);
      };
      printf("INSIDE Pid = %d Code AA: process Pid = %d terminated\n", getpid(), D);
      
    }
     
    if( waitpid( D, &waitStatus, 0 ) == -1 ){
          printf("Error waiting child process.\n");
          exit(1);
      };
      //printf("\nPid = %d Code AA: process Pid = %d terminated\n", getpid(), D);
     printf("OUTSIDE Pid = %d Code AA: process Pid = %d terminated\n", getpid(), D);

    return 0;
}