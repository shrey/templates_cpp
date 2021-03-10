

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

ll n,x,y;
const ll M = 2e5+100;
vl gr[M];
vl path;
vl mark(M,0);
vb vis2(M,false);
vl dist2(M,0);
ll k;


ll bfs(ll src){
    vb vis(n+1,false);
    vl dist(n+1,0);
    path.clear();
    path.resize(n+1);
    path[src] = 0;
    queue<ll> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        // cout<<cur<<"()\n";
        for(auto x: gr[cur]){
            if(!vis[x] && !mark[x]){
                vis[x] = true;
                q.push(x);
                dist[x] = dist[cur] + 1;
                path[x] = cur;
            }
        }
    }
    ll d = src;
    for(ll i = 1; i<=n; i++){
        if(dist[i] > dist[d]) d = i;
    }
    k = dist[d];
    return d;
}




pll bfs2(ll src){
    vl cur;
    cur.pb(src);
    queue<ll> q;
    q.push(src);
    vis2[src] = true;
    while(!q.empty()){
        ll t = q.front();
        q.pop();
        for(auto x: gr[t]){
            if(!vis2[x] && !mark[x]){
                vis2[x] = true;
                q.push(x);
                dist2[x] = dist2[t] + 1;
                cur.pb(x);
            }
        }
    }
    ll d = src;
    for(auto x: cur){
        if(dist2[x] > dist2[d]) d = x;
    }
    return mp(d,dist2[d]);
}

void solve(){
    re n;
    fo(n-1){
        re x; re y;
        gr[x].pb(y), gr[y].pb(x);
    }
    ll a = bfs(1);
    ll b = bfs(a);
    vl p;
    // cout<<a<<"()"<<b<<"\n";
    ll cur = b;
    while(cur != 0){
        p.pb(cur);
        cur = path[cur];
    }
    for(auto x: p) mark[x] = 1;
    ll c, res = -1;
    for(auto x: p){
        pll cur = bfs2(x);
        if(cur.sec > res && cur.ff != a && cur.ff != b){
            res = cur.sec;
            c = cur.ff;
        }
    }
    res += k;
    pr(res);
    cout<<a<<" "<<b<<" "<<c<<"\n";
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
