#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void* a, const void* b);

typedef struct{

    int peso;
 }aresta_;

int comp(const void* a, const void* b)
{
    aresta_* a1 = (aresta_*)a;
    aresta_* b1 = (aresta_*)b;



    return a1->peso - b1->peso;
}
int main(int argc, const char * argv[]) {

    aresta_* array /*struct array, has field peso of type int*/;
    int dim=7;
    int dim_aux=4;
    int i;

    array = (aresta_*) malloc(dim * sizeof(aresta_));

    array[0].peso=1;
    array[1].peso=6;
    array[2].peso=2;
    array[3].peso=3;


    printf("First sort:\n");
    for(i=0; i<dim_aux; i++)
        printf("%d ",array[i].peso);

    printf("\n");


    qsort(array, dim_aux, sizeof(array[0]), comp);


    for(i=0; i<dim_aux; i++)
        printf("%d ",array[i].peso);

    printf("\n\n");

    array[4].peso=1;
    array[5].peso=5;
    array[6].peso=1;

    printf("Second sort:\n");


    for(i=0; i<dim; i++)
        printf("%d ",array[i].peso);

    printf("\n");

    qsort(array, dim, sizeof(array[0]), comp);

    for(i=0; i<dim; i++)
        printf("%d ",array[i].peso);




    printf("\n");

}