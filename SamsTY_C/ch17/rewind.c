// Feb 17, 17
// Demonstratin of ftell() and rewind().
//
/*
abcd
current file pointer loc = 4
current file pointer loc = 0
*/
#include <stdio.h>
#include <stdlib.h>


#define BUF_SIZE 5

char ca[] = "abcdefghijklmnopqrstuvwxyz";

int
main(void)
{
    char buffer[6];
    FILE *fp;
    
    if ((fp = fopen( "temp.txt", "w" )) == NULL ){
        printf("Error fopen to write.\n");
        exit(1);
    }
    
    if( fputs(ca,fp) == EOF ){
        printf("Error writing to a file");
        exit(1);
    }
    
    fclose(fp);
    
    if ( (fp = fopen( "temp.txt", "r" ) )== NULL ){
        printf("Error fopen to read.\n");
        exit(1);
    }
    
    fgets( buffer, BUF_SIZE, fp );
    printf( "%s\n", buffer );
    
    printf( "current file pointer loc = %ld\n", ftell(fp));
    
    
    rewind(fp);
    printf( "current file pointer loc = %ld\n", ftell(fp));
   
    
    return 0;

}