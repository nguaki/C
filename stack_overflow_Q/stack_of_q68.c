#include <stdio.h>
#include <string.h>
int
main(void)
{
    FILE *fp;
    char caBuffer[50];
    char caV1[50], caV2[50], caCnt[2];
    const char *cp;
    const char *cpDelimeter = "\n";
    int iLoopCnt = 0;
    
    if( ( fp = fopen( "xyz.txt", "r" ) ) == NULL ){
        printf( "failed opening\n" );
        return 1;
    }
    
    while( fgets( caBuffer, sizeof(caBuffer), fp ) != NULL ){
        if( strlen(caBuffer) > 1 ){  //skip the lines with newline char
          cp = strtok(caBuffer, cpDelimeter);
          if(cp != NULL){
              
            switch( iLoopCnt++ )
            {
                  case 0:
                    strcpy(caCnt, cp );
                    break;
                  case 1:
                    strcpy(caV1, cp );
                    break;
                  case 2:
                    strcpy(caV2, cp );
                  break;
            }
          }
        }
    }
    
    printf("caCnt = %s\n", caCnt );
    printf("caV1  = %s\n", caV1 );
    printf("caV2  = %s\n", caV2 );
    
    return 0;
    
}