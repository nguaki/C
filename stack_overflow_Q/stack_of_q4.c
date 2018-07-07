#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
#include <ctype.h>
void Upper(char *x)
{
int i = 0;
while (x[i]!='\0')
{
    if (x[i] >= 97 && x[i] <= 122)
    {
        x[i] -= 32;
    }
            i++;

}
    return;

}
int main() {
char *A = "Just for Try.";
Upper(A);
printf("%s",A);
getchar();
return 0;
}