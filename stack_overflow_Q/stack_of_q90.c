#include <stdio.h>

int main()
{
    int width;
    int breadth;

    scanf("%d %d", &width, &breadth);

    if (width == 1 && breadth == 1)
        printf ("#\n");
    else
    {
        for(int i = 0; i<breadth; i++)
        {
            for(int j = 0; j<width;j++)
                if( j == 0 || j == width - 1 || i == 0 || i == breadth - 1 )
                    printf("#");
                else 
                    printf(".");
            printf("\n");
        }
    }
    return 0;
}