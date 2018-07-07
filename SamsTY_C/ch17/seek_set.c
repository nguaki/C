//Feb 18, 17
//
//Demonstration of SEEK_SET.
//
/*
Enter a nth int: 80
Enter a nth int: 7
Read 70
Enter a nth int: 90
Enter a nth int: 56
Enter a nth int: 5
Read 50
Enter a nth int: -1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int
main(void)
{
    int ia[MAX];
    int i, data, readamt;
    FILE *fp;
    long lseek;
    int fseek_val;
    
    for( i=0; i<MAX; i++ )
        ia[i] = 10 * i;
        
    if ( (fp=fopen( "temp1.txt", "wb" ) ) == NULL ){
        printf("Cannot open to write.\n");
        exit(1);
    }
    
    if ( fwrite(ia, sizeof(int), MAX, fp ) != MAX ){
        printf( "Failed writing.\n");
        exit(1);
    }
    
    fclose(fp);
    if ( (fp=fopen( "temp1.txt", "rb" ) ) == NULL ){
        printf("Cannot open to write.\n");
        exit(1);
    }
       
    printf( "Enter a nth int: ");
    scanf( "%ld", &lseek);
     
    do{
        
        while( lseek >= MAX ){
            printf( "Enter a nth int: ");
            scanf( "%ld", &lseek);
        }
    

        if( ( fseek_val = fseek( fp, lseek*sizeof(int), SEEK_SET ) ) != 0 ){
            printf( "faile fseek\n");
            exit(1);
        };
       if (( readamt =fread( &data, sizeof(int), 1, fp )) != 1 ){
            printf( "Failed reading an integer.\n" );
            exit(1);
        };
        printf( "Read %d\n", data );
        printf( "Enter a nth int: ");
        scanf( "%ld", &lseek);
    }while( lseek > 0 );
    
    fclose(fp);

    return 0;
}