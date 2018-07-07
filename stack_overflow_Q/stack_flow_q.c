#include <stdio.h> 
char *stringncpy(char *s1, char *s2, int n);
int main()
{
    char sourceStr[40], targetStr[40], junk[30], *target, sLength[10];
    int length;


    //iRetCnt = scanf("%d", &length);
    //fgets( junk, 30, stdin);
    //fflush(stdin);
    printf("Enter the string: \n");
    //scanf("%s",sourceStr); //doesn't work for some reason
    fgets( sourceStr, 40, stdin);
    
    
     printf("Enter the number of characters: \n");
    fgets( sLength, 10, stdin );
    length = atoi(sLength);
   
    
    target = stringncpy(targetStr, sourceStr, length);
    printf("stringncpy(): %s\n", target);
    return 0;
}
char *stringncpy(char *s1, char *s2, int n)
{
    /* Copy source to target */
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (s2[i] == '\0')
        {
            break;
        }
        else
        {
            s1[i] = s2[i];
        }
    }
    //s1[i + 1] = '\0';
    for (j = i + 1; j <= n; j++)
    {
        s1[j] = '\0';
    }
    return s1;
}