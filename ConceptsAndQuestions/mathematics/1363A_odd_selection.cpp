

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
#include <math.h>



#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

bool solve(int arr[], int n, int x){
    int a = 0, b = 0;

    if(n<x) return false;
    fo(n){
        if(arr[i]%2){
            b++;
        }else{
            a++;
        }
    }
    // cout<<a<<" "<<b<<endl;
    if(x%2 == 0){
        //odd number of odd numbers and odd number of even numbers
        for(int i = 1; i<=x; i+=2){
            if(b>=i && a>=(x-i)){
                return true;
            }
        }
    }else{
        if(b>=x || b%2 == 1) return true;
        //odd number of odd numbers and even number of even numbers
        for(int i = 1; i<=x; i+=2){
            if(b>=i && a>=(x-i)){
                return true;
            }
        }

    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        fo(n) cin>>arr[i];
        if(solve(arr,n,x)){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}