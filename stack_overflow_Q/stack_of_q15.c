#include <stdio.h>
#include <string.h>

int
main(void)
{
    char ch;
    
    printf("Please enter an option [1,2,3,4,5 (return to exit):");
    while( ( ch = getchar() ) !='\n' )
    {
        
        switch(ch)
        {
            case '1':
                printf("hello 1\n");
                break;
            case '2':
                printf("hello 2\n");
                break;
            case '3':
                printf("hello 3\n");
                break;
            case '4':
                printf("hello 4\n");
                break;
            case '5':
                printf("hello 5\n");
                break;
            default:
                printf("unknown option. Press a key to continue. (return to exit)\n");
                break;
        }
        printf("Please enter an option [1,2,3,4,5 (return to exit):");

        ch = getchar();
    }
    
    return 0;
}