// Feb 17, 17
//
// Lower to upper case.
// Demonstration of ASCII value comparison for characters.
//
/*
enter filename:temp.txt
ABCDEFGHIJKLMNOPQRSTUVWXYZABCDE

cat temp.txt
abcdefghijklmnopqrstuvwxyzABCDE
*/
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    char fileName[40];
    FILE *fp;
    
    printf( "enter filename:");
    scanf("%s", fileName );
    
    if ((fp = fopen(fileName,"r")) == NULL ){
        fprintf( stderr, "cannot open %s\n", fileName);
        exit(1);
    }
    
    while(1)
    {
        int c;
        
        c = fgetc(fp);
        
        if (!feof(fp)){
        
            if ( c >=97 && c <=122 )
                printf( "%c", c - 32 );
            else
                printf( "%c", c );
        }else{
            break;
        }
    }
    
    fclose(fp);
    return 0;
}