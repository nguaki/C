//////////////////////////////////////////////////////////////////
//April 20, 17
//
//Demonstration of complexity behind fork() command.
//
//OUTPUT:
//
//Hello there.
//Hello there.
//Hello there.
//Hello there.
//////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    fork();
    fork();
    printf("Hello there.\n");

    return 0;
}
