// Feb 15, 17
//
// More tests on UNION.
/*
size of structure = 8  <==== This is 8 due to WORD boundary. It should have been 4+1.
Size of union is 4 since largest element is float which is size of 4.
character = X
integer = 100
float = 25.250000
*/
#include <stdio.h>

#define CHARACTER 'c'
#define INTEGER   'i'
#define FLOAT     'f'

struct xyz{
    char type;
    union union_tag{
        char  c;
        int   i;
        float f;
    }shared;   // Instatiation of a union.  This becomes a variable.
};

void
display( struct xyz xyz )
{
    switch( xyz.type )
    {
        case CHARACTER:
            printf( "character = %c\n", xyz.shared.c );
            break;
        case INTEGER:
            printf( "integer = %d\n", xyz.shared.i );
            break;
        case FLOAT:
            printf( "float = %f\n", xyz.shared.f );
            break;
    };
}

int
main(void)
{
    struct xyz xyz;
    
    printf( "size of structure = %d\n", (int)sizeof(struct xyz));
    xyz.type = CHARACTER;
    xyz.shared.c = 'X';
    display( xyz );
    xyz.type = INTEGER;
    xyz.shared.i = 100;
    display( xyz );
    xyz.type = FLOAT;
    xyz.shared.f = 25.25;
    display( xyz );

    return 0;
}

