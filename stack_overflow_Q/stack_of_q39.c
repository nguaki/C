#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n=1,i,cont;
    char string[50];

    printf("Enter n:");
    scanf("%d\n",&n);   // <=== \n character is very critical.  It consumes this character.
    while(n!=0){
        //gets(string);
        fgets(string,sizeof(string) ,stdin);
        cont=0;
        for(i=0;i<strlen(string);i++){
            if(string[i]=='.'){
                cont++;
            }
        }
        if(cont%2==0){
            printf("S\n");
        }else{
            printf("N\n");
        }
        printf("Enter n:");
        scanf("%d\n",&n);
    }
    return 0;
}