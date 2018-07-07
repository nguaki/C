/*
Feb 16, 2017

 More demonstration of pointer to a character array of [12].
 X X X X X X
X X X X X X 
 X X X X X X
X X X X X X 
 X X X X X X
X X X X X X 
 X X X X X X
X X X X X X 
 X X X X X X
X X X X X X 
 X X X X X X
X X X X X X 

Aprl 28, 18   Note the difference between char *x[12] and char (*x)[12].
              Former one is array of char *.
              Latter one is pointer to array of char.
              Converts type from (*char)[12] to *char.
*/
#include <stdio.h>

//void vDisp( char (*x)[12] );
void vDisp( char *x );

int
main(void)
{
    char c[12][12];
    char (*p_a)[12];
    
    int i, j;
    
    for( i=0; i<12; i++)
        for( j=0; j<12; j++)
        {
            if( ((i+j)%2) ) c[i][j] = 'X';
            else c[i][j] = ' ';
        }
    
    p_a = c;
    for( i = 0; i <12; i++ )
        vDisp( (char *)p_a++ );  //Type casting.
        
    return 0;
}

void
//vDisp( char (*x)[12] )
vDisp( char *x )
{
    //char *p_c;
    int  i;
    
    //p_c = (char *)x;
    
    for( i = 0; i < 12; i++ )
        //putchar(*p_c++);
        putchar(*x++);
    puts("");
}