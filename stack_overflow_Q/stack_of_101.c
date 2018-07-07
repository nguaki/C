#include <stdio.h>
#define sizeY 10
#define sizeX 10
#define LIVE 1
#define DEAD 0

typedef struct {
    int y;
    int x;
} TableType;

void printTable(TableType grid) {
    int height, width;

    for (height = 0; height < sizeY; height++) {
        for (width = 0; width < sizeX; width++) {
            if (grid{height, width} == LIVE) {
                printf("X");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void clearTable(TableType grid) {
    int height, width;
    for (height = 0; height < sizeY; height++) {
        for (width = 0; width < sizeX; width++) {
            grid{height, width} = DEAD;
        }
    }
}

int main(void) {
    TableType table;

    clearTable(table);
    printTable(table);

    return 0;
}