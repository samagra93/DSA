#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;         
    int left = 2 * i + 1;    
    int right = 2 * i + 2;   

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int insert(int arr[], int n, int key) {
    int i = n;
    arr[i] = key;
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    return n + 1;
}

int deleteRoot(int arr[], int n) {
    if (n <= 0) return 0;
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);
    return n;
}

int main() {
    int arr[100] = {3, 9, 5, 1, 4, 2}; // Extra space for insertion
    int n = 6;

    printf("Original array:\n");
    printArray(arr, n);

    buildMaxHeap(arr, n);
    printf("Max Heap:\n");
    printArray(arr, n);

    n = insert(arr, n, 10);
    printf("After inserting 10:\n");
    printArray(arr, n);

    n = insert(arr, n, 7);
    printf("After inserting 7:\n");
    printArray(arr, n);

    n = deleteRoot(arr, n);
    printf("After deleting root:\n");
    printArray(arr, n);

    return 0;
}
