#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    unsigned char c, asciiMessage[100];
    int i = 0;
    
    printf("Please enter file path for the input file\n");
            FILE *file;
            char fileName[100];
            scanf("%s",fileName);
            file = fopen(fileName, "rb");
            if(file == NULL){
                printf("File not found program will now end \n");
                exit(1);
            }
            while ((c = fgetc(file)) != EOF && i <= 10){
                //putchar(c);
                asciiMessage[i] = c;
                printf( "%u\n", c);
                //cypher[i] = c;
                i++;
            }
            fclose(file);
            
            for( i = 129; i < 255; i++ )
                printf( "%c\n", i );
    return 0;
}