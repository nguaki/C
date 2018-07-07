//OUTPUT
//
//-5
//25
//-5
//25
//-5
//25
//-5
//25
//-5
//25
//
//Applying function pointer to functions.
//This is polymorphism in C prog language.
//

#include <stdio.h>

int 
sum( int a, int b )
{
    return a + b;
}

int
sub( int a, int b )
{
    return a - b;
}

int
main()
{
    int (*op)(int, int);
    
    int a = 10, b = 15;
    
    for( int i = 0; i < 10; i++ ){
        if( (i%2) == 0)    op = &sub;
        else op = &sum;
        
        int result;
    
        result = op(a,b);
    
        printf("%d\n", result );
    }
    
    return 0;
}