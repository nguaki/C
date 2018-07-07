// Jan 29, 17
//
// Demonstration of fork() and execle() command.
// By using child process, now it goes thru all three loop.
// But still there is a problem. 
// These child processes overlap each other.
// In order to resolve this overlap problem, we need to make sure
// each child process terminates before starting a new process.
// We do this with waitpid() command.
// Furthermore, we use dup2() command to redirect the stdout to
// a text file.
// The text file looks like as follows:
/*
# of Diners:2
# of Diners:2
Dish: chicken
Dish: chicken
Dish: beef
Dish: beef
DRINK: COKE
DRINK: ORANGE JUICE
# of Diners:2
Dish: chicken
Dish: beef
DRINK: ICE-TEA
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

    int i, pid_status;
    FILE *f = fopen( "output.txt", "w");
    
    if( !f ){
        error( "Cannot open a file to write.");
    }
    
    
    for( i=0; i<3; i++ ){
        sprintf( drink, "DRINK=%s", drinks[i] );
        char *myEnv[] = { drink, NULL };

        pid_t pid = fork();
        
        if( pid == -1 ){
            error( "Can't fork process. \n" );
        }
        
        if( !pid ){
            
            printf( "file number = %u\n", fileno(f));
            
            if( dup2( fileno(f), 1) == -1 ){
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
    }
    return 0;
}