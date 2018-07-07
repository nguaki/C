//March 29, 17
//
//This is a demonstration of using array to set up integer array.
//This is the best method to return an array of int.
//It makes the memory management more visible.
/*
OUTPUT
ip[0] = 0
ip[1] = 1
ip[2] = 4
ip[3] = 9
ip[4] = 16
ip[5] = 25
ip[6] = 36
ip[7] = 49
ip[8] = 64
ip[9] = 81
ip[10] = 100
ip[11] = 121
ip[12] = 144
ip[13] = 169
ip[14] = 196
ip[15] = 225
ip[16] = 256
ip[17] = 289
ip[18] = 324
ip[19] = 361
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void
int_cpy( int *ip, int size)
{
    int i = 0;
    
    for( i = 0; i < size; i++ )
        ip[i] = i * i;
}

int
main(void)
{

    int *ip, i;
    
    ip = malloc(50*sizeof(int));
    
    int_cpy(ip, 20);
    
    for( i = 0; i < 20; i++ )
        printf( "ip[%i] = %i\n", i, ip[i] );
    
    if( ip )
        free(ip);
    return 0;
}
