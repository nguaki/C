#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FILE_NAME "gcd.txt"

time_t val; long *p, *q;

FILE *fp; char input;


int recursive(long a, long b) {

p = &a;
q = &b;

if (a%b == 0)
    return b;
else return recursive(b, a%b);
}

int iteration(long a, long b) {

int tmp;

p = &a;
q = &b;

while (b) {
    tmp = a;
    a = b;
    b = tmp%b;
}
return a;
}

void initialize() {

fp = fopen(FILE_NAME, "r");
input = fgetc(fp);
printf("input = %c\n", input);
}

/*
void Printerror(ERRORtypes err) {

switch (err) {
case error:
    printf("ERROR");
    exit(0);
    break;
}
}
*/

void Printgcd() {

int gcd1, gcd2;
float t1, t2;
int i;



t1 = getSecond();
//for (i = 0; i < LOOP; i++)
for (i = 0; i < 5; i++)
    gcd1 = recursive(*p, *q);

t2 = getSecond();
//for (i = 0; i < LOOP; i++)
for (i = 0; i < 5; i++)
    gcd2 = iteration(*p, *q);


printf("(1)Recursion\n");
printf("u=%d, v=%d\n", *p, *q);
printf("greastest common divisor(u,v)=%d\n", gcd1);
printf("exection time = %.4fmsec\n", diffTime(t2,t1));
printf("(2)Iteration\n");
printf("greastest common divisor(u,v)=%d\n", gcd2);
printf("exection time = %.4fmsec\n", diffTime(t2,t1));
}

int main() {

initialize();

while (input != EOF) {

    Printgcd();

    return 0;
}
}