#include <stdio.h>

void insertElement(int arr[], int *n, int i, int insert_val) {
    if (i < 0 || i > *n) {
        printf("Invalid insertion index!\n");
        return;
    }
    
    for (int j = *n; j > i; j--) {
        arr[j] = arr[j - 1];
    }
    arr[i] = insert_val;
    (*n)++;  
}

void deleteElement(int arr[], int *n, int j) {
    if (j < 0 || j >= *n) {
        printf("Invalid deletion index!\n");
        return;
    }
    
    for (int k = j; k < *n - 1; k++) {
        arr[k] = arr[k + 1];
    }
    (*n)--;  
}

void displayArray(int arr[], int n) {
    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i, insert_val, j;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[100]; 

  
    printf("Enter %d elements:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }

    displayArray(arr, n);

    printf("Enter the index where you want to insert: ");
    scanf("%d", &i);
    printf("Enter the value to insert: ");
    scanf("%d", &insert_val);
    insertElement(arr, &n, i, insert_val);

    displayArray(arr, n);

    printf("Enter the index from which you want to delete: ");
    scanf("%d", &j);
    deleteElement(arr, &n, j);

    displayArray(arr, n);

    return 0;
}

