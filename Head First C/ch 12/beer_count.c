// Feb 2, 2017
//
// Demonstration of MUTEX of locking and unlocking variables
// for threads.
/*
dguai:~/workspace/Head First C/ch 12 $ ./beer_count
beers left = 1897449
beers left = 1700000
beers left = 1700000
beers left = 1600000
beers left = 1500000
beers left = 1400000
beers left = 1300000
beers left = 1200000
beers left = 1100000
beers left = 1000000
beers left = 900000
beers left = 800000
beers left = 700000
beers left = 600000
beers left = 500000
beers left = 400000
beers left = 300000
beers left = 200000
beers left = 100000
beers left = 0
Total number of beers left: 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int num_of_beers = 2000000;
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;


void 
error( char *msg )
{
    fprintf( stderr, "%s %s\n", msg, strerror(errno));
}


void *
drink_beer( void *x )
{
    int i;
    
    pthread_mutex_lock( &beers_lock );
    for( i=0; i<100000; i++ )
        num_of_beers--;
    pthread_mutex_unlock( &beers_lock );
    
    printf( "beers left = %i\n", num_of_beers );
    
    return NULL;   
}

int
main()
{

    int i;
    pthread_t p[20];
    void *result;
    
    for( i = 0; i < 20; i ++ )
    {
        if ( pthread_create( &p[i], NULL, drink_beer, NULL ) == -1 )
        error( "Cannot create p1 thread.");
    }    

    for( i = 0; i < 20; i ++ )
    {
        if ( pthread_join( p[i], &result ) == -1 )
           error( "Can't join thread.");
    }
    
    printf( "Total number of beers left: %d\n", num_of_beers );
    return 0;
}