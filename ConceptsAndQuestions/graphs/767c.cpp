

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

const ll M = 1e6+100;
vl gr[M];
ll n,a[M],x,y;
ll par[M] = {0};
ll dp[M] = {0};
ll sz[M] = {0};

void dfs(ll cur){
    dp[cur] += a[cur];
    sz[cur] = 1;
    for(auto x: gr[cur]){
        dfs(x);
        dp[cur] += dp[x];
        sz[cur] += sz[x];
    }
}

void solve(){
    re n;
    ll r;
    fo(n){
        re x; re a[i+1];
        if(x) gr[x].pb(i+1);
        else r = i+1;
        par[i+1] = x;
    }
    dfs(r);
    if(dp[r] % 3){
        pr(-1);
        return;
    }
    ll req = dp[r] / 3;
    ll op = -1;
    ll s = 1e15;
    for(ll i = 1; i<=n; i++){
        if(dp[i] == req && sz[i] < s && i != r){
            s = sz[i];
            op = i;
        }
    }
    if(op == -1){
        pr(-1);
        return;
    }
    vl res;
    res.pb(op);
    ll p = par[op];
    while(p != 0){
        dp[p] -= req;
        p = par[p];
    }
    for(ll i = 1; i<=n; i++){
        if(i != op && dp[i] == req && i!=r){
            res.pb(i);
            break;
        }
    }
    if(res.size() != 2){
        pr(-1);
        return;
    }
    for(auto x: res) cout<<x<<" "; nl;
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
