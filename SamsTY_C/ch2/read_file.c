//Feb 11, 2017
//
//Description:
//Opens a file and reads a line at a time.
//Prints out the right justified line numbers and a tab and the line.
//
/*OUTPUT
dguai:~/workspace/SamsTY_C/ch2 $ ./a.out read_file.c 
   1    #include <stdio.h>
   2    #include <stdlib.h>
   3
   4    #define MAX 250
   5
   6    int
   7    main( int argc, char *argv[] )
   8    {
   9
  10        FILE *f1;
  11        char buffer[MAX];
  12        int  iLineNum = 1;
  13        
  14        if ( ( f1 = fopen( argv[1], "r" ) ) == NULL ){
  15            fprintf( stderr, "cannot open file.\n" );
  16            exit(2);
  17        }
  18        
  19        while( fgets( buffer, MAX, f1 ) != NULL ){
  20            printf( "%4d\t%s", iLineNum++, buffer );
  21        }
  22        
  23        fclose(f1);
  24    }
  
  Apr 25, 18      Added comments
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 250

int
main( int argc, char *argv[] )
{

    FILE *f1;
    char buffer[MAX];
    int  iLineNum = 1;
    
    if ( ( f1 = fopen( argv[1], "r" ) ) == NULL ){   //argv[1] is the 1st arguement.
        fprintf( stderr, "cannot open file.\n" );
        exit(2);
    }
    
    while( fgets( buffer, MAX, f1 ) != NULL ){
        printf( "%4d\t%s", iLineNum++, buffer );
    }
    
    fclose(f1);
}