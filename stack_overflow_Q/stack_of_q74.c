#include <stdio.h>
#include <string.h>


int
main(void)
{

    int iNumW, iIndex;
    int iWCnt = 0;
    //char cC;
    int iC;
    char caTemp[100];
    char caWords[100][100];
    char *cpDelimeter = " \n";
    char *cpToken;
    char *cp;
    short sIsWord = 1;
    char caGarbage[100];
    
    scanf("%d", &iNumW );
    fgets(caGarbage, sizeof caGarbage, stdin);  //Remove newline char
    
    //Get word inputs
    while( iWCnt < iNumW )
    {
        fgets(caTemp, sizeof caTemp, stdin );
        for( cpToken = strtok( caTemp, cpDelimeter );   cpToken != NULL;  cpToken = strtok( NULL, cpDelimeter)){
            
            cp = cpToken;
            while( *cp ){
                sIsWord = 1;
                
                //Check if alphabet
                if( !isalpha(*cp) ){
                    sIsWord = 0;
                    break;
                }
                cp++;
            }
            if( sIsWord ){
                strcpy( caWords[iWCnt], cpToken );
                //printf( "%s\n", caWords[iWCnt]);
                iWCnt++;
                if( iWCnt >= iNumW ) break;
            } else {
                printf("invalid entry.\n");
            }
            //printf("%d\n", iWCnt);
        } 
    }
    int i,j ;
    for (i = 0; i < iWCnt; i++) {//loop to sort alphabetically    
        for (j = i + 1; j < iWCnt; j++) {
            if ((strcasecmp(caWords[i], caWords[j]) > 0)) {  //swapping words         
                strcpy(caTemp, caWords[j]);
                strcpy(caWords[j], caWords[i]);
                strcpy(caWords[i], caTemp);
            }
        }
    }

    for (i = 0; i < iWCnt; i++) { //loop to skip duplicates   
        if ((strcasecmp(caWords[i], caWords[i + 1]) != 0)) { //if there is a duplicate , we willnot output it
            printf("%s ", caWords[i]);
        }
    }

    return 0;
}