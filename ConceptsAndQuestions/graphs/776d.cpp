

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

ll n,m;
const ll M = 1e5+100;
vl op;
vl close;
vl mat[M];
vp gr[M];
vl vis(M,false);

vl p(M,0); vl r(M,1);

ll getp(ll v){
    if(v == p[v]) return v;
    return p[v] = getp(p[v]);
}

void unite(ll u, ll v){
    u = getp(u), v = getp(v);
    if(u == v) return;
    if(r[u] < r[v]) swap(u,v);
    r[u] += r[v];
    p[v] = u;
}
vl side(M,-1);

bool bpcheck(ll src){
    queue<ll> q;
    q.push(src);
    // cout<<src<<"()\n";
    side[src] = 0;
    vis[src] = true;
    while(!q.empty()){
        ll par = q.front();
        q.pop();
        for(auto x: gr[par]){
            ll co = side[par];
            if(x.sec == 1) co = 1-co;
            if(vis[x.ff] && side[x.ff] != co) return false;
            if(!vis[x.ff]){
                vis[x.ff] = true;
                side[x.ff] = co;
                q.push(x.ff);
            }
        }
    }
    return true;
}

void solve(){
    re n; re m;
    fo(n){
        ll x; re x;
        if(x) op.pb(i+1);
        else close.pb(i+1);
    }
    fo(m){
        ll x; re x;
        forn(j,x){
            ll k; re k;
            mat[k].pb(i+1);
        }
    }
    // fo(n){
    //     cout<<i+1<<" - "<<mat[i+1][0]<<" , "<<mat[i+1][1]<<"\n";
    // }

    for(auto x: close){
        ll a = mat[x][0], b = mat[x][1];
        gr[a].pb(mp(b,1));
        gr[b].pb(mp(a,1));
    }
    bool flag = true;
    for(auto x: op){
        ll a = mat[x][0], b = mat[x][1];
        gr[a].pb(mp(b,0));
        gr[b].pb(mp(a,0));
    }
    for(ll i = 1; i<=m; i++){
        if(!vis[i]){
            if(!bpcheck(i)){
                NO;
                return;
            }
        }
    }
    YES;
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
