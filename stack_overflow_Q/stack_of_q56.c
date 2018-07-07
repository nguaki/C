/*
Printing an unsigned long long using %X format specifier is undefined behavior, 
because sprintf expects an int for %X. It produces correct results when you switch 
around the specifiers by an unfortunate coincidence. The behavior on different 
platforms may not be the same.

Use %llX to print the value:

08105DBF;135290303
0135290303;08105DBF;
08105DBF;135290303

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(void)
{
    char pcMsg[255];
    int iMsgAllocatedLength=255;
    unsigned long long ullRecordID = 135290303ULL;
    snprintf(pcMsg, iMsgAllocatedLength, "%08X;%llu", ullRecordID, ullRecordID);
    printf("%s\n", pcMsg );
    snprintf(pcMsg, iMsgAllocatedLength, "%010llu;%08X;", ullRecordID, ullRecordID);
    printf("%s\n", pcMsg );

    snprintf(pcMsg, iMsgAllocatedLength, "%08llX;%llu", ullRecordID, ullRecordID); 
    printf("%s\n", pcMsg );

    return 0;
}