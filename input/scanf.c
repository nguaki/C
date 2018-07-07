#include<stdio.h>
#include<stdlib.h>

int
main(void)
{
    char string1[10], string2[10];
  
    scanf("%[^;];",string1);
    scanf("%[^;];",string2);
    
    printf( "%s %s\n", string1, string2 );


    return 0;
}