#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int val;
  struct lista *next;
} lista;
  
//lista *head=NULL;


void print(lista *head){
  printf("List:");
  while(head != NULL){
    printf("%d; ", head->val);
    head = head->next;}
}
/**
void insert(lista  **p,int v){    
  lista *novo;
  if(p == NULL){
    novo = malloc(sizeof(lista));
    novo->val = v;
    novo->next = NULL;
    *p = novo;
  }
  else{
    novo =malloc(sizeof(lista));
    novo->val = v;
    novo->next = NULL;
    (**p)->next = novo;
  }
}
**/
void insert(lista  **p,int v){
  lista *novo;
  if(*p == NULL){
    novo = malloc(sizeof(lista));
    novo->val = v;
    novo->next = NULL;
    *p = novo;}
  else{
    lista *head = *p;
    while(head->next != NULL){
        head = head->next;
    }
    novo =malloc(sizeof(lista));
    novo->val = v;
    novo->next = NULL;
    head->next = novo;
  }
}


int main()
{
  lista *head=NULL;
  char garbage[50];
  int v = 1;
  printf("Write the values u want to put in your list.(write 0 to exit)\n");
  while (v != 0){
    scanf("%d",&v);
    fgets( garbage, sizeof garbage, stdin );
    insert(&head,v);
  }
  print(head);
}
