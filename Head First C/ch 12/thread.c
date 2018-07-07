//Demonstration of creating threads.
//
// thread.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>


void 
error( char *msg )
{
    fprintf( stderr, "%s %s\n", msg, strerror(errno));
}

void *
i_have( void *x )
{
    int i; 
    
    for( i=0; i<5; i++ ){
        sleep(1);
        puts( "i have.\n" );
    }
    
    return NULL;   
}

void *
i_have_not( void *x )
{
    int i;
    
    for( i=0; i<5; i++ ){
        sleep(1);
        puts( "i have not.\n" );
    }
    
    return NULL;   
}

int
main()
{

    pthread_t p1;
    pthread_t p2;
    void *result;
    
    if ( pthread_create( &p1, NULL, i_have, NULL ) == -1 )
        error( "Cannot create p1 thread.");
        
    if ( pthread_create( &p2, NULL, i_have_not, NULL ) == -1 )
        error( "Cannot create p2 thread.");
        
    if ( pthread_join( p1, &result ) == -1 )
        error( "Can't join thread.");
    if ( pthread_join( p2, &result ) == -1 )
        error( "Can't join thread.");
        
    return 0;
       
}