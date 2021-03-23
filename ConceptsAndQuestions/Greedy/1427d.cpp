

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
#include<bitset>
#include<cstring>
#include<numeric>
#include<array>


using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
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
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
#define endl "\n"
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)
#define all(x) x.begin(),x.end()
#define LG 20

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

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
    if(a < 0.0){
        return (ll) a - 1;
    }
    return (ll) a;
}

//code starts here

const ll M = 55;
ll n;
vl a;

bool check(){
    for(ll i = 0; i<n; i++){
        if(a[i] != i+1) return false;
    }
    return true;
}

void solve(){
    re n;
    a.resize(n);
    fo(n) re a[i];
    vector<vl> res;
    ll q = 1;
    while(!check()){
        // for(auto x: a) cout<<x<<" "; nl;
        vl vis(n+1,0);
        vis[0] = 1;
        for(ll i = 0; i<n; i++){
            vis[a[i]] = 1;
            if(!vis[a[i]-1]){
                ll j = i+1;
                while(j < n && a[j] != a[i]-1) j++;
                ll t = i+1;
                while(t < n && a[t] > a[t-1]) t++;
                vl cans;
                if(i) cans.pb(i);
                cans.pb(t-i);
                cans.pb(j-t+1);
                if(n-j > 1) cans.pb(n-j-1);
                vl b;
                for(ll k = j+1; k <n; k++) b.pb(a[k]);
                for(ll k = t; k<=j; k++) b.pb(a[k]);
                for(ll k = i; k<t; k++) b.pb(a[k]);
                for(ll k = 0; k<i; k++) b.pb(a[k]);
                a = b;
                res.pb(cans);
                break;
            }
        }
    }
    pr(res.size());
    for(auto vec: res){
        cout<<vec.size()<<" "; for(auto x: vec) cout<<x<<" "; nl;
    }
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    // re t;
    while(t--) solve();
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
