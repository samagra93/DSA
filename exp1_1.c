#include <stdio.h>
int soa(int arr[], int n){
    if(n<0){
       return 0;
    }
    else{
        return arr[n]+soa(arr,n-1);
    }

}
int main(){
    int n,a;
    printf("Enter the length of array:\n"); 
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of an array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    a=soa(arr,n-1);
    printf("The sum of elements of array is: %d\n",a);
    return 0;
}
