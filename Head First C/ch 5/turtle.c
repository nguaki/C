//Jan 25, 2017
//
//Passing structure by reference.
//
/*
From main(). memory address of name is 0x7ffc75c08450.
You are now 100 years old.
From procedure(). memory address of name is 0x7ffc75c08450.
You are Eric.
*/
#include <stdio.h>


typedef struct
{
    const char *name;
    const char *species;
    int   age;
}turtle;

//Increments age by 1.
void
happy_birthday( turtle *t )
{
    //t->age = t->age + 1;    //This  syntax works also.
    (*t).age = (*t).age + 1; 
}

//Modifies name.
void
modify_name( turtle *t )
{
    //t->age = t->age + 1;    //This  syntax works also.
    //(*t).name[4] = 'x';     //Modifying the value causes compiling error message.
                              //turtle.c:26:5: error: assignment of read-only location ‘*(t->name + 4u)’
                              //(*t).name[4] = 'x'; 
                              //^

    t->name = "Eric";         //Assigning to new name is legit. 
    printf( "From procedure(). memory address of name is %p.\n", &t->name );
}

int
main()
{
    turtle t = { "Jin Hwan", "Quiet turtle", 99 };
    
    printf( "From main(). memory address of name is %p.\n", &t.name );
    happy_birthday( &t );
    
    
    printf( "You are now %i years old.\n", t.age );   
    
    modify_name( &t );
    
    printf( "You are %s.\n", t.name );
    
    return 0;
}