#include <stdio.h>

char f1() {
    return 'a';
}

char f2() {
    return 'b';
}

typedef char (*fptr)();
typedef char (*(*fptr1)(char))();

//f is a function( char ) that returns a pointer to a function which returns a char.
fptr f( char c ) {
    if ( c == 'a' ) 
        return f1;
    
    else 
        return f2;
    
}

int main() {
    fptr1 z;
    char c = 'a';

    fptr fp1 = f( c );
    printf( "%c\n", fp1());

    z = f;        //error: lvalue required as left operand of assignment
    fptr fp2 = z( c );
    printf( "%c\n", fp2());
}