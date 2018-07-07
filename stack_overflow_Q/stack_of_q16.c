#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
char name[100], firstDigits[13], cards[5000][16];

srand(1019336);
int i, j;
char c = '0';
for(i=0;i<13;i++){
    c = '0' + (rand() % 43);
    while(c > 57 && c < 65){
        c = '0' + (rand() % 43);
    }
    firstDigits[i] = c;

}
//printf("%s \n", firstDigits);
for(i=0;i<5;i++){
    for(j=0;j<13;j++){
        cards[i][j] = firstDigits[j];
    }
}
for(i=0;i<5;i++){

    for(j=13;j<16;j++){
        c = '0' + (rand() % 43);
        while(c > 57 && c < 65){
            c = '0' + (rand() % 43);
        }
        cards[i][j] = c;
    }
}

printf("Hello\n");
for(j=0;j<16;j++)
    printf("%c", cards[1][j]);

return 0;
}