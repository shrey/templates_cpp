

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
#include<deque>


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
#define vs vector<string>
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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

//code starts here

const ll M = 3010;
ll dist[M][M] = {0},n,m;
vl gr[M];

void bfs(ll src){
    vl vis(n+1,false);
    queue<ll> q;
    q.push(src);
    vis[src] = true;
    dist[src][src] = 0;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(auto x: gr[cur]){
            if(!vis[x]){
                dist[src][x] = dist[src][cur] + 1;
                vis[x] = true;
                q.push(x);
            }
        }
    }
}

void solve(){
    re n; re m;
    fo(m){
        ll x,y; re x; re y;
        gr[x].pb(y); gr[y].pb(x);
    }
    forn(i,n+1){
        forn(j,n+1) dist[i][j] = 1e15;
    }
    for(ll i = 1; i<=n; i++){
        bfs(i);
    }

    ll s[2],t[2],l[2];
    fo(2){
        re s[i]; re t[i]; re l[i];
    }
    ll tot = 0;
    fo(2){
        if(dist[s[i]][t[i]] > l[i]){
            pr(-1);
            return;
        }
    }
    ll ans = m - dist[s[0]][t[0]] - dist[s[1]][t[1]];
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n; j++){
            ll a = min(dist[s[0]][i] + dist[t[0]][j],dist[t[0]][i] + dist[s[0]][j]);
            ll b = min(dist[s[1]][i] + dist[t[1]][j],dist[t[1]][i] + dist[s[1]][j]);
            ll cur = a + b + dist[i][j];
            if(a + dist[i][j] > l[0] || b + dist[i][j] > l[1]) continue;
            // if(m-cur == 3){
            //     cout<<a<<"()"<<b<<"()"<<dist[i][j]<<"\n";
            // }
            ans = max(ans,m-cur);
        }
    }
    pr(ans);
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
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
