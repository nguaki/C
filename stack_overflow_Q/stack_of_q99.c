//100 factorial
//93326215443944152681699238856266700490715968264381621468592963895217599993229915608
//941463976156518286253697920827223758251185210916864000000000000000000000000
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#if __STDC_VERSION__>=199901L
#include <inttypes.h>
#else
#define PRIu16 "hu"
#endif

typedef struct _unums {
    size_t size;
    uint16_t *nums;//array 
} UNums;

void UNums_init(UNums *num, uint16_t n){
    num->nums = (uint16_t*)malloc(sizeof(uint16_t));
    num->nums[0] = n;
    num->size = 1;
}

void UNums_mul(UNums *num, uint16_t n){
    uint16_t carry = 0;
    size_t i;

    for(i=0;i<num->size;++i){
        uint32_t wk = n;
        wk = wk * num->nums[i] + carry;
        num->nums[i] = wk % 10000;
        carry = wk / 10000;
    }
    if(carry){
        num->size += 1;
        num->nums = (uint16_t*)realloc(num->nums, num->size * sizeof(uint16_t));
        num->nums[i] = carry;
    }
}

void UNums_print(UNums *num){
    size_t i = num->size;
    int w = 0;
    do{
        --i;
        printf("%0*" PRIu16, w, num->nums[i]);
        if(!w) w = 4;
    }while(i!=0);
}

void UNum_drop(UNums *num){
    free(num->nums);
    num->nums = NULL;
}

int main( void ){
    UNums n;
    uint16_t i;

    UNums_init(&n, 1);
    for(i=2;i<=100;++i)
        UNums_mul(&n, i);
    UNums_print(&n);//100!
    UNum_drop(&n);
    return 0;
}