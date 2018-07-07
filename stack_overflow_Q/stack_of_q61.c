#include <stdio.h>

int main() {
    // a is a byte array
    unsigned char a[] = "0a\xeb";
  
    printf("sizeof a = %lu\n", sizeof a);
    
    for(size_t i = 0; i < sizeof a; i++) 
        printf( "%u  %c\n", a[i], a[i]);
    
    for (size_t i = 0; i < sizeof a; i++) {
        int b = (int)a[i];
        int s = (b & 0xFF) | ((b & 0x80) ? ~0xFF : 0);
        printf("a[%zd] = 0x%hhx, b: 0x%x, %d, s: 0x%x, %d\n",
               i, a[i], b, b, s, s);
    }
    return 0;
}