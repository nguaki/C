#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct node
    {
        int data;
        struct node *nextNode;
    };

    int counter = 10;
    struct node *nodeSpace = malloc(counter * sizeof(struct node));
    int i;
    
    for(i = 0; i < counter; i++)
    {
        struct node currentNode = nodeSpace[i];
        currentNode.data = i;

        if(i == counter-1)
            currentNode.nextNode = NULL;
        else
            currentNode.nextNode = &nodeSpace[i+1];

        printf("Node (%i): Address: %p Data: %i Next: %p\n",
               i, currentNode, currentNode.data, currentNode.nextNode);
    }

    free(nodeSpace);
    return 0;
}