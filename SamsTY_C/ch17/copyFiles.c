//Feb 17, 17
//
//Demonstration of feof().
//
/*
Enter old file name:temp.txt
Enter new file name:abcd
dguai:~/workspace/SamsTY_C/ch17 $ cat temp.txt
abcdefghijklmnopqrstuvwxyz
dguai:~/workspace/SamsTY_C/ch17 $ cat abcd
abcdefghijklmnopqrstuvwxyz
*/

#include <stdio.h>
#include <stdlib.h>

void copyFile( char *, char *);

int
main(void)
{
    char newFileName[20], oldFileName[20];
    
    printf("Enter old file name:" );
    scanf("%s", oldFileName);
    printf("Enter new file name:" );
    scanf("%s", newFileName);
    
    copyFile(oldFileName,newFileName);
    
    return 0;
}

void
copyFile( char *oldFileName, char *newFileName)
{
    FILE *of, *nf;
    
    if ( (of = fopen(oldFileName,"rb")) == NULL ){  //<==Doesn't matter if binary or no binary.
        fprintf( stderr, "failed opening %s.\n", oldFileName);
        exit(1);
    }
    
    if ( (nf = fopen(newFileName,"wb")) == NULL ){
        fprintf( stderr, "failed opening %s.\n", oldFileName);
        exit(1);
    }
    while( 1 ){
        int c;
        
        c = fgetc(of);
        
        if( !feof(of) )  //<==== Very important check. Otherwise last character of the file would look funny.
            fputc( c, nf );
        
        else
            break;  //Avoid writing EOF character.  It is a funny looking char.
        
        //fputc returns a value that is written.
        
        //printf("fputc return value = %c\n", j);
        //c = fgetc(of);
        
        //fputc( c, nf);
    }

    
    fclose(of);
    fclose(nf);
}
