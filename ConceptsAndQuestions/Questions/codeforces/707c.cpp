

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
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(ld a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll flr(ld a){
    return (ll) a;
}

ll n;

bool check(ll a, ll b){
    if(a == 0 || b == 0) return false;
    if((n*n + a*a) == b*b){
        return true;
    }
    return false;
}

int32_t main(){
    KOBE;
    cin>>n;
    ll a,b;
    if(n<=1){
        cout<<-1<<"\n";
        return 0;
    }
    if(n%2){
        b = cl((ld)(n*n/2.0));
        a = n*n/2;
        // cout<<a<<" "<<b<<"\n";
    }else{
        b = (n*n/4+1);
        a = (n*n/4-1);
    }
    if(check(a,b)){
        cout<<a<<" "<<b<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
