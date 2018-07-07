// feb 18, 17
//
// Demonstration of strchr() function.
//
/*
Enter a string:abcdefghjkl
Enter a character:f
mem_location = fghjkl
mem address = 140730058064901
mem address of s1 = 140730058064896
char is found at 5 position.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(void)
{
    char s1[100];
    char c;
    char *mem_location;
    char garbage[100];
    
    
    printf("Enter a string:");
    scanf("%s", s1);
    gets(garbage);
    
    printf("Enter a character:");
    c = getchar();
    
    mem_location = strchr( s1, c );
    
    printf( "mem_location = %s\n", mem_location);//prints string.
    printf( "mem address = %ld\n", (long int) mem_location); //prints Memory address
    printf( "mem address of s1 = %ld\n", (long int)s1);//prints memory address
    
    printf("char is found at %ld position.\n", mem_location - s1 );
    
    return 0;
    
}