

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<list>
#include<iomanip>
#include<queue>
#include<stack>


#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int bitonic(int arr[], int n){
    int dp1[n];
    int dp2[n];
    dp1[0] = 1;
    for(int i = 1; i<n; i++){
        dp1[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[i]>arr[j]){
                dp1[i] = max(dp1[i],dp1[j]+1);
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout<<"("<<arr[i]<<","<<dp1[i]<<") ";
    }cout<<endl;
    reverse(arr,arr+n);
    dp2[0] = 1;
    for(int i = 1; i<n; i++){
        dp2[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[i]>arr[j]){
                dp2[i] = max(dp2[i],dp2[j]+1);
            }
        }
    }
    int result = 1;
    for(int i = 0; i<n; i++){
        cout<<"("<<arr[i]<<","<<dp2[i]<<") ";
    }cout<<endl;
    for(int i = 0; i<n; i++){
        result = max(result,dp1[i] + dp2[n-i-1]-1);
    }
    return result;
}

int main(){
    int arr[] = {12, 11, 40, 5, 3, 1};
    int n = sizeof(arr)/sizeof(int);
    cout<<bitonic(arr,n)<<endl;
}