

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

const ll M = 1e5+100;
ll n,m,x,y;
vl g[M];
vl gr[M];
vl gr2[M];
map<pll,ll> edges;
vb vis(M,false);
vp res;
vl order; vl scc;


void dfs0(ll cur){
    vis[cur] = true;
    for(auto x: g[cur]){
        if(!edges[mp(min(x,cur),max(x,cur))]) continue;
        gr[cur].pb(x);
        gr2[x].pb(cur);
        res.pb(mp(cur,x));
        edges[mp(min(x,cur),max(x,cur))]--;
        if(!vis[x]) dfs0(x);
    }
}

void dfs(ll cur){
    vis[cur] = true;
    for(auto x: gr[cur]){
        if(!vis[x]) dfs(x);
    }
    order.pb(cur);
}

void dfs2(ll cur){
    vis[cur] = true;
    scc.pb(cur);
    for(auto x: gr2[cur]){
        if(!vis[x]){
            dfs2(x);
        }
    }
}

void solve(){
    re n; re m;
    fo(m){
        re x; re y;
        edges[mp(min(x,y),max(x,y))]++;
        g[x].pb(y); g[y].pb(x);
    }
    dfs0(1);
    fo(n+1) vis[i] = false;
    dfs(1);
    if(order.size() != n){
        pr(0);
        return;
    }
    fo(n+1) vis[i] = false;
    dfs2(order[n-1]);
    if(scc.size() != n){
        pr(0);
        return;
    }
    for(auto e: res) cout<<e.ff<<" "<<e.sec<<"\n";
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
