

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

ll n,m,x,y;
const ll M = 2e5+100;
vl gr[M];


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

bool vis[M] = {false};

// ll dfs(ll cur){
//     ll ans = 1;
//     for(auto x: gr[cur]){
//         if(!vis[x]) ans += dfs(x);
//     }
//     return ans;
// }

void solve(){
    re n; re m;
    for(ll i = 1; i<=n; i++) p[i] = i;
    multiset<ll,greater<ll> > s;
    fo(n) s.insert(1);

    fo(m){
        re x; re y;
        ll pa = getp(x), pb = getp(y);
        if(pa != pb){
            s.erase(s.find(r[pa]));
            s.erase(s.find(r[pb]));
            unite(x,y);
            s.insert(r[getp(x)]);
        }
        cout<<s.size()<<" "<<*s.begin()<<"\n";
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