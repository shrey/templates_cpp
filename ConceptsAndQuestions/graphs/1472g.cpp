

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
    return (ll) a;
}



//code starts here

const ll M = 2e5+100;
ll n,m,x,y;
vl gr[M];
const ll inf = 1e15;
vl dist(M,inf);
vl par_dist(M,-1);
vb vis(M,false);
ll dp[M] = {0};

void bfs(){
    queue<ll> q;
    q.push(1);
    vb visited(n+1,0);
    dist[1] = 0;
    visited[1] = true;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(auto x: gr[cur]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                dist[x] = dist[cur] + 1;
            }
        }
    }
}

map<pll, bool> edges;

void dfs(ll src){
    vis[src] = true;
    dp[src] = dist[src];
    // cout<<src<<"()\n";
    for(auto x: gr[src]){
        if(!vis[x] && dist[x] > dist[src]){
            dfs(x);
        }
        if(dist[x] > dist[src]){
            dp[src] = min(dp[x],dp[src]);
        }else{
            dp[src] = min(dp[src],dist[x]);
        }
    }

}

void solve(){
    re n; re m;
    fo(n+1){
        gr[i].clear();
        dist[i] = inf;
        par_dist[i] = -1;
        vis[i] = false;
    }
    fo(m){
        re x; re y;
        gr[x].pb(y);
    }
    bfs();
    // fo(n) cout<<dist[i+1]<<" ";nl;
    dp[1] = 0;
    dfs(1);
    fo(n) cout<<min(dp[i+1],dist[i+1])<<" ";nl;
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    re t;
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
