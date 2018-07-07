/*
ddde   dddd are different
winner = 0
winner = 1
winner = 1
winner = 1
aaaa
aaaa
aaaa
bbbb
bbbb
bbbb
cccc
cccc
cccc
dddd
dddd
dddd
0x7ffc93e67fc0
0x7ffc93e67fc5
0x7ffc93e67fca
0x7ffc93e67fcf
0x7ffc93e68000
0x7ffc93e68008
0x7ffc93e68010
0x7ffc93e68018
0x25f1010
0x25f1018
0x25f1020
0x25f1028
sizeof a = 20
sizeof sa = 32
sizeof da = 8
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
checkIfWin(char array[4][5], char array2[4][5])
{
       int winner = 1, i;

       for(i = 0; i < 4; i++){

          if((strncmp(array2[i], array[i], 4)) != 0){
              printf("%s   %s are different\n", array2[i], array[i]);
             winner = 0;
             break;
          }
       }
      
     return winner;

}
int 
checkIfWin_sp(char *array[4], char *array2[4])
{
       int winner = 1, i;

       for(i = 0; i < 4; i++){

          if((strncmp(array2[i], array[i], 4)) != 0){
              printf("%s   %s are different\n", array2[i], array[i]);
             winner = 0;
             break;
          }
       }
      
     return winner;

}
int 
checkIfWin_dp(char **array, char **array2)
{
       int winner = 1, i;

       for(i = 0; i < 4; i++){

          if((strncmp(array2[i], array[i], 4)) != 0){
              printf("%s   %s are different\n", array2[i], array[i]);
             winner = 0;
             break;
          }
       }
      
     return winner;

}
int
main(void)
{
    char a[4][5] = { "aaaa", "bbbb", "cccc", "dddd" };
    char b[4][5] = { "aaaa", "bbbb", "cccc", "ddde" };
    //char **pa, **pb;
    
    //pa = (char **)a;  
    //pb = (char **)b;
    char *sa[] = { "aaaa", "bbbb", "cccc", "dddd" }; //Memory address are equally separated
    char *sb[] = { "aaaa", "bbbb", "cccc", "dddd" };
    
    char **da;
    char **db;
    int i;
    
    da = malloc( 4 * sizeof(char *));
    for( i =0; i<4; i++)
    {
        da[i] = malloc( 5 * sizeof(char )); //Each address can be non-equally separated.
    }
    strcpy( da[0], "aaaa" );
    strcpy( da[1], "bbbb" );
    strcpy( da[2], "cccc" );
    strcpy( da[3], "dddd" );
    
    db = malloc( 4 * sizeof(char *));
    for( i =0; i<4; i++)
    {
        db[i] = malloc( 5 * sizeof(char ));
    }
    strcpy( db[0], "aaaa" );
    strcpy( db[1], "bbbb" );
    strcpy( db[2], "cccc" );
    strcpy( db[3], "dddd" );
    
    
    printf( "winner = %d\n", checkIfWin(a, b) );

    printf( "winner = %d\n", checkIfWin_sp(sa, sb) );
    printf( "winner = %d\n", checkIfWin_dp(sa, sb) ); //No compilation error.
    printf( "winner = %d\n", checkIfWin_dp(da, db) ); //No compilation error.
    
    //It is hard to tell the true type of these variables since they
    //all behave as an array.
    for( i=0; i<4; i++){
        printf( "%s\n", a[i] );
        printf( "%s\n", sa[i] );
        printf( "%s\n", da[i] );
    }
    
    for( i=0; i<4; i++){
        printf( "%p\n", &a[i] );
    }
    for( i=0; i<4; i++){
        printf( "%p\n", &sa[i] );
    }
    for( i=0; i<4; i++){
        printf( "%p\n", &da[i] );
    }
    
    printf( "sizeof a = %lu\n", sizeof(a));
    printf( "sizeof sa = %lu\n", sizeof(sa));
    printf( "sizeof da = %lu\n", sizeof(da));
    
    return 0;
}