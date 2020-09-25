

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"

ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

int main(){
    KOBE;
    ll n;
    cin>>n;
    ll arr[n];
    fo(n) cin>>arr[i];
    ll lis[n];
    fo(n){
        lis[i] = 1;
        if(i>0 && arr[i]>arr[i-1]){
            lis[i] = lis[i-1]+1;
        }
    }
    ll rev[n];
    rev[n-1] = 1;
    for(ll i = n-2; i>=0; i--){
        rev[i] = 1;
        if(arr[i]<arr[i+1]){
            rev[i] = rev[i+1]+1;
        }
    }
    ll ans = 1;
    fo(n){
        ans = max(ans,lis[i]);
    }
    for(ll i = 1; i<n-1; i++){
        ll t = rev[i+1] + lis[i-1];
        if(t>ans && arr[i-1]<arr[i+1]){
            ans = t;
        }
    }
    cout<<ans<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
