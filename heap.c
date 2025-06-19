#include <stdio.h>
// Function to heapify a subtree rooted at index i in array of size n
void heapify(int arr[], int n, int i) 
{
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index
   // If left child is larger than root

    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not root
    if (largest != i) {
        // Swap
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// Function to build a max heap
void buildMaxHeap(int arr[], int n) {
    // Index of last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
// Utility function to print the array
void printArray(int arr[], int n)
 {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
// Main function
int main() {
    int arr[] = {3, 9, 5, 1, 4, 2}; // Your input example
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr, n);
    buildMaxHeap(arr, n);
    printf("Max Heap:\n");
    printArray(arr, n);
    return 0;
}