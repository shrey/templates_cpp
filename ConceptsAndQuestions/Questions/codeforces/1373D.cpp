

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

#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define in ll
using namespace std;
typedef long long ll;
ll modulo = 1e9 + 7;

ll solve(ll arr[], ll n){
    ll l = 0, r = 1;
    ll maxDiff = 0;
    ll currDiff = 0;
    for(ll i = 1; i<n; i+=2){
        ll diff = arr[i]-arr[i-1];
        if((currDiff+diff)<0){
            currDiff = 0;
        }
        else{
            currDiff+=diff;
            maxDiff = max(maxDiff,currDiff);
        }
    }
    currDiff = 0;
    for(ll i = 2; i<n; i+=2){
        ll diff = arr[i-1]-arr[i];
        if(currDiff+diff<0){currDiff = 0;}
        else{
            currDiff+=diff;
            maxDiff = max(maxDiff,currDiff);
        }
    }
    ll evenSum = 0;
    for(ll i = 0; i<n; i+=2){
        evenSum+=arr[i];
    }
    evenSum+=maxDiff;
    return evenSum;
}

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n];
        fo(n) cin>>arr[i];
        cout<<solve(arr,n)<<"\n";
    }
}