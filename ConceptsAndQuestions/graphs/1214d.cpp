

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
vector< vl > mat;

bool ok(ll x, ll y){
    if(x >= 0 && x<n && y>=0 && y<m && mat[x][y] == 0) return true;
    return false;
}

vector<vector<bool> > bfs(ll a, ll b, ll op){
    queue< pll > q;
    q.push(mp(a,b));
    vector<vector<bool> > vis(n,vb(m,false));
    vis[a][b] = true;
    while(!q.empty()){
        pll cur = q.front();
        q.pop();
        ll x = cur.ff, y = cur.sec;
        if(ok(x+op,y) && !vis[x+op][y]){
            vis[x+op][y] = true;
            q.push(mp(x+op,y));
        }
        if(ok(x,y+op) && !vis[x][y+op]){
            vis[x][y+op] = true;
            q.push(mp(x,y+op));
        }
    }
    return vis;
}

const ll M = 1e4+100;
void solve(){
    re n; re m;
    // pr("here");
    mat.resize(n);
    fo(n) mat[i].resize(m);
    forn(i,n){
        forn(j,m){
            char ch; re ch;
            if(ch == '.'){
                mat[i][j] = 0;
            }else{
                mat[i][j] = 1;
            }
        }
    }
    // pr("here");
    vector< vb > v0 = bfs(0,0,1);
    vector< vb > vn = bfs(n-1,m-1,-1);
    // forn(i,n){
    //     forn(j,m){
    //         if(v0[i][j]) cout<<1<<" ";
    //         else cout<<0<<" ";
    //     }nl;
    // }
    if(!v0[n-1][m-1]){
        pr(0);
        return;
    }
    // pr("here");
    vp dist[n+m];
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            ll curdist = i + j;
            if(v0[i][j] && vn[i][j]) dist[curdist].pb(mp(i,j));
        }
    }
    for(ll d = 1; d<n+m-2; d++){
        if(dist[d].size() < 2){
            // cout<<dist[d][0].ff<<"()"<<dist[d][0].sec<<"\n";
            // cout<<d<<"()\n";
            pr(1);
            return;
        }
    }
    pr(2);
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
