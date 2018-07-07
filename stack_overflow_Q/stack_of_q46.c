#include <stdio.h>
#include <stdlib.h>

const size_t stIncrement = 2;

typedef struct
{
    size_t space_left;
    size_t size;
    void **vptrX;
}T;

T t;

void
vStoreData( void *data )
{
    void *vptrTemp;
    size_t stMaxLength;
    
    if( t.space_left == 0 )
    {
        stMaxLength = t.size + stIncrement;
        vptrTemp = realloc(t.vptrX, stMaxLength * sizeof(void *) );
        if( vptrTemp == NULL ){
            printf( "Failed realloc");
            exit(1);
        }
        t.space_left = stIncrement;
        t.vptrX = vptrTemp;
    }
    
    t.vptrX[t.size++] = data;
    t.space_left--;
}

//This will make the memory efficient.
void
vFinalizeMemory()
{
   t.vptrX = realloc(t.vptrX, t.size * sizeof(void *));
}

int
main(void)
{
    int i;
    char c;
    float d;
    char *cp = "How are you";
    i = 10;
    c ='O';
    
    d = 40.12345;
    t.vptrX = malloc(stIncrement*sizeof(void *));
    t.size = 0;
    t.space_left = 2;

    vStoreData( &i );
    printf( "%d\n", *((int *)t.vptrX[0]) );
    
    vStoreData( &c );
    printf( "%c\n", *((char *)t.vptrX[1] ));

    vStoreData( cp );
    printf( "%s\n", (char *)t.vptrX[2] );
    
    vStoreData( &d );
    printf( "%f\n", *((float*)t.vptrX[3] ));
    //printf( "%d  %d\n", sizeof( void * ), sizeof(float));

     vStoreData( &c );
    printf( "%c\n", *((char *)t.vptrX[4] ));

    vStoreData( cp );
    printf( "%s\n", (char *)t.vptrX[5] );
    
    vStoreData( &d );
    printf( "%f\n", *((float*)t.vptrX[6] ));
   
    vFinalizeMemory();
    printf( "%d\n", *((int *)t.vptrX[0]) );
    printf( "%c\n", *((char *)t.vptrX[1] ));
    printf( "%s\n", (char *)t.vptrX[2] );
    printf( "%f\n", *((float*)t.vptrX[3] ));
    printf( "%c\n", *((char *)t.vptrX[4] ));
    printf( "%s\n", (char *)t.vptrX[5] );
    printf( "%f\n", *((float*)t.vptrX[6] ));

    return 0;
}