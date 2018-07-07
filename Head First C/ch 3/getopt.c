//Jan 24, 17
//
//Illustrates getopt() command.
//
//

/*
scene 1: -d option with an arguement.

dguai:~/workspace/Head First C/ch 3 $ ./a.out -d now
deliver now.


scene 2: -d option without an arguement

dguai:~/workspace/Head First C/ch 3 $ ./a.out -d 
./a.out: option requires an argument -- 'd'
Wrong argument.


scene 3: invalid arguement -z

dguai: ~/workspace/Head First C/ch 3 $ ./a.out -z
./a.out: invalid option -- 'z'
Wrong argument.


scene 4: valid arguement with ingredients.

dguai:~/workspace/Head First C/ch 3 $ ./a.out -dtmrw -t mushroom pineapple
Make it thick.
deliver tmrw.
Ingredients are ... 
mushroom
pineapple
*/
#include <stdio.h>
#include <unistd.h>

int 
main( int argc, char *argv[] )
{
    const char *delivery = "";   //Note that const or no const make a difference.
                                 //  Must be initialized with empty string in case 
                                 //  there is no -d arguement.
                                 //If there is no empty string assignment, this will result in
                                 //segmentation error when checking for delivery[0].
    char ch;
    int  count;
     
    //delivery[0] = 'f';   //This is illegal since delivery is a const.
    
    //printf("I. address of delivery is %p\n", &delivery[0]);
    
    while( ( ch = getopt( argc, argv, "d:t" )) != EOF ){  //: following d implies that there must be arguement.
                                                          //t  implies that this is another valid arguement.
        switch(ch)
        {
            case 'd':
                delivery = optarg;
                //printf("II. address of delivery is %p\n", &delivery[0]);
                break;
            case 't':
                printf( "Make it thick.\n" );
                break;
            default:
                printf( "Wrong argument.\n" );
                break;
        }
    }
    
    //decrement num of arguements by number of optind. 
    argc = argc - optind;  
    //argv is an array of char pointers.
    //Advance the pointer by the number of optind.
    argv = argv + optind;  
    
    if (delivery[0]){
        printf( "deliver %s.\n", delivery );
    }
    
    if (argc > 0 )
    {
        printf("Ingredients are ... \n");
        for( count = 0; count < argc; count ++ )
            printf( "%s\n", argv[count] );
    }
    
    return 0;
}   