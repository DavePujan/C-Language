// 9.3 Write a program to implement Bubble Sort

/*
i 0 to n-1
j 0 to n-i-1
if arr j > arr j+1
swap arr j and arr j+1
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int n){
    for(int i=o;i< n-1;i++){
        for(int j=0;i<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int rr[]= {64,45,43,44,56,78,98};
    int n= sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        printf("\n");

        return 0;
    }
}