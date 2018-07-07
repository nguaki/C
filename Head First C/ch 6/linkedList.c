//Jan 25, 17
//
//Demonstration of linked list.
//
//
//Uses valgrind for any memory leaks.
//
/***
dguai:~/workspace/Head First C/ch 6 $ valgrind --leak-check=full ./a.out
==1972== Memcheck, a memory error detector
==1972== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==1972== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==1972== Command: ./a.out
==1972== 
Enter a city name: afdafa
Enter a city name: werwr
Enter a city name: afdaf
Enter a city name: werwer
Enter a city name: You have arrived afdafa
.You have arrived werwr
.You have arrived afdaf
.You have arrived werwer
.Freeing afdafa

==1972== Invalid read of size 8
==1972==    at 0x4007D1: freeMemory (in /home/ubuntu/workspace/Head First C/ch 6/a.out)
==1972==    by 0x40089F: main (in /home/ubuntu/workspace/Head First C/ch 6/a.out)
==1972==  Address 0x51fc048 is 8 bytes inside a block of size 16 free'd
==1972==    at 0x4C2BDEC: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==1972==    by 0x4007CC: freeMemory (in /home/ubuntu/workspace/Head First C/ch 6/a.out)
==1972==    by 0x40089F: main (in /home/ubuntu/workspace/Head First C/ch 6/a.out)
==1972== 
Freeing werwr

Freeing afdaf

Freeing werwer

==1972== 
==1972== HEAP SUMMARY:
==1972==     in use at exit: 0 bytes in 0 blocks
==1972==   total heap usage: 8 allocs, 8 frees, 94 bytes allocated
==1972== 
==1972== All heap blocks were freed -- no leaks are possible
==1972== 
==1972== For counts of detected and suppressed errors, rerun with: -v
==1972== ERROR SUMMARY: 4 errors from 1 contexts (suppressed: 0 from 0)
****/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct city{
    char *city_name;
    struct city  *next;
}CITY;


CITY *
getNewCity( char *name )
{

    CITY *city;
    
    city = malloc(sizeof(CITY));
    
    city->city_name = strdup(name);
    city->next = NULL;
    
    return city;
}

void
displayCities( CITY *start )
{

    CITY *current = start;
    
    while( current != NULL)
    {
        printf( "You have arrived %s.", current->city_name );
        current = current->next;
    }
}

void 
freeMemory( CITY *start )
{
    CITY *current = start;
    
    while( current != NULL )
    {
        printf("Freeing %s\n", current->city_name);
        free(current->city_name);
        free(current);
        current = current->next;
    }

}

int
main()
{

    char cityName[80];
    CITY *start = NULL, *linker = NULL, *newCity = NULL;
    
    
    printf( "Enter a city name: " );
    while(fgets( cityName, 80, stdin ) != NULL)
    {
        newCity = getNewCity( cityName );
        
        if (start == NULL )
            start = newCity;
            
        if (linker != NULL)
            linker->next = newCity;
            
        linker = newCity;
        printf( "Enter a city name: " );
    
    }

    displayCities(start);
    freeMemory(start);
    return 0;
}   