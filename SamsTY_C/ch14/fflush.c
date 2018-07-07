// Feb 14, 17
//
// Demonstration of flushing out stdin buffer in case
// unnecessary inputs have been entered.
//
/*
Enter your age:
45 fgfgf        <==fgfgf is a garbage and should be ignored.
Enter you name:
sgsgfdsgfsd
your name is sgsgfdsgfsd and your age is 45.  <==fgfgf was infact ignored.
*/
#include <stdio.h>

int
main(void)
{
    int age;
    char name[20], junk[20];
    
    puts( "Enter your age:" );
    scanf( "%d", &age );
    
    //fflush(stdin);  <=== This didn't flush out the keyboard buffer.
    //gets(junk);       //<=== This cleared out keyboard buffer.
    fgets(junk, 20, stdin);
    
    puts( "Enter you name:" );
    scanf( "%s", name );
    
    printf("your name is %s and your age is %d.\n", name, age );
    
    return 0;
}