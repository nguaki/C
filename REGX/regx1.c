//Ret code:1 Number:121
//Ret code:1 Number:121
//Ret code:1 Number:1
#include <stdio.h>
 
int main(void) {
	int n = 99999;
	int res = sscanf("hello 121", "%*[^0-9]%d", &n);
	printf("Ret code:%d Number:%d\n", res, n);

	res = sscanf("he121llo", "%*[^0-9]%d", &n);
	printf("Ret code:%d Number:%d\n", res, n);

	res = sscanf("he1llo", "%*[^0-9]%d", &n);
	printf("Ret code:%d Number:%d\n", res, n);

	res = sscanf("he1ll2o", "%*[^0-9]%d", &n);
	printf("Ret code:%d Number:%d\n", res, n);
	return 0;
}