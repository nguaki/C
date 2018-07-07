#include <stdio.h>
#include <stdlib.h>

void
change( int *i )
{
     *i = 888;
    
}

void
change1( int *i )
{
     *i = 777;
    
}
void
change2( int **i )
{
     **i = 555;
    
}
int
main(void)
{
    int i;
    int *j;
    int **k;
    
    i = 999;
    j = &i;
    k = &j;
    
    printf("i = %d\n", i );
    printf("*j = %d\n", *j );
    printf("**k = %d\n", **k );
    
    printf("address of i = %p\n", &i);
    printf("contents of i = %d\n", i);
    
    printf( "address of j = %p\n", &j);
    printf("address of j = %p\n", j);
    printf("contents of *j = %d\n", *j );
    
    printf("address of k = %p\n", &k);
    printf("address of k = %p\n", k);
    printf("address of k = %p\n", *k);
    printf("address of k = %d\n", **k);
    
    *j = 111;
     printf("i = %d\n", i );
    printf("*j = %d\n", *j );
    printf("**k = %d\n", **k );
   
    **k = 333;
     printf("i = %d\n", i );
    printf("*j = %d\n", *j );
    printf("**k = %d\n", **k );
    
    change( &i );
    
    printf("i = %d\n", i );
    printf("*j = %d\n", *j );
    printf("**k = %d\n", **k );
    
    change1( j );
    printf("i = %d\n", i );
    printf("*j = %d\n", *j );
    printf("**k = %d\n", **k );

    change2( k );
    printf("i = %d\n", i );
    printf("*j = %d\n", *j );
    printf("**k = %d\n", **k );
    return 0;
}
