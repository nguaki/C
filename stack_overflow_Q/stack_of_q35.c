#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ticket {
    char Name[30];
    long int PhoneNum;
    char Description [500];
    char Time[20];
};

struct Node {
    struct ticket data;
    struct Node *next;
}*front = NULL, *rear = NULL;



void insert( char *, long, char *, char * );
void delete1();
void display();



void main() {
    int choice, value;
    char Phone[30],  Name[30], garbage[40];
    long int PhoneNum;
    char Description[500];
    char Time[20];

    //clrscr();
    printf("\n:: Queue Implementation using Linked List ::\n");

    while(1) {
        printf("\n****** MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        fgets( garbage, sizeof(garbage), stdin);  //Remove newline character.
        switch (choice) {

        case 1:
            printf("Enter name: ");
            fgets(  Name, sizeof(Name),stdin );
            Name[strcspn(Name, "\n")] = 0;  //Remove newline character.
            
            printf("Enter phone:");
            fgets( Phone, sizeof(Phone), stdin);
            PhoneNum  = atol(Phone);
            
            printf("Enter description:");
            fgets( Description, sizeof(Description), stdin);
            Description[strcspn(Description, "\n")] = 0;  //Remove newline character.
            
            printf("Enter time:");
            fgets( Time, sizeof(Time), stdin);
            Time[strcspn(Time, "\n")] = 0;  //Remove newline character.
            
            insert( Name, PhoneNum, Description, Time );
            break;

        case 2:
            delete1();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}


void insert( char *Name, long PhoneNum, char *Description, char *Time ) { //puts value on end of queue
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy( newNode->data.Name, Name );
    newNode->data.PhoneNum = PhoneNum;
    strcpy( newNode->data.Description, Description );
    strcpy( newNode->data.Time, Time );
    newNode->next = NULL;

    if(front == NULL) front = rear = newNode;
    else {
        rear -> next = newNode;
        rear = newNode;
    }
    printf("\nInsertion is Success!!!\n");
}


void delete1() { //takes value from start of queue
    if (front == NULL) printf("\nQueue is Empty!!!\n");
    else {
        struct Node *temp = front;
        front = front->next;
        printf("\nDeleted element: %s\n", temp->data.Name);
        free(temp);
    }
}


void display() { //displays the queue
    if (front == NULL) printf("\nQueue is Empty!!!\n");
    else {
        struct Node *temp = front;
        while(temp->next != NULL) {
            printf("%s:",temp->data.Name);
            printf("%ld:",temp->data.PhoneNum);
            printf("%s:",temp->data.Description);
            printf("%s---->",temp->data.Time);
            temp = temp->next;
        }
            printf("%s:",temp->data.Name);
            printf("%ld:",temp->data.PhoneNum);
            printf("%s:",temp->data.Description);
            printf("%s---->NULL",temp->data.Time);
    }
}