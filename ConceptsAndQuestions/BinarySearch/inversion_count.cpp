

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

int cntMerge(ll arr[], int s, int e){
    int mid = (s+e)/2;
    int cnt = 0;
    ll temp[e+1];
    int i = s, j = (s+e)/2+1, k = s;
    while(i<=mid && j<=e){
        if(arr[i]>arr[j]){
            // cout<<"("<<arr[i]<<" "<<j<<")"<<endl;
            temp[k++] = arr[j++];
            cnt+=(mid-i+1);
        }
        else{
            temp[k++] = arr[i++];
        }
    }
    temp[k++] = arr[i++];
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    // cout<<"("<<s<<" "<<e<<")"<<" "<<cnt<<endl;
    for(int i = s; i<=e; i++){
        // cout<<temp[i]<<" ";
        arr[i] = temp[i];
    }

    return cnt;
}

int inversionCnt(ll arr[], int s, int e){
    if(s >= e){
        return 0;
    }
    int mid = (s+e)/2;
    int a = inversionCnt(arr,s,mid);
    int b = inversionCnt(arr,mid+1,e);
    int c = cntMerge(arr,s,e);
    return (a+b+c);
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n];
        fo(n){
            cin>>arr[i];
        }

        cout<<inversionCnt(arr,0,n-1)<<endl;
        // fo(n){cout<<arr[i]<<" ";}cout<<endl;s
    }
}