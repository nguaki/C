#include<stdio.h>
#include<stdlib.h>

struct point *test(int x, int y);

struct point {
int x;
int y;
};


int main() {

struct point* val2;

int xx, yy;

xx = 1;

yy = 2;

val2 = test(xx, yy);

printf( "%d %d\n", val2->x, val2->y);
 }

struct point *test (int xx, int yy) {

struct point *a;

a = ( struct point *)malloc(sizeof(a));

printf( "size of a = %d\n", sizeof(a));
printf( "size of a = %d\n", sizeof(*a));
printf( "size of struct = %d\n", sizeof(struct point));

a->x = xx;

a->y = yy;

return (a);

}