// Feb 1, 2017
//
// Study of signal, alarm, raise commands.
//
//
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

//This is called when SIGINT signal is evoked.
void diedie( int sig )
{
    printf( "Good bye cruel world.\n" );
    exit(2);
}

//If alarm goes off, this will terminate by 
//escalation of SIGINT.
void took_too_long( int sig )
{
    printf( "Taking too long.\n" );
    raise( SIGINT );
}

//Establishes signal handling.
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
    //Set signal handler for SIGINT.
    if( catch_signal( SIGINT, diedie ) == -1 )
    {
        printf( "Cannot set up signal handler.\n" );
        exit(2);
    } 
    
    //Set signal handler for SIGALRM.
    if( catch_signal( SIGALRM, took_too_long) == -1 )
    {
        printf( "Cannot set up signal handler.\n" );
        exit(2);
    } 

    
    char answer[10];
    int i, j;
    int correct = 0;
    
    //Allows new initiation of random numbers.
    srand(time(0));
    while(1)
    {
        i = random()%11;
        j = random()%11;
        
        printf( "what is %i times %i? \n", i, j );
        //If this line is not executed within 5 secs,
        //alarm goes off.
        //If this line gets executed within 5 secs,
        //alarm is reset.
        alarm(5);
        fgets( answer, 50, stdin );
        
        
        if( atoi(answer) == i*j )
            printf( "You got %i correct.\n", correct++ );
        else
            printf( "Sorry!. Wrong answer.\n" );
    }
            
    return 0;
}