#include <stdio.h>
#include <stdlib.h>
void inputMatrix(int**, int, int);
void outputMatrix(int **, int, int);

int main(){
    int rows, cols;
    printf("Nhap so dong(rows) va cot(cols): ");
    scanf("%d %d", &rows, &cols);

    //cap phat bo nho
    int **matrix= (int**)malloc(rows*sizeof(int *));//2D
    for(int i=0; i<rows; i++){
        matrix[i] = (int *)malloc(cols*sizeof(int));//1D
    }
    inputMatrix(matrix, rows, cols);
    outputMatrix(matrix, rows, cols);

    //giai phong bo nho
    for(int i=0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
void inputMatrix (int **matrix, int rows, int cols){
    printf("Nhap cac phan tu ma tran: \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void outputMatrix(int **matrix, int rows, int cols){
    printf("Ma tran vua nhap la: \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
