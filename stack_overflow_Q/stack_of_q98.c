//gcc -o entry_test -Wl,-eother entry_test.c
#include<stdio.h>       

int other(void){//can't use argc, argv
    printf("Bye-Bye world!\n");
    return 0;
}

int main(int argc, char *argv[]){
    printf("%s\n","Hello world!");
    return 0;
}