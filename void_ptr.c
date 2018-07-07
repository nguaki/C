#include <stdio.h>
#include <stdlib.h>


int
main(void)
{
    int i;
    char c;
    char *cp = "How are you";
    float f;
    
    void *vptr;
    
    i = 10;
    c ='O';
    
    f = 40.12345;
    
    //vptr = (void *)i;
    vptr = &i;
    printf( "%d\n", *((int *)vptr));  //vptr is a void pointer.  So it must be typecast first and then dereference it.
    
    vptr = &c;
    printf( "%c\n", *((char *)vptr));

    vptr = cp;
    printf( "%s\n", (char *)vptr );
    
    vptr = &f;
    printf( "%f\n", *((float *)vptr));
    //printf( "%d  %d\n", sizeof( void * ), sizeof(float));
    return 0;
}