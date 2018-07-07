#include <stdio.h>
#include <string.h>


int
main(void)
{
       char cmd[255];
       char argv[3][20];
       char *token;
       char *tstr = " ";
        
       fgets( cmd, sizeof cmd, stdin );
    
       token = strtok( cmd, tstr );
       int i = 0;
    
       while( token != NULL )
       {
            strcpy( argv[i], token);
            printf( "%s\n", argv[i] );
            token = strtok( NULL, tstr ); 
            i++;
       }

       return 0;
       
}