#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;
    for (int i = 1; i <= n-1; i++){
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    printf("Original array: ");
    printArray(A, n); 

    insertionSort(A, n); 

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
