

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

const ll M = 2e5+100;
vl gr[M];
ll n,m,a,b,c;

vl bfs(ll src){
    vl dist(n+1,-1);
    dist[src] = 0;
    queue<ll> q;
    q.push(src);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(auto x: gr[cur]){
            if(dist[x] == -1){
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
    }
    return dist;
}

void solve(){
    re n; re m; re a; re b; re c;
    ll e[m];
    fo(m) re e[i];
    fo(m){
        ll x,y; re x; re y;
        gr[x].pb(y); gr[y].pb(x);
    }
    sort(e,e+m);
    ll pre[m];
    pre[0] = e[0];
    for(ll i = 1; i<m; i++) pre[i] = pre[i-1] + e[i];
    vl dist[3];
    dist[0] = bfs(a);
    dist[1] = bfs(b);
    dist[2] = bfs(c);
    // fo(3){
    //     forn(j,n) cout<<dist[i][j+1]<<" "; nl;
    // }
    // fo(m) cout<<e[i]<<" "; nl;
    // fo(m) cout<<pre[i]<<" "; nl;
    ll ans = 1e15;
    for(ll i = 1; i<=n; i++){
        ll op = dist[0][i] + dist[1][i] + dist[2][i];
        if(op > m) continue;
        ll cur = 0;
        if(op > 0) cur += pre[op-1];
        if(dist[1][i] > 0) cur += pre[dist[1][i]-1];
        // cout<<i<<"()"<<dist[1][i]<<"\n";
        ans = min(ans,cur);
    }
    pr(ans);
    for(ll i = 1; i<=n; i++){
        gr[i].clear();
    }
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
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
