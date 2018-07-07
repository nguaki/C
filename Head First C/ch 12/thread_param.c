// Feb 2, 17
//
// thread_param.c
//
// Demonstrates sending parameters to threads and also
// returning values from threads.
//
//
/*
dguai:~/workspace/Head First C/ch 12 $ gcc thread_param.c -o thread_param -lpthread
dguai:~/workspace/Head First C/ch 12 $ ./thread_param
thread number 0
thread number 1
thread returned 1
thread returned 2
thread number 2
thread returned 3

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void *
get_thread( void *param )
{
    long l = (long)param;
    
    printf( "thread number %ld\n", l );
    
    return (void *)(l + 1);
}

int
main()
{
    pthread_t t[3];
    void *result;
    long i;
    
    for( i=0; i<3; i++ )
        pthread_create( &t[i], NULL, get_thread, (void *)i);
    
    for( i=0; i<3; i++ ){
        pthread_join( t[i], &result );
        printf( "thread returned %ld\n", (long)result );
    }
    return 0;
}