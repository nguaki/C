// Jan 29, 17
//
// Exercising fork() and execle() and dup2() and pipe command.
// By using child process, now it goes thru all three loop.
// But still there is a problem. 
// These child processes overlap each other.
// In order to resolve this overlap problem, we need to make sure
// each child process terminates before starting a new process.
// We do this with waitpid() command.
// Furthermore, we use dup2() command to redirect the stdout to
// a text file.
// The text file looks like as follows:
//
// This program takes one step further by creating a pipe between
// child and parent process.  The stdout of the child process is
// piped to stdin of the parent process.
/*
parents: # of Diners:2

parents: Dish: chicken

parents: Dish: beef

parents: DRINK: ORANGE JUICE

parents: # of Diners:2

parents: Dish: chicken

parents: Dish: beef

parents: DRINK: COKE

parents: # of Diners:2

parents: Dish: chicken

parents: Dish: beef

parents: DRINK: ICE-TEA

*/
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void
error( char *msg )
{
    fprintf( stderr, "%s: %d\n", msg, strerror(errno));
    //exit(1);
}

int
main()
{

    char *drinks[] = { "ORANGE JUICE", "COKE", "ICE-TEA" };
    char drink[50];
    
    int fd[2];

    int i, pid_status;
    
    
    
    for( i=0; i<3; i++ ){
        if( pipe(fd) == -1 ){
            error( "Cannot create a pipe.\n" );
        }
        
        sprintf( drink, "DRINK=%s", drinks[i] );
        char *myEnv[] = { drink, NULL };

        pid_t pid = fork();
        
        if( pid == -1 ){
            error( "Can't fork process. \n" );
        }
        
        if( !pid ){
            
            //close reading end of the pipe.
            close(fd[0]);
            //make STDOUT same as the pipe writing.
            //In other words, what ever is written on STDOUT will be written to the pipe.
            //STDOUT equals to writing end of the PIPE.
            if( dup2( fd[1], 1) == -1 ){
                    error( "Can't redirect Standard output");
            
                    perror("dup2 failed");
            }
            if( execle( "/home/ubuntu/workspace/Head First C/ch 9/diner", "/home/ubuntu/workspace/Head First C/ch 9/diner", "2", "chicken", "beef", NULL, myEnv ) == -1 )
            {
                error( "Cannot run diner\n");
            }
            if( waitpid(pid, &pid_status, 0) == -1 ){
                error( "Error waiting for child process" );
            }
        }
        
        
        //Whatever written is written to the pipe will be considered as STDIN.
        //STDIN = reading end of the pipe.
        dup2(fd[0], 0);
        
        //Close the written end of the pipe.
        //This part is needed.  Without it, this works only for the first loop.
        close(fd[1]);
    
        char line[255];
        
        while( fgets(line, 255, stdin) ){
            printf("parents: %s\n", line);
        }
    }
    return 0;
}