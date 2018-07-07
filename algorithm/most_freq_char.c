//May 2, 18
//Prints out the most frequent character.
//
//Here are important things to know in order to solve this problem.
//
// There are 256 alphanumerica characters.
// Character has an ASCII decimal value.
// So in the context of array[char], char becomes an ASCII decimal value.
// e.g.  array['A'] = array[65].
//
// Also concept of hashmap is necessary.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char 
cFindMostFreqChar( const char *caString)
{
    int iCharCnt[256] = {0};
    int iHighest = 0;
    char cMostFreqChar;
    
    while(*caString){
        
        iCharCnt[*caString]++;
        if( iCharCnt[*caString] > iHighest ){
            iHighest = iCharCnt[*caString];
            cMostFreqChar = *caString;
        }
        caString++;
    }
    return cMostFreqChar;
    
}


int
main(void)
{
    const char caString[] = "aaaabbbcccddee";
    
    printf( "%c\n", cFindMostFreqChar(caString));
    assert( cFindMostFreqChar("aaaabbbbeeeee") == 'e');
    assert( cFindMostFreqChar("aaaabbbbeeeee       ") == ' ');
    assert( cFindMostFreqChar("abcdefgzzz") == 'z');
return 1;
}
