#include<stdio.h>
#include<string.h>

int 
main (void)
{
    char first_line[1000];
    char cC;
    char caGarbage[50];
    int i,n,j,k;
    int count=0,flag=0;

    printf("Enter count:");
    scanf("%d",&k);
    fgets( caGarbage, sizeof caGarbage, stdin);//Consumes newline character.

    for(int m=0; m<k; m++)
    {
        printf("Insert first line:");
        fgets(first_line, 1000, stdin);

        printf("Insert a character:");
        cC = fgetc( stdin );
    
        fgets( caGarbage, sizeof caGarbage, stdin); //Consumes newline character
    
        for(i=0; i<strlen(first_line); i++)
        {
           if(cC == first_line[i])
           {
               flag=1;
               count++;
           }
        }
    
        first_line[strcspn( first_line, "\n" )] = '\0';

        if(flag==1)
            printf("Occurrence of '%c' in %s = %d",cC,first_line,count);
        else
            printf("%c isn't present",cC);

        printf("\n");

        count=0;
        flag=0;
    }

    return 0;
}