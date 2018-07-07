#include <stdio.h>

    float fToC(float far);

    int main()
    {
        int c;
        char caGarbage[50];
        float far;
        /*
        while((c = getchar()) != EOF)
        {
            fgets( caGarbage, sizeof caGarbage, stdin);
            printf( "char c = %c\n", c);
        scanf("%f", &far);
        printf( "far = %f\n", far);
        printf("%.2f\n", fToC(far));
        }
        */
        while((scanf("%f", &far) == 1))
        {
        printf( "far = %f\n", far);
        printf("%.2f\n", fToC(far));
        }
       return 0;
     }

    float fToC(float far)
    {
        float C;
        C = (5.0 / 9.0) * (far - 32.0);
        return C;
    }