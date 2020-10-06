

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

int32_t main(){
    KOBE;
    ll n;
    cin>>n;
    ll a[4],b[4];
    fo(3) cin>>a[i+1];
    fo(3) cin>>b[i+1];
    ll maxwins = min(a[1],b[2]) + min(a[2],b[3]) + min(a[3],b[1]);
    ll minwins = 0;
    ll c1 = b[1]+b[3];
    a[1]-=min(a[1],c1);
    c1-=min(a[1],c1);
    ll o1 = min(b[1],c1);
    a[2]-=min(o1,a[2]);
    c1-=min(o1,a[2]);
    ll o2 = min(c1,b[3]);
    a[3]-=min(o2,a[3]);
    ll c2 = min(a[2],b[2]);
    a[2]-=c2;
    b[2]-=c2;
    ll f = min(a[3],b[2]);
    a[3]-=f;
    minwins = a[1]+a[2]+a[3];
    cout<<minwins<<" "<<maxwins<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
