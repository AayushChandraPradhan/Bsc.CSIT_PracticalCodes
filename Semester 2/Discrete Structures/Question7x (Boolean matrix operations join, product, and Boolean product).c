// WAP to implement Boolean matrix operations join, product, and Boolean product

#include <stdio.h>

#define ROWS 3
#define COLS 3

void join(int mat1[][COLS], int mat2[][COLS], int result[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] || mat2[i][j];
        }
    }
}

void product(int mat1[][COLS], int mat2[][COLS], int result[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for(int k = 0; k < COLS; k++) {
                result[i][j] |= mat1[i][k] && mat2[k][j];
            }
        }
    }
}

void booleanProduct(int mat1[][COLS], int mat2[][COLS], int result[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] && mat2[i][j];
        }
    }
}

void printMatrix(int mat[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int mat1[ROWS][COLS] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}};
    int mat2[ROWS][COLS] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int result[ROWS][COLS];
    
    join(mat1, mat2, result);
    printf("Join:\n");
    printMatrix(result);
    
    product(mat1, mat2, result);
    printf("Product:\n");
    printMatrix(result);
    
    booleanProduct(mat1, mat2, result);
    printf("Boolean Product:\n");
    printMatrix(result);
    
    return 0;
}
