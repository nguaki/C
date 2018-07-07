#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
int main(void){
	const char *input = "Parrot says hi!";
	char word[40];//or more size
 
	const char *pi = input;
	while(*pi){
		char *po = word;
		while(*pi && !isalpha((unsigned char)*pi)){
			++pi;//skip not alpha
		}
		while(*pi && isalpha((unsigned char)*pi)){
			*po++ = *pi++;
		}
		*po = 0;
		if(*word)
			puts(word);//push(strdup(word));//and pop then free
	}
}