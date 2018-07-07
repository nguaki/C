/*
   Feb 14. 2017

   Weird scanf() string specifier.

   scanf( "%30[^*]", buffer );  //Note that there is no %s specifier.

   Enter a string with * character 
   dfafdafdsfwerewr****asfsfsdfds
   Picked up:
   dfafdafdsfwerewr

   Enter a string with * character 
   rwtrwte***sfdsfs
   Picked up:
   rwtrwte

   Enter a string with * character 
   ******
   Picked up:
 
   Enter a string with * character 
   w*dfsfsd*
   Picked up:
   w
   
   Apr 26, 18      Enter a line to flush out STDIN buffer. fgets( ..,garbage,..);
*/

#include <stdio.h>

int
main(void)
{

    char buffer[31];
    char garbage[30];
    
    puts("Enter a string with * character ");
    scanf("%30[^*]", buffer );  //Note that there is no %s specifier.
                                //Pick up characters not *.?
    
    puts("Picked up:");
    puts(buffer);
    fgets(garbage, 30, stdin);
    
    return 0;
}