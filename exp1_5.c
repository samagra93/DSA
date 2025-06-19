#include <stdio.h>

void inputMatrix(int rows, int cols, int *matrix) {
    printf("Enter elements for %d x %d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (matrix + i * cols + j)); 
        }
    }
}

void displayMatrix(int rows, int cols, int *matrix) {
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(matrix + i * cols + j));  
        }
        printf("\n");
    }
}   

void multiplyMatrices(int m, int n, int p, int *A, int *B, int *C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            *(C + i * p + j) = 0;
            for (int k = 0; k < n; k++) {
                *(C + i * p + j) += (*(A + i * n + k)) * (*(B + k * p + j));
            }
        }
    }
}

int main() {
    int m, n, p, q;
    
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("\nError: Matrix multiplication is not possible!\n");
        printf("Number of columns in A (%d) must be equal to number of rows in B (%d).\n", n, p);
        return 1;  
    }

    int A[m][n], B[p][q], C[m][q]; 

    inputMatrix(m, n, (int *)A);
    inputMatrix(p, q, (int *)B);

    printf("\nMatrix A:");
    displayMatrix(m, n, (int *)A);
    
    printf("\nMatrix B:");
    displayMatrix(p, q, (int *)B);

    multiplyMatrices(m, n, q, (int *)A, (int *)B, (int *)C);

    printf("\nProduct of A and B:");
    displayMatrix(m, q, (int *)C);

    return 0;
}

