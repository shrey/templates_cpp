

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


int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

bool is_swappable1(int a, int b, int min_no){
    if(gcd(a,b) == min_no){
        return true;
    }
    return false;
}

bool is_possible(int arr[], int n){
    int min_num = INT_MAX;
    fo(n){
        min_num = min(min_num,arr[i]);
    }
    for(int i = 0; i<n-1;i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j]){
                if(is_swappable1(arr[i],arr[j],min_num)){
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    for(int i = 1; i<n; i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    int n;
    cin>>t;

    while(t--){
        cin>>n;
        int arr[n];
        int min_num = INT_MAX;
        fo(n){
            cin>>arr[i];
        }
        if(is_possible(arr,n)){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }

    }
}