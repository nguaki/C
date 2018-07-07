// Jan30, 2017
//
//  signal handler
//
/*
from one terminal, send a signal using kill command
------------------------------------------------------
ubuntu      3090     608  0 04:10 pts/3    00:00:00 ./signal
ubuntu      3093     606  0 04:11 pts/1    00:00:00 ps -ef
dguai:~/workspace $ kill -SIGINT 3090


The OS sends a signal and signal handler captures the sign.
--------------------------------------------------------------
dguai:~/workspace/Head First C/ch 10 $ ./signal
Good bye cruel world.

*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void diedie( int sig )
{
    printf( "Good bye cruel world.\n" );
    exit(2);
}


int catch_signal( int sig, void (* handler)(int) )
{
    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    
    return sigaction( sig, &action, NULL );
}

int
main()
{
    if( catch_signal( SIGINT, diedie ) == -1 )
    {
        printf( "Cannot set up signal handler.\n" );
        exit(2);
    } 
    
    char name[50];
    
    fgets( name, 50, stdin );

    return 0;
}