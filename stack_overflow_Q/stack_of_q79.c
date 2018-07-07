//MACRO doesn't evalute.  It just expands.
#include <stdio.h>

#define HEX_TO_DEC(num) 0x##num

int
main(void)
{
unsigned hexValue_1 = HEX_TO_DEC(5310B00B);
unsigned hexValue_2 = HEX_TO_DEC(DEADBEEF);
//
//This will expand to this:
//unsigned hexValue_1 = 0x5310B00B;
//unsigned hexValue_2 = 0xDEADBEEF;
//

//And that's all fine and good. Now what would this expand to, do you think?

//unsigned i = 2345;
//unsigned hexValue_3 = HEX_TO_DEC(i); // ?
//Because macros substitute text, not values, it expands to this:

//unsigned i = 2345;
//unsigned hexValue_3 = 0xi;