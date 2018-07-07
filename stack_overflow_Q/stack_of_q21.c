#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = malloc(NULL);
    printf( "%d", sizeof(NULL));

    strcpy( ptr, "ABCD");
    printf("%s\n", ptr);
    return 0;
}