#include <stdio.h>

int linearSearch(float arr[], int size, float target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;
}

int main() {
    int n;
    float target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n]; 

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%f", &target);

    int index = linearSearch(arr, n, target);

    if (index != -1) {
        printf("Success! Number %.2f found at index %d.\n", target, index);
    } else {
        printf("Failure! Number %.2f not found in the array.\n", target);
    }

    return 0;
}

