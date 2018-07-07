#include <stdio.h>
#include <stdlib.h>

typedef struct que_adt {
    unsigned int head;
    unsigned int rear;
    unsigned int empty;
    unsigned int capacity;
    unsigned int nitems;
    void **array;
    int (*cmp)(const void *a, const void *b);
} QueueADT;

int
compare( const void *a, const void *b)
{
    return 1;
}

QueueADT que_create(int (*cmp)(const void *a, const void *b)) {
    QueueADT queue = {0, 0, 1, 10, 0, calloc(10, sizeof(void *)), cmp};
    return queue;
}

int
main(void)
{
    QueueADT q = que_create( compare );

    return 0;
}