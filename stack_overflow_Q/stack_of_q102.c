#include <stdio.h>

char f1() {
    return 'a';
}

char f2() {
    return 'b';
}

//fptr is a type of a funtion pointer that returns a char
typedef char (*fptr)();

//f is a function( char ) that returns a pointer to a function which returns a char.
fptr f( char c ) {
    if ( c == 'a' ) 
        return f1;
    
    else 
        return f2;
    
}

int main() {
    char (*(*fptr1)(char))();
    //char (*fptr1(char))();
    char c = 'a';

    fptr fp1 = f( c );
    printf( "%c\n", fp1());

    fptr1 = f;        
    fptr fp2 = fptr1( c );
    printf( "%c\n", fp2());
}