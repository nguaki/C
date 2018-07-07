#include <stdio.h>
#include <stdlib.h>

struct student{
    char *name; 
    int age;
};


void print_student(struct student* st){
    printf("Student: %s is %d years old\n", st->name, st->age);
}


int main(void) {    
    srand(time(NULL));
    struct student *molly_ptr = malloc(sizeof(struct student));

    struct student billy = {
                            .name = "billy",
                            .age = rand()%30
                           };

    *molly_ptr = (struct student){
                    .name = "molly",
                    .age = 25
                 };

    //molly_ptr->name = "molly";
    //molly_ptr->age = 25;

    print_student(&billy);
    print_student(molly_ptr);


    return 0;
}