#include <iostream>
using namespace std;
void merge(int *arr, int s, int e){
    int mid = (s + e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    for(int i = s; i<=e; i++){
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    //divide
    int mid = (s+e)/2;
    //recursively sort the 2  arrays
    mergeSort(arr,s,mid);
    mergeSort(arr,mid + 1, e);
    merge(arr,s,e);
}

int main() {
    int arr[] = {2,1,3,2,6,5};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for(int i = 0; i<n; i++){
        printf("%d", arr[i]);
        printf(" ");
    }
    printf("\n");
}
