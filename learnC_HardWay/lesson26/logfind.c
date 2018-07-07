// usage:  logfind -o God Paul   <== -o flag is for or logic.
//         logfind God Paul      <== default logic is and.
//
//
//
#define _GNU_SOURCE   //This is needed for strcasestr().  This  command is not ANSI-C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../dbg.h"

#define OR 1
#define MAX_SIZE 100

int
iCheckAllExists( int *found, int argc )
{
    int i = 0, allExists = 1;
            
    for( i=0; i<argc;i++ )
    {
        if(found[i] == 0 )
        {
            allExists = 0;
            break;
        }
    }
    
    return allExists;
}

void
vInitFound( int *found, int argc )
{
    int i;
    
    for( i=0; i<argc;i++ )
    {
        found[i] = 0;
    }
}

/*
This function readjusts argc as well argv.
case 1: logfind   (argc = 1)
*/
int
check_args( int *argc, char **argv[], int *OR_LOGIC )
{
    
    (*argc)--; //Decrement argc since program name doesn't count.
    (*argv)++; //This moves pointer up 1. Now points after program name.
    debug( "argc = %d\n", *argc );
    debug( "argv[0] = %s\n", *argv[0]);
    
    check( *argc >= 1, "Usage: logfind [-o] ");
    
    if( strcmp(*argv[0], "-o") == 0 ){
        (*argc)--;  //Decrement argc.
        (*argv)++;  //This moves pointer pass by "-o".
        *OR_LOGIC = 1;
        
        check( *argc > 1, "You need at least 1 word.  Usage example: logfind [-o] abc")
    }else{
        *OR_LOGIC = 0;
    }
    
    return 0;
error:
    return -1;
}


void
vCheckWordsExist( char *fileName, int option, int argc, char *argv[] )
{
    char *rcp = NULL;
    FILE *fp1 = NULL;
    char contents[100] = { 'a' };
    int found[10] = {0};
    int allExists = 0;

    fp1 = fopen( fileName, "r");
    
    check(fp1!=NULL, "Failed opening %s file.\n", fileName);
    
    vInitFound( found, argc );

    while(!feof(fp1)){
        int i;
        rcp = fgets(contents, 100, fp1);
        check( rcp != NULL, "Error reading a line from a file %s.\n", fileName);
        debug("scanning line = %s\n", contents);
                
        //the search string starts from 3rd arguement.
        //prog_name -o  str1 str2 str3
        for( i=0; i<argc;i++){
            if(strcasestr(contents, argv[i])){
                found[i] = 1;
                if( option == OR ) 
                    printf("%s is found in file %s line=%s\n", argv[i], fileName, contents);
            }
        }
    }
    
    if( option != OR ){
        allExists = iCheckAllExists( found, argc );
        if( allExists ) printf("All words are found in file %s\n", fileName);
    }

    fclose(fp1);

error:
    return;
}

int
main( int argc, char *argv[])
{
    FILE *fp = NULL;
    char fileName[20] = { 'a' };
    int  option = 0;  //default is AND
    char *rcp = NULL;

    check( check_args( &argc, &argv, &option ) == 0, "Invalid arguement.\n" );

    //open .logfind filename
    fp = fopen( ".logfind", "r");
    check(fp!=NULL, "Failed opening .logfind file.\n");
    
    //list all the file names from .logfind
    while(!feof(fp))
    {
        rcp = fgets( fileName, 20, fp);
        check( rcp != NULL, "Error reading a line from a file .logfind.\n");
        //If the last character is a newline character,
        //replace it with a NULL character.
        if( fileName[strnlen(fileName, MAX_SIZE)-1] == '\n' ) 
            fileName[strnlen(fileName, MAX_SIZE)-1] = '\0'; 
        
        vCheckWordsExist( fileName, option, argc, argv );

    }
    fclose(fp);
    
    return 0;
error:
    return -1;
}