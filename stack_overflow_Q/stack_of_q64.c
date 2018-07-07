#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(void)
{
    //fpos_t.__pos =
    fpos_t current;
    fpos_t end;
    FILE *fp;
    
    if( ( fp = fopen( "abc.txt", "r" ) ) == NULL )
    {
        printf( "Cannot open.\n" );
        return 0;
    }
    
    /* error checks omitted for brevity */
    fgetpos(fp, &current);
    fseek(fp, 0, SEEK_END);
    fgetpos(fp, &end);
    fsetpos(fp, &current);

    printf("Last position is: %llu\n", (long long unsigned) end.__pos);

    fclose(fp);
}