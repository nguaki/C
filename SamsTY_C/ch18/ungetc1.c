// Feb 18, 17
//
// Demonstration of ungetc().
//
//hello
#include <stdio.h>

int main()
{
    ungetc('\n',stdin);  //<=== Pushes characters to stdin stream.
    ungetc('o',stdin);
    ungetc('l',stdin);
    ungetc('l',stdin);
    ungetc('e',stdin);
    ungetc('h',stdin);

    while(putchar(getchar()) != '\n')
        ;

    return(0);
}
