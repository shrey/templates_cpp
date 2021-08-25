

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
#include <cstdlib>
#include <cstdio>
#include<stdlib.h>
#include <cerrno>
#include <ctime>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <random>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>


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
#define bct(x) __builtin_popcountll(x)
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

ll pow(ll n, ll k){
    if(k == 0) return 1;
    ll t = pow(n,k/2);
    ll ans = (t*t)%mod;
    if(k % 2) return (ans*n)%mod;
    else return ans;
}

//code starts here

const ll M = 2e5+100;
vl gr[M];
ll a[M];
ll n,q;
vl path;
ll pos[M];
ll dp[M];
ll sz[M];
ll arr[M];

vl st(4*M + 1);
vl lazy(4*M + 1,0);

void update_range(ll v, ll tl, ll tr, ll l, ll r, ll change){
    if(lazy[v] != 0){
        st[v] += (tr-tl+1) * lazy[v]; //change here
        if(tl != tr){
            lazy[2*v] += lazy[v]; // at times we have to do alternate i.e 1-lazy[v]
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(tl > r || tr < l) return;
    if((tl >= l && tr <= r) || tl == tr){
        st[v] += (tr-tl+1)*change; //change here in rmq to st[v] += change as only change is added to the max or min number
        if(tr != tl){
            lazy[2*v] += change;
            lazy[2*v+1] += change;
        }
        return;
    }
    ll tm = (tl + tr)/2;
    update_range(2*v,tl,tm,l,r,change);
    update_range(2*v+1,tm+1,tr,l,r,change);
    st[v] = st[2*v] + st[2*v+1]; //change here
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0; //change here
    if(lazy[v]){
        st[v] += (tr-tl+1)*lazy[v]; //change here
        if(tl != tr){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = arr[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = st[2*v] + st[2*v+1]; // change here for min, max, sum query
}

void dfs(ll cur, ll par, ll tot){
    dp[cur] = a[cur] + tot;
    path.pb(cur);
    sz[cur] = 1;
    pos[cur] = path.size()-1;
    for(auto x: gr[cur]){
        if(x != par){
            dfs(x,cur,dp[cur]);
            sz[cur] += sz[x];
        }
    }
}

void solve(){
    re n; re q;
    FOR(1,n) re a[i];
    fo(n-1){
        ll x,y;
        re x; re y;
        gr[x].pb(y); gr[y].pb(x);
    }
    dfs(1,0,0);
    for(ll i = 0; i<path.size(); i++){
        arr[i] = dp[path[i]];
    }
    build(1,0,n-1);
    while(q--){
        ll t; re t;
        if(t == 1){
            ll s; ll x;
            re s; re x;
            // cout<<a[s]<<"()"<<x<<"\n";
            update_range(1,0,n-1,pos[s],pos[s]+sz[s]-1,x-a[s]);
            a[s] = x;
        }else{
            ll s; re s;
            ll ans = query(1,0,n-1,pos[s],pos[s]);
            pr(ans);
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
// always check for n = 1 condition
// check loop starting and end points :(
//when dividing with mod, use mod inverse

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
