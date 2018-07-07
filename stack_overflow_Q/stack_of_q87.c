#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

int main( void )
{
    char c = ' ';
    char lastKey;

    initscr();
    cbreak();
    noecho();

    for(;;)
    {
        //timeout(500);

        while( (c = getch()) != EOF )
        {
            printf("%c", c);
            lastKey = c;
        }

        //sleep(1);

        //if( EOF == c )
        //{
            printw("%c", lastKey);
        //}
    }

    return 0;
}