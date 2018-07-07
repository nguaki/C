#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfunctions.h"
#define B 26

int main() {

FILE *input=fopen("input.txt", "r");
FILE *output=fopen("output.txt", "w");

char cmd[100];
char s[100];
int i;

NodeT **Bucket=(NodeT**)malloc(B*sizeof(NodeT*));
//NodeT *Bucket=(NodeT*)malloc(B*sizeof(NodeT));
for( i=0; i<26; i++) {
    Bucket[i]=NULL;
}

int hashcode;
char c;

//iBob
//i -> insert
//Bod -> name
while(fscanf(input, "%s", cmd)!=-1){
    c=cmd[0];

    strcpy(s, cmd+1);

    switch (c) {
        case 'i':
        {
            hashcode=hashfunction(s);
            insert(Bucket, s);
        }
            break;

        case 'd':{
            deleteNode(Bucket, s);
        }
            break;

        case 'f':{
            if(findNode(Bucket, s)!=NULL) printf("%s was found", s);
        }
            break;
        case 'l':{
            printNodes(Bucket);
        }
            break;
        default:
            break;
    }
}



return 0;
}