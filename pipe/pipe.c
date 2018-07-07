#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pipe(fd);
    
    printf("fd[0] = %d\n", fd[0]);
    printf("fd[1] = %d\n", fd[1]);
    

    FILE* write_file = fdopen(fd[1], "w");
    FILE* read_file = fdopen(fd[0], "r");
    int x = 0;
    
    printf("write_file = %x read_file = %x\n", write_file, read_file);
    if( write_file != NULL && read_file != NULL )
    { 
        //fprintf(write_file, "%da", 500); 
        fprintf(write_file, "%d ", 600); 
        fflush(write_file);
        fscanf(read_file, "%d", &x);
        printf("%d\n", x);
    }

    x = -999;
    if( write_file != NULL && read_file != NULL )
    { 
        fprintf(write_file, "%d ", 200); 
        fflush(write_file);
        fscanf(read_file, "%d", &x);
    
        printf("%d\n", x);
        fprintf(write_file, "%d ", 8800); 
        fflush(write_file);
        fscanf(read_file, "%d", &x);
        printf("%d\n", x);
        fprintf(write_file, "%d ", 9999); 
        fflush(write_file);
        fscanf(read_file, "%d", &x);
        printf("%d\n", x);
    }
}