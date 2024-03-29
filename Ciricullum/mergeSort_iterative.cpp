

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



#include<iostream>
using namespace std;




void merge(int arr[], int s, int m, int e){
    int n1 = m-s+1;
    int n2 = e-m;
    int left[n1], right[n2];
    for(int i = 0; i<n1; i++){
        left[i] = arr[s+i];
    }
    for(int i = 0; i<n2; i++){
        right[i] = arr[m+i+1];
    }
    int i = 0, j = 0, k = s;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }

    }
    while(i<n1){
        arr[k] = left[i];
        i++; k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++; k++;
    }

}


void mergeSort(int arr[], int n){

    for(int sz = 1; sz<n; sz=2*sz){
        for(int s = 0; s<n-1; s+=(2*sz)){
            int mid = min(s+sz-1,n-1);
            int e = min(s+2*sz-1,n-1);
            merge(arr,s,mid,e);
        }
    }
}

int main(){
    int arr[] = {4,5,3,5,6,7};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}