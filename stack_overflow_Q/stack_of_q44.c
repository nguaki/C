#include <stdio.h>

struct vertice_t{
    char city;
    char connectedBy;
    unsigned short airportCost;
    unsigned short primKey;
    int queueIndex;
    struct adjacency_list_t * adjacencyList;
};

struct adjacency_list_t{
    struct adjacency_list_node_t *  first;
    struct adjacency_list_node_t *  last;
};

struct adjacency_list_node_t{
    unsigned short weight;
    struct vertice_t *  vertice;
    struct adjacency_list_node_t * next;
};

int
main(void)
{
    printf( "%ld\n", sizeof(struct vertice_t) );
    printf( "%ld\n", sizeof(struct adjacency_list_t *) );
    
    return 0;
}