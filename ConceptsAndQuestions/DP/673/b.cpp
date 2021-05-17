

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

const ll M = 1e5+100;
ll n,m,a[M],pt[M];
vl gr[M];
vp p[M];
multiset< pll > st1;
vl fin[M];
ll sz[M] = {0};
vl path;
ll res[M] = {0};

vl st(4*M + 1,0);

void update(ll v, ll tl, ll tr, ll pos, ll change){
    if(tl == tr){
        st[v] += change; //change here
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm) update(2*v,tl,tm,pos,change);
    else update(2*v + 1,tm+1,tr,pos,change);
    st[v] = st[2*v] + st[2*v+1]; //change here
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0; //change here
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r); // change here
}


void dfs(ll cur, ll par){
    sz[cur] = 1;
    st1.insert(mp(a[cur],cur));
    for(auto x: p[cur]){
        auto it = st1.upper_bound(mp(x.sec,1e15));
        if(it == st1.begin()){
            continue;
        }
        --it;
        fin[(*it).sec].pb(x.ff);
    }
    for(auto x: gr[cur]){
        if(x != par){
            dfs(x,cur);
        }
    }
    st1.erase(st1.find(mp(a[cur],cur)));
}

void dfs2(ll cur, ll par){
    for(auto x: fin[cur]){
        update(1,0,M-1,x,1);
    }
    res[cur] += query(1,0,M-1,0,a[cur]);
    for(auto x: gr[cur]){
        if(x != par){
            dfs2(x,cur);
        }
    }
    for(auto x: fin[cur]){
        update(1,0,M-1,x,-1);
    }
}


void solve(){
    re n; re m;
    ll r;
    FOR(1,n){
        re a[i];
        re pt[i];
        if(pt[i] == i){
            r = i;
            continue;
        }
        gr[pt[i]].pb(i);
        gr[i].pb(pt[i]);
    }
    fo(m){
        ll o,l,r;
        re o; re l; re r;
        p[o].pb(mp(l,r));
    }
    dfs(r,0);
    dfs2(r,0);
    for(ll i = 1; i<=n; i++) cout<<res[i]<<" "; nl;
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
