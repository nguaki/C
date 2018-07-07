#include <stdio.h>
#include <stdlib.h>

struct graph{
    int v;
    int e;
    int z;
    struct graph **admat;
};
void main()
{
    int x,i,y,z=1,n;
    struct graph *G= malloc(sizeof(struct graph *));
    printf("\nenter number of vertices: ");
    scanf("%d",&G->v);
    printf("\nenter number of edges: ");
    scanf("%d",&G->e);
    G->admat=malloc(G->v * sizeof(struct graph *));
    for(i=0;i<G->v;i++)
    {
        G->admat[i]=malloc(G->v * sizeof(int));//here is the main error
    }
    for(x=0;x<i;x++)
    {
        for(y=0;y<i;y++)
        {
            G->admat[x][y].z=z++;
        }
    }
    for(x=0;x<i;x++)
    {
        for(y=0;y<i;y++)
        {
            printf(" %d ",G->admat[x][y].z);
        }
        printf("\n");
    }
}