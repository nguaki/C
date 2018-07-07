#include <stdio.h>
#include <string.h>

int
main(void)
{
    char str[10];
    
    strcpy( str, "ABCEDFGG" );
    //str[4] = (int)NULL; // warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
    //str[4] = NULL;   // warning: assignment makes integer from pointer without a cast [enabled by default]
    
    str[4] = 0;
    str[4] = '\0';
    str[4] = (int *)NULL;
    
    printf("%s\n", str);
    if(NULL == 0) printf( "ajfkdajfla");
    return 0;
}