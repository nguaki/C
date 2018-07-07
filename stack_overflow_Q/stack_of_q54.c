#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
main(void)
{
    //char *ccp = "This is it";  //This causes seg fault
    char ca[100] = "This is it";
    char *delimeter = " \t";
    char  *cp;
    char *backwards[5];
    int i=0, j;
    
    cp = strtok(ca, delimeter);
    backwards[i] = malloc(strlen(cp)+1);
    strcpy(backwards[i], cp);
    i++;
    while( cp != NULL ){
        printf( "%s\n", cp );
        
        cp = strtok( NULL, delimeter );
        if(cp!=NULL){
            backwards[i] = malloc(strlen(cp)+1);
            strcpy(backwards[i], cp);
            i++;
        }
    }
    
    for(j = i-1; j>=0; j--)
         printf( "%s\n", backwards[j] );
       
    return 0;
}