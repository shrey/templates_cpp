

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
#define vi vector<ll>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define ll long long
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

ll n,q,x,y;
const ll M = 2e5 + 5; const ll mxe = 30;
vl gr[M];
ll up[M][mxe];
bool vis[M];

void dfs(ll cur, ll p) { // keep track of current node and its parent node
    up[cur][0] = p; // mark the parent in the array
    vis[cur] = 1; // mark the node as visited
    for(ll x: gr[cur]) if(!vis[x]) dfs(x,cur); // visit all unvisited children
}

void solve(){
    //take the input
    re n; re q;
    memset(up,-1,sizeof(up));
    for(ll i = 2; i<=n; i++){
        // re x; re y;
        // gr[x].pb(y);
        // gr[y].pb(x);
        re up[i+1][0]; //did this for a qn, change it to take edge input
    }
    // dfs(1,-1); //use it when performing on normal graph
    for(ll l = 1; l<mxe; l++){
        for(ll i = 1; i<=n; i++){
            if(up[i][l-1] != -1) up[i][l] = up[up[i][l-1]][l-1];
        }
    }
    fo(q){
        ll k;
        re x; re k;
        for(ll l = 0; l<mxe; l++){
            if(x != -1 && (k & (1<<l))){
                x = up[x][l];
            }
        }
        pr(x);
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
