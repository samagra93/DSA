#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("\nThe matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void sumRows(int rows, int cols, int matrix[rows][cols]) {
    printf("\nSum of each row:\n");
    for (int i = 0; i < rows; i++) {
        int row_sum = 0;
        for (int j = 0; j < cols; j++) {
            row_sum += matrix[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, row_sum);
    }
}

void sumColumns(int rows, int cols, int matrix[rows][cols]) {
    printf("\nSum of each column:\n");
    for (int j = 0; j < cols; j++) {
        int col_sum = 0;
        for (int i = 0; i < rows; i++) {
            col_sum += matrix[i][j];
        }
        printf("Column %d sum = %d\n", j + 1, col_sum);
    }
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];  
    
    inputMatrix(rows, cols, matrix);
    displayMatrix(rows, cols, matrix);
    sumRows(rows, cols, matrix);
    sumColumns(rows, cols, matrix);

    return 0;
}

