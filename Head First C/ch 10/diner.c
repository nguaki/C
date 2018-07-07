#include <stdio.h>
#include <stdlib.h>

int
main( int argc, char *argv[])
{
    int i;
    printf("# of Diners:%i\n", atoi(argv[1]) );
    
    for( i = 2; i < (atoi)(argv[1]) + 2; i ++ )
        printf( "Dish: %s\n", argv[i] );
    
    printf( "DRINK: %s\n", getenv("DRINK"));
        
    return 0;
}