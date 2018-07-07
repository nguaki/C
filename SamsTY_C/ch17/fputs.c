// Feb 17
//
// Demonstration of fputs().
//
/*
Enter filename:temp.txt
abcdefghijklmnopqrstuvwxyz
*/
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 80

int
main(void)
{
    FILE *fp;
    char buffer[81], fileName[40];
    char *bf;
    
    printf("Enter filename:");
    scanf( "%s", fileName );
    
    if (( fp = fopen(fileName, "r") ) == NULL ){
        fprintf( stderr, "fopen error.\n" );
        exit(1);
    }
    
    while( !feof(fp) ){
        
        //bf is same as buffer.
        if ( (bf = fgets( buffer, BUF_SIZE, fp )) == NULL ){
            fprintf( stderr, "fgets error.\n" );
            exit(1);
        }
        //printf("fgets returned %s\n", bf );
        
        printf("%s", buffer);
        
    }
    
        
    fclose(fp);    
        
    return 0;
}

