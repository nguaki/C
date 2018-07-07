//
// Feb 11, 17
//
/*output
Enter 1st string:
gfsdgdfs
Enter 2nd string:
werwerw
longer string is gfsdgdfs
concatenate string is gfsdgdfswerwerw
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *totalString;

//Note that these strings are stored in static memory from main.
//So it is returning  memory addresses of static memory.
char *
longerString( char *p1, char *p2 )
{
    if(strlen(p1) > strlen(p2) )
        return p1;
    else
        return p2;
}


//totalString is stored in a HEAP memory.
//So, it is returning a memory address in
//HEAP memory.
char *
addString( char *p1, char *p2 )
{
    totalString = malloc(strlen(p1) + strlen(p2) );
    
    strcpy( totalString, p1 );
    strcat( totalString, p2 );


    return totalString;
    
}
int
main(void)
{
    char s1[100], s2[100];
    
    
    puts("Enter 1st string:");
    gets(s1);
    
    puts("Enter 2nd string:");
    gets(s2);
    
    printf( "longer string is %s\n", longerString(s1,s2) );
    printf( "concatenate string is %s\n", addString(s1, s2));
    
    return 0;
}

