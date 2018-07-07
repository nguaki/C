/*
10
10
10
10
10
100
*/
#include <stdio.h>
#include <stdlib.h>

//array can be either already malloced or not malloced.
void
storeInt( int **array, int size, int value )
{
    int i;
    
    if( *array == NULL ){
        *array = malloc( size * sizeof(int));
    }
    for( i = 0; i < size; i++ )
        //(*array)[i] = value;  //*array[i] doesn't work.  subscript has higher 
        //array[0][i] = value;    //preference over *.  There must be a parenthesis
                              // aroung *array.
                              //This is sames as array[0][i] is same as (*array)[i];
        *(*array+i) = value;
}
void
storeInt2( int *array, int size, int value )
{
    int i;
    
    array = malloc( size * sizeof(int));
    
    for( i = 0; i < size; i++ )
        array[i] = value;  //*array[i] doesn't work.  subscript has higher 
        //array[0][i] = value;    //preference over *.  There must be a parenthesis
                              // aroung *array.
                              //This is sames as array[0][i] is same as (*array)[i];
        
}
void
storeInt1( int *p, int size, int value )
{
    int i;
    
    for( i=0; i<size; i++)
        p[i] = value;
}


int
main(void)
{
    int *i = NULL, *k = NULL;
    int j;
    
    int *p;
    
    p = malloc(sizeof p);
    
    storeInt( &i, 5, 10 );
    storeInt( &k, 1, 100 );
    storeInt( &p, 5, 500 );
    //storeInt2( &i, 5, 78);
    
    for( j=0; j < 5; j++ )
        printf("%d\n", i[j] );
    for( j=0; j < 1; j++ )
        printf("%d\n", k[j] );
        
    for( j=0; j < 5; j++ )
        printf("%d\n", p[j] );
    storeInt1( p, 5, 1000 );
    for( j=0; j < 5; j++ )
        printf("%d\n", p[j] );
       
    if(i)  free(i);
    if(k)  free(k);
    if(p)  free(p);
    
    return 0;
}
    