// April 5, 2017
//
//  A B C D E F G H I J K L    <=== string characters
//  0 1 2 3 4 5 6 7 8 9 0 1    <=== Index
//
//  p[8] = 'I'
//  p[1] = 'B'
//
//  'I' - 'B' = ascii number of 'I' - ascii number of 'B' = 7
//
//   Don't need to learn ASCII representation of character.
//   We know that ASCII # increase by 1 betweem each letter.
//   So doing a simple math, 8 - 1 = 7.
//
//  p + p[8] - p[1] = p + 7 (so it is 7th character from the beginning.)
//  p represents memory address of beginning of string.
//  p + 7 is a pointer math.
//
// OUTPUT:
//    HIJKL
//
// Apr 25, 18      Added comments.
//
#include <stdio.h>

int
main(void)
{
    char ca[] = "ABCDEFGHIJKL";
    
    char *p = ca;
    
    
    printf( "%s", p + p[8] - p[1] );
    
    return 0;
}

