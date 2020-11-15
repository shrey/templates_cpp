

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

ll solve(int a[], int n){
    umap<ll,ll> freqLeft;
    ll ans = 0;
    for(int j = 0; j<n; j++){
        umap<ll,ll> freqRight;
        for(int k = n-1; k>=(j+1); k--){
            ans+=(freqLeft[a[k]]*freqRight[a[j]]);
            freqRight[a[k]]++;
        }
        freqLeft[a[j]]++;
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int arr[n];
        fo(n){
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<"\n";
    }
}