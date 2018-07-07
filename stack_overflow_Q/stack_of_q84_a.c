#include <stdio.h>
#include <stdlib.h>

typedef struct XYZ{
    int i;
    struct XYZ *next;
}XYZ;

XYZ *
push( XYZ *pXYZ, int i )
{
    XYZ *pTemp = malloc(sizeof(*pXYZ));
    
    pTemp->i = i;
    pTemp->next = pXYZ;
    
    return pTemp;
}

void
vRemDup( XYZ *l )
{
    while( (l != NULL) && (l->next != NULL ) )
    {
        if( l->i == l->next->i )
        {
            XYZ *pT = l->next;
            l->next = l->next->next;
            free(pT);
        }
        else
        {
            l = l->next;
        }
    }
}

void
vPrint( XYZ *l )
{
    while( l != NULL ){
        printf( "%i ", l->i);
        l = l->next;
    }

    printf("\n");
}

int
main(void)
{
    XYZ *pTOS = NULL;
    
    pTOS = push( pTOS, 2 );
    pTOS = push( pTOS, 2 );
    pTOS = push( pTOS, 4 );
    pTOS = push( pTOS, 4 );

    vPrint( pTOS );
    
    vRemDup( pTOS );
    
    vPrint( pTOS );
    
    return 1;
    
}
    