#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findMin(int arr[], int start, int size);
void printArr(int arr[], int size);
void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Syntax Error: ./<exec> <infile>\n");
        exit(1);
    }

    FILE *ifp = NULL;
    ifp = fopen(argv[1], "r");

    if(ifp == NULL)
    {
        printf("Could not open %s for reading\n", argv[1]);
        exit(1);
    }

    int counter;
    int j = 0;

    fscanf(ifp, "%d", &counter);

    int array[counter];
    int arrB[counter];
    for(j = 0; j < counter; ++j)
    {
        fscanf(ifp, "%d", &array[j]);
    }

    for(j = 0; j < counter; j++)
    {
        arrB[j] = array[j];
    }
    int size = sizeof(array) / sizeof(int);

    printf("Before: ");
    printArr(array, size);

    selectionSort(array, size);
    bubbleSort(arrB, size);

    fclose(ifp);

    return 0;
}
int findMin(int arr[], int start, int size)
{
    int i = 0;
    int minLoc = start;
    int minVal = arr[minLoc];

    for ( i = start + 1; i < size; ++i)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
            minLoc = i;
        }
    }

    return minLoc;
}

void printArr(int arr[], int size)
{
    int i = 0;

    for(i = 0; i < size; ++i)
        printf("%3d ", arr[i]);
    printf("\n");
}
void selectionSort(int arr[], int size)
{
    int i = 0;
    int minLoc = 0;
    int tmp = 0;
    for(i = 0; i < size; ++i)
    {
        minLoc = findMin(arr, i, size);
        tmp = arr[i];
        arr[i] = arr[minLoc];
        arr[minLoc] = tmp;
    }

    printf("** Selection Sort **\n After: ");
    printArr(arr, size);

}
void bubbleSort(int arr[], int size)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    for(j = 0; j < size; j++)
    {
        for(i = 0; i < size; ++i)
        {
            if(arr[i] > arr[i+1])
            {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
    }
    printf("** Bubble Sort **\n After: ");
    printArr(arr, size);

}
