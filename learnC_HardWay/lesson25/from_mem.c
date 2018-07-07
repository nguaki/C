#include "../dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define SIZE 100

int
read_string( int size, char **name )
{
    char *s = NULL;
    
    //Memory location of **name is *name.
    //Allocate memory at this location.
    *name = calloc(1, size+1);
    check_mem( name );
    s = fgets( *name, size, stdin);
    check( s != NULL, "error reading a string.");
    return 0;
error:
    if(*name) free(*name);
    *name = NULL;
    return -1;
}

int
read_int( int *age )
{
    char *s = NULL;
    char *end = NULL;
    int  rc = 0;
    
    rc = read_string(SIZE, &s );
    
    check( rc==0, "Error reading a string");
    
    *age = strtol( s, &end, 10);
    check( (end[0]=='\0' || end[0] =='\n') && s[0] != '\0', "Invalid integer");

    return 0;
error:
    return -1;
    
}

int
read_scan( const char *fmt, ... )
{
    int i = 0, rc = 0;
    int size = 0;
    char **name = NULL;
    char *mi = NULL;
    int  *age = NULL;
    char garbage[100] = { 'a' };
    
    va_list argp;
    va_start( argp, fmt );
    
    
    for( i=0; fmt[i] != '\0'; i++)
    {
        if( fmt[i] == '%' )
        {
            i++;
        
            switch( fmt[i] )
            {
                case 'd':
                    age = va_arg(argp, int *);
                    rc = read_int( age );
                    check(rc==0, "Error reading age\n");
                    break;
                case 'c':
                    mi = va_arg(argp, char *);
                    *mi = fgetc(stdin);
                    //fgets( garbage, 100, stdin);
                    //fflush(stdin);
                    break;
                case 's':
                    size = va_arg(argp, int );
                    name = va_arg(argp, char **);
                    rc = read_string( size ,name );
                    check(rc==0, "Error reading a name\n");
                    break;
                default:
                    printf("character = %c\n", fmt[i]);
                    sentinel("Wrong format specifier.");
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
    char mi = ' ';
    char garbage[100] = { 'a' };
    int  age = 0;
    
    int  rc = 0;
    
    printf("Enter first name:");
    rc = read_scan( "%s", SIZE, &first_name );
    check(rc==0, "Invalid first name.\n");
    
    printf("Enter middle initial:");
    rc = read_scan( "%c", &mi );
    fgets( garbage, 100, stdin);
    check(rc==0, "Invalid middle initial.\n");
    fflush(stdin);
    printf("Enter last name:");
    rc = read_scan( "%s", SIZE, &last_name );
    check(rc==0, "Invalid last name.\n");
     
    printf("Enter age:");
    rc = read_scan( "%d", &age);
    check(rc==0, "Invalid age.\n");

    printf("first name: %s", first_name);
    printf("Middl Init: %c\n", mi);
    printf("last name: %s", last_name);
    printf("age: %d", age);
    
    return 0;
error:
    return -1;
}