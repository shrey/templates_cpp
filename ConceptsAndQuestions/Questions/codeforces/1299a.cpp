

//Shrey Dubey

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
#include<climits>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define sec second
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
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

const ll M = 1e5+100;

ll arr[M],n;

umap<ll,set<ll> > bitpos;
umap<ll,bool> usedInd;
vl ans;



int32_t main(){
    KOBE;
    cin>>n;
    fo(n){
        cin>>arr[i];
    }
    ll pref[n],suff[n];
    pref[0] = ~arr[0];
    for(ll i = 1; i<n; i++){
        pref[i] = pref[i-1]&(~arr[i]);
    }
    suff[n-1] = ~arr[n-1];
    for(ll i = n-2; i>=0; i--){
        suff[i] = suff[i+1]&(~arr[i]);
    }
    ll maxres = ((suff[1])&arr[0]);
    ll ans = 0;
    for(ll i = 1; i<n; i++){
        ll curr;
        if(i == n-1){
            curr = ((pref[i-1])&arr[i]);
        }
        else{
            curr = (((pref[i-1]&suff[i+1]))&arr[i]);
        }
        // cout<<i<<" "<<curr<<"\n";
        if(curr>maxres){
            maxres = curr;
            ans = i;
        }
    }
    swap(arr[0],arr[ans]);
    fo(n) cout<<arr[i]<<" ";cout<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
