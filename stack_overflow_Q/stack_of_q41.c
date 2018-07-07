#include <stdio.h>
void insert_node(int arr[], int max){
    
    char garbage[50];
    if(max<15){
        printf("Type the number to insert: ");
        scanf("%d", &arr[max]);  
        fgets( garbage, sizeof(garbage), stdin);
        max++;
        }
    else
    printf("Error. The heap is full!");
}
void printheap(int arr[], int max){
    int count;  
    if(max>=1){
        printf("\nPrinting the Heap:");
        for(count=0;count<max;count++)
        printf(" %d", arr[count]);
    }
}
void heapSort(int arr[], int max) {
    int i=0,temp,lc,rc; 
    while(i!=max-1){
        lc=2*i+1;
        rc=2*i+2;
        if(arr[i]<arr[lc]){ 
            temp=arr[i];
            arr[i]=arr[lc];
            arr[lc]=temp;
        }
        else if(arr[i]<arr[rc]){
            temp=arr[i];
            arr[i]=arr[rc];
            arr[rc]=temp;
        }   
        i=i+1;
    }
}
int main(int argc, char *argv[]){
    int arr[15];
    int max=0;  
    char ch;
    while(ch!='n' && ch!='N'){
        printheap(arr,max);
        insert_node(arr,max++);   
        if(max>1)
            heapSort(arr,max);
        printf("\nInsert another key (y:yes/n:no)?  ");
        scanf("%c", &ch);
    }
    return 0;
}