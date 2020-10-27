

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

bool solve(){
    ll n;
    cin>>n;
    ll a[n];
    fo(n){
        cin>>a[i];
        a[i]+=i;
        a[i]%=n;
        if(a[i]<0) a[i]+=n;
    }
    //if (a[i]+i+(x)*n) == a[j]+j for any i,j the ans if false, so take mod on both sides
    umap<ll,bool> marked;
    for(ll i = 0; i<n; i++){
        if(marked[a[i]]) return false;
        marked[a[i]] = true;
    }
    return true;
}


int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        if(solve()){
            YES;
        }else{
            NO;
        }

    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs