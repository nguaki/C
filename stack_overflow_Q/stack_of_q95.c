#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    char input[4], garbage[50];
    do 
    {
        //important code
        printf ("You want to continue??");
        //fflush(stdin);
        //fgets(input, sizeof(input), stdin);
        scanf("%s", input);
        fgets(garbage, sizeof(garbage), stdin);
        printf("input=[%s]\n", input);
        printf("garbage = [%s]\n", garbage);
    } while (strcmp(input,"yes") == 0 || strcmp(input,"Yes") == 0 );

    return 0;
}