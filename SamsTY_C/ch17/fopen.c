// Feb 17, 17
// 
// Demonstration of fopen().
//
//
/*
dguai:~/workspace/SamsTY_C/ch17 $ ./a.out
Enter filename:trtret
Enter file mode:a
Successful opening trtret with mode a
press x to quitq
Enter filename:fsafsadf
Enter file mode:w
Successful opening fsafsadf with mode w
press x to quitx
*/
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{

    char fileName[20], mode[4], garbage[80],c;
    FILE *fp;
    
    do{
        printf("Enter filename:");
        scanf("%s", fileName );
        printf("Enter file mode:");
        scanf("%s", mode );
        
        if( ( fp = fopen( fileName, mode ) ) != NULL ){
            printf("Successful opening %s with mode %s\n", fileName, mode );
        }else{
            printf("UnSuccessful opening %s with mode %s\n", fileName, mode );
        }
        
        gets(garbage);
        printf( "press x to quit" );
        c = getc(stdin);

    }while( c != 'x' );
    
    return 0;
}