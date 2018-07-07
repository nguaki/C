#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *a;
    int j;
}A;

A *a;


//Frees memory allocated within a structure.
void
remove_mem( int *a )
{
    free(a);
}
 
int
main(void)
{
    a = malloc(sizeof a);
    a->a = malloc( sizeof(int *));

    //free(a->a);
    remove_mem(a->a);
    free(a);
}