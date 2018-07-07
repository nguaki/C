///////////////////////////////////////////////////////////////////////////
// Jan 20 ,17
//
// Illustrates the importance of the number "%4s" in scanf command.
//
//OUTPUT 1
//
//What is your name(with '%4s')?ads
//Name:ads
//What is your name(without '%4s')?afdafdaffadfafa   <==== Causes seg fault.
//Name:afdafdaffadfafa
//*** stack smashing detected ***: ./a.out terminated
//Aborted
//
//OUTPUT 2
//What is your name(with '%4s')?tttttttttttt    <=== Does not cause seg fault but the consequence is not good.
//Name:tttt
//What is your name(without '%4s')?Name:tttttttt   <=== Doesn't even wait for an input.  The rest values get
//                                       automatically assigned.
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

int
main()
{

    char caName[5];
    char caName1[5];
    
    printf("What is your name(with '%%4s')?");
    scanf("%4s", caName);   //<== limits the input to max of 4.  This is prevernt buffer overflow which 
                            // causes seg fault.
    
    printf("Name:%s\n", caName);
    fflush(stdin);
    printf("What is your name(without %%4s)?");
    scanf("%s", caName1);  // <==This will cause segment fault if input exceeds 5 characters.
    
    printf("Name:%s\n", caName1);
   
    return 0;
}