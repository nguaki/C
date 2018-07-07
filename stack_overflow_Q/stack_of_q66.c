#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    int in, jn, row, col, **mat;
    scanf("%d %d", &row, &col);
    mat = (int **) malloc(row * sizeof(int *));
    if(mat == NULL){
        printf("Error. Allocation was unsuccessful. \n");
        return 1;
    }
    for(in = 0; in < row; in++){
        mat[in] = (int *) malloc((row) * sizeof(int));
        assert(mat[in]!=NULL);
    }
    for(in = 0; in < row; in++){
        for(jn = 0; jn < col; jn++){
            scanf("%d", &mat[in][jn]);
        }
    }
    for(in = 0; in < row; in++){
        for(jn = 0; jn < col; jn++){
            printf("%d ", mat[in][jn]);
        }
        printf("\n");
    }
    return 0;
}