//Bible
//How to pray?
//Book of John
//Learn C
//Calculus
//Teach yourself PHP
//
// One storage.  Use pointer to just point to this storage.
#include <stdio.h>

int
main(void)
{
    char *books[] = { "Bible", "Learn C", "How to pray?", "Calculus", "Book of John", "Teach yourself PHP" };
    
    char **ChristianBooks[3];
    char **TextBooks[3];
    int i;
    
    ChristianBooks[0] = &books[0];
    ChristianBooks[1] = &books[2];
    ChristianBooks[2] = &books[4];
    
    TextBooks[0] = &books[1];
    TextBooks[1] = &books[3];
    TextBooks[2] = &books[5]; 
    
    for( i=0; i<3; i++ )
        printf( "%s\n", *ChristianBooks[i] );
    for( i=0; i<3; i++ )
        printf( "%s\n", *TextBooks[i] );
    
    return 0;
}