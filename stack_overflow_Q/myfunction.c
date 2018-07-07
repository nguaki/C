#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 26
#include "myfunctions.h"

int hashfunction(char *name){
int sum; unsigned long len;
sum = 0;
len = strlen(name);
int i;

for ( i=0; i<len; i++) {
    sum+=name[i];
}
return (sum%26);
}

void fillNode(NodeT *p, char *value){
//p->name=value;
    p->name = strdup(value);
    //p->name = (char *)malloc(sizeof(value)*sizeof(char)+1);
    // strncpy(p->name, value, sizeof(value)+1);
}

void insert(NodeT **Bucket, char *name){
//void insert(NodeT *Bucket, char *name){

NodeT *p=(NodeT*)malloc(sizeof(NodeT));

if(p){
    fillNode(p, name);
    int h=hashfunction(p->name);

    if(Bucket[h]==NULL){
        Bucket[h]=p;
        p->next=NULL;
    }
    else {
        //inserts at the top
        p->next=Bucket[h];
        Bucket[h]=p;
    }
}
}

NodeT *findNode(NodeT **buckets, char *str){
int ok=0;
int i=0;
NodeT *aux=(NodeT*)malloc(sizeof(NodeT));

for(i=0;i<B && ok == 0;i++){
    NodeT *p=buckets[i];
    while(p){
        if(strcmp(p->name, str)==0)
        {
            ok=1;
            aux=p;
            break;
        }
        p=p->next;
    }
}
if(aux!=NULL) return aux;
else return NULL;
}

void deleteNode(NodeT **buckets, char *str){

NodeT **link=&buckets[hashfunction(str)];

while(*link){
    NodeT *aux=*link;
    if(strcmp(aux->name, str)==0){
        *link=aux->next;
        free(aux);
        break;
    }
    else link=&(*link)->next;
}
}

void printNodes(NodeT **buckets){

int i=0;
for(i=0;i<B;i++){
    NodeT *p=buckets[i];
    while(p){
        printf("%s\n", p->name);
        p=p->next;
    }

}
}