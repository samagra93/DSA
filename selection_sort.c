#include<stdio.h>
 
void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void selectionSort(int *A, int n){
    int indexofmin,temp;
    printf("Running selection sort:");
    for(int i=0;i<n-1;i++)
    {
        indexofmin= i;
        for(int j = i + 1; j<n;j++)
        {
            if(A[j]<A[indexofmin])
            {
                indexofmin=j;
            }
        }
        temp=A[i];
        A[i]=A[indexofmin];
        A[indexofmin]=temp;
    }
}
 
 
int main(){
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n); // Printing the array before sorting
    selectionSort(A, n); // Function to sort the array
    printArray(A, n); // Printing the array before sorting
    return 0;
}
