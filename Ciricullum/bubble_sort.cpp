#include<iostream>

using namespace std;

int main(){
    int a[] = {5,6,3,2,1};
    int n = sizeof(a)/sizeof(int);
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        // cout<<"Step "<<i<<" - \n";
        // for(int i = 0; i<n; i++) cout<<a[i]<<" "; cout<<"\n";
    }
    cout<<"Sorted array is :- \n";
    for(int i = 0; i<n; i++) cout<<a[i]<<" "; cout<<"\n";
}