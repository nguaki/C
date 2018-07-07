#include <stdio.h>
 
int main(void) {
	char a[] = "AAAAAAAAAA";
	char b[] = "BBBBBBBBBB";
	char *args[] = {a, b, NULL};
	char **pp = args;
	(*pp++)[1] = 0;
	printf("a:%s\n", a);
	printf("b:%s\n", b);
	return 0;
}