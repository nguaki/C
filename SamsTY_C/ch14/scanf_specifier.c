/*
   Feb 14, 17

   Demonstrates the power of scanf format string specifier.

    scanf( "%ld %f", &l, &f );
    scanf( "%2d%3d", &i1, &i2 );            //first 2 digits is i1. following 3 digits  is i2.
    scanf( "%[^ ]%s", firstname, lastname );//Read everything except a space character.

    Enter a long and float
    42342 344323.34
    long = 42342   float = 344323.343750   <== Why decimal is off?
    Enter a number
    234234234
    i1 = 23 i2 = 423    <== follows specifier
    Enter first and last name
    afdfads fdfd werwe  <== follows specifier
    firstname = afdfads lastname = fdfd

    Enter a long and float
    34545   4534.2345     345454          <== Note multiple spaces between 2 numbers.  3rd number is ignored.  
    long = 34545   float = 4534.234375
    Enter a number
    12345677
    i1 = 12 i2 = 345                      <== designed to read certain number of digits.
    Enter first and last name
    james       che sdafasf
    firstname = james lastname = che      <=== note that 3rd string is ignored.

*/
#include <stdio.h>

int
main(void)
{
    int i1, i2;
    long l;
    float f;
    char garbage[40];
    char firstname[10], lastname[10];
    
    puts( "Enter a long and float" );
    //Read 2 distinct numbers.
    scanf( "%ld %f", &l, &f );
    
    fgets( garbage, 40, stdin );   //flushes buffer stdin buffer. 
    printf( "long = %ld   float = %f\n", l, f );
    
    puts( "Enter a number" );
    
    //Read certain number of digits.
    scanf( "%2d%3d", &i1, &i2 ); //first 2 digits is i1. following 3 digits  is i2.
    
    fgets( garbage, 40, stdin );   //flushes buffer stdin buffer.
    printf( "i1 = %d i2 = %d\n", i1, i2 );
    
    puts( "Enter first and last name" );
    
    //Read everything but a space.
    scanf( "%[^ ]%s", firstname, lastname );//Read everything except a space character.
    
    fgets( garbage, 40, stdin );  //flushes buffer stdin buffer.
    printf( "firstname = %s lastname = %s\n", firstname, lastname );

    return 0;
}