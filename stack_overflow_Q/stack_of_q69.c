#include<stdio.h>
#include <stdbool.h>

typedef int (*comparatorPtr)(void*, void*);
bool isMaxHeap(void *heap, int index, int length, size_t size, comparatorPtr comparator);

/**
 * comparator with pointers (the mistake could be here)
 */
int comparator_integer(void* e1, void* e2) {
    int i1 = *(int *) e1;
    int i2 = *(int *) e2;

    //print 2 elements of array/heap
    printf("i1 heap: %d\n", i1);
    printf("i2 heap: %d\n", i2);
    printf("***************************\n");

    
    if (i1 == i2) return 0;
    else if (i1 > i2) return 1;
    else return -1;
}

/**
 * Function for check if the array is or isn't a maxHeap
 */
bool isMaxHeap(void *heap, int index, int length, size_t size, comparatorPtr comparator) {
    char *heapbase = heap;
    if (index >= length) {
        return true;
    }

    printf("I'm calling comparator 1 \n%d value index1\n",index);
    if (length > index * 2 + 1 && comparator(heapbase + index * size, heapbase + (index * 2 + 1) * size) < 0) {
        printf("I am returning false from comparator1.\n");
        return false;
    }

    printf("I'm calling comparator 2 \n%d value index2\n",index);
    printf("Value lenght %d\n", length);
    if (length > index * 2 + 2 && comparator(heapbase + index * size, heapbase + (index * 2 + 2) * size) < 0) {
        return false;
    }

    printf("I'm calling comparator 3 \n");
    return isMaxHeap(heap, index * 2 + 1, length, size, comparator) && isMaxHeap(heap, index * 2 + 2, length, size, comparator);
}

int main() {
    int array[6] = {90, 15, 10, 7, 12, 2}; //maxHeap array
    int length = sizeof(array)/ sizeof(array[0]);
    int index = 0;

    printf("element in position 1: %d\n",*(array + (index*2)+1));
    printf("length %d\n", length);

    isMaxHeap(array, index, length, sizeof array[0], comparator_integer) ? printf("Yes\n"): printf("No\n");
    return 0;
}