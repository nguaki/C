/*
Enter first name:james
Enter middle initial:m
Enter last name:che
Enter age:51
first name: james
middle initial: m
last name: che
age: 51
*/

#include "../dbg.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define MAX_BUFFER 100

int
read_string( int length, char **name )
{
    char *result;
    
    //Note: **name represents the dereferening of data.
    //       *name represents the memory location of data.
    //        name represents the memory location to the pointer to data.
    //
    //   **name =============================>
    //    *name ============>
    //     name
    //   -----           ------             -------
    //   | N | ======>   | CP |    =====>   | data|
    //   -----           ------             -------
    //    N  = name
    //    CP = character pointer
    //    data = character string
    
    //Allocate memory of length bytes at memory location of *name.
    *name = calloc( 1, length );
    
    //Check if memory allocation succeeded.
    check_mem(*name);
    
    //Get string std input and store the string starting at memory location of
    //*name.
    result = fgets(*name,length, stdin);
    
    //Check if something was entered.
    //check result != null is true.  If not (same as result == null), error out.
    check(result != NULL, "Getting name failed");
    
    return 0;
error: if( *name ) free (*name);
        name = NULL;
        return -1;
}

int
read_int( int *age )
{
    char *input = NULL;
    char *end   = NULL;
    int    rc   = 0;

    //Note:  char *input;
    //       input is a pointer to character.
    //       
    //        *input   represents dereferencing.
    //         input   represents memory address.
    //        &input   represents address of the pointer to char.
    //
    rc = read_string( MAX_BUFFER, &input );
    check( rc == 0, "Failed reading a number");
    
    //Note:
    //strtol( "3456 abc", &end, 10 );
    //  end = "abc"
    // Store 3456. 
    *age = strtol( input, &end, 10 );
    
    //Check if end is empty and input is not empty.
    //This checks if a valid number has entered.
    check( (*end == '\0' || *end == '\n') && *input != '\0', "Invalid integer");
    
    
    return 0;
error:
    if(input) free(input);
    input = NULL;
    return -1;
}
int 
read_scan( const char *fmt, ... )
{
    char **name = NULL;
    char *mi = NULL;
    int i = 0;
    int buffer_len = 0;
    int rc = 0;
    int *age= NULL;
    
    va_list argp;
    va_start( argp, fmt );
    
    for( i=0; fmt[i] != '\0'; i++)
    {
        if( fmt[i] == '%')
        {
            
            i++;
        
            switch(fmt[i]){
                case 'd':
                    age = va_arg( argp, int *);
                    rc = read_int( age );
                    check( rc == 0, "Failed reading age.");
                    break;
                case 'c':
                    mi = va_arg( argp, char* );
                    *mi = fgetc(stdin);
                    check( mi != NULL, "Failed reading a character.");
                    break;
                case 's':
                    buffer_len = va_arg( argp, int );
                    name = va_arg( argp, char** );
                    rc = read_string( buffer_len,  name );
                    check( rc == 0, "Failed reading a name.");
                    break;
                
            }
        }
    }
    
    
    va_end( argp );
    return 0;
error:
    return -1;
}

int
main(void)
{

    char *first_name = NULL;
    char *last_name  = NULL;
    int age = 0;
    char mi = ' ';
    char garbage[100];

    printf( "Enter first name:" );
    read_scan( "%s", MAX_BUFFER, &first_name );
    
    //fgets( garbage, 100, stdin);
    printf( "Enter middle initial:" );
    read_scan( "%c", &mi );
    fgets( garbage, 100, stdin);
    
    printf( "Enter last name:" );
    read_scan( "%s", MAX_BUFFER, &last_name );

    printf( "Enter age:" );
    read_scan( "%d", &age );
    
    printf("first name: %s", first_name);
    printf("middle initial: %c\n", mi);
    printf("last name: %s", last_name);
    printf("age: %d", age);
    return 0;
}