#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
     int a[] ={3, 7, 1};
     int i;
     char singleStr[2], combineStr[4];
     int combineDec;

     for( i = 0; i < 3; i++ ){
       sprintf( singleStr, "%d", a[i] );
       //combineStr[i] = singleStr[0];          
       strcat( combineStr, singleStr );
     }
    combineStr[3] = '\0';
    
    combineDec = atoi(combineStr);
    
    return 0;
} 