

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

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};

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

ll n,m,t;
queue<pll> q;
const ll M = 1010;
ll mat[M][M];
ll op[M][M] = {0};
ll dist[M][M];
ll vis[M][M] = {0};
bool ok(ll x, ll y){
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

void bfs(){
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        forn(k,4){
            ll x = cur.ff + dx[k], y = cur.sec + dy[k];
            if(ok(x,y) && !vis[x][y]){
                dist[x][y] = dist[cur.ff][cur.sec] + 1;
                vis[x][y] = true;
                q.push(mp(x,y));
            }
        }
    }
}

void solve(){
    re n; re m; re t;
    for(ll i = 0; i<n; i++){
        string s; re s;
        for(ll j = 0; j<m; j++){
            mat[i][j] = s[j]-'0';
        }
    }
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            forn(k,4){
                ll x = i + dx[k], y = j + dy[k];
                if(ok(x,y) && mat[x][y] == mat[i][j]) op[i][j] = 1;
            }
        }
    }
    memset(dist,-1,sizeof(dist));
    forn(i,n){
        forn(j,m){
            if(op[i][j]) {
                dist[i][j] = 0, q.push(mp(i,j));
                vis[i][j] = true;
            }
            // cout<<op[i][j]<<" ";
        }
        // nl;
    }
    bfs();
    while(t--){
        ll x,y; re x; re y;
        x--, y--;
        ll p; re p;
        // cout<<dist[x][y]<<"()\n";
        if(dist[x][y] == -1){
            pr(mat[x][y]);
            // pr("here");
            continue;
        }
        if(p > dist[x][y]){
            // pr("here");
            p -= dist[x][y];
            if(p % 2) pr(1-mat[x][y]);
            else pr(mat[x][y]);
        }
        else{
            pr(mat[x][y]);
        }
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
