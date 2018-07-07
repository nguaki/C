#include <stdio.h>


void *loop(char *filename){

    int counter = 10;
    int level = 0;
    char *filenames[10];
    filenames[0] = filename;

    while (counter-- > 0) {

        level++;
        if (level > 10) {
            break;
        }

        printf("Level %d - MAX_LEVELS %d\n", level, 10);
        filenames[level] = filename;

    }

    return NULL;
}

int main(int argc, char *argv[]) {
    loop(argv[0]);
}