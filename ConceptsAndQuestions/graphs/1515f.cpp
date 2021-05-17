

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

const ll M = 3e5+100;
ll a[M],n,m,x;
set<pll> gr[M];

vl p(M,0); vl r(M,1);
vl sz(M,0);

ll getp(ll v){
    if(v == p[v]) return v;
    return p[v] = getp(p[v]);
}

void unite(ll u, ll v){
    u = getp(u), v = getp(v);
    if(u == v) return;
    if(r[u] < r[v]) swap(u,v);
    sz[u] = (sz[u]+sz[v]-x);
    r[u] += r[v];
    for(auto e: gr[v]){
        gr[u].insert(e);
    }
    p[v] = u;
}


void solve(){
    re n; re m; re x;
    fo(n) re a[i+1];
    vector<pair<pll,pll> > e;
    fo(m){
        ll x,y;
        re x; re y;
        gr[x].insert(mp(y,i+1));
        gr[y].insert(mp(x,i+1));
    }
    // sort(all(e));
    for(ll i = 1; i<=n; i++){
        p[i] = i; sz[i] = a[i];
    }
    multiset<pll,greater<pll> > st;
    for(ll i = 1; i<=n; i++){
        st.insert(mp(sz[i],i));
    }
    ll tot = 0;
    vl res;
    while(!st.empty() && res.size() < n-1){
        auto cur = *st.begin();
        st.erase(st.begin());
        while(!gr[cur.sec].empty()){
            auto neg = *gr[cur.sec].begin();
            gr[cur.sec].erase(gr[cur.sec].begin());
            if(getp(cur.sec) != getp(neg.ff)){
                ll par = getp(neg.ff);
                ll p2 = getp(cur.sec);
                if(sz[par] + sz[p2] < x) continue;
                st.erase(mp(sz[par],par));
                res.pb(neg.sec);
                unite(cur.sec,neg.ff);
                p2 = getp(cur.sec);
                st.insert(mp(sz[p2],p2));
                break;
            }
        }
    }
    if(res.size() >= n-1){
        YES;
        for(auto x: res) cout<<x<<"\n";
    }else{
        NO;
    }

}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    // re t;s
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
