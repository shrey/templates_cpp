

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

ll pw(ll n, ll k){
    if(k == 0) return 1;
    ll t = pw(n,k/2);
    ll ans = (t*t)%mod;
    if(k % 2) return (ans*n)%mod;
    else return ans;
}

//code starts here
const ll M = 4e5+100;
ll n,m;
vl gr[M];
vl st;
ll c[M];
vl path;
ll pos[M], sz[M] = {0};

vl lazy;
ll a[M];

void update_range(ll v, ll tl, ll tr, ll l, ll r, ll change){
    if(lazy[v] != -1){
        st[v] = lazy[v]; //change here
        if(tl != tr){
            lazy[2*v] = lazy[v]; // at times we have to do alternate i.e 1-lazy[v]
            lazy[2*v+1] = lazy[v];
        }
        lazy[v] = -1;
    }
    if(tl > r || tr < l) return;
    if((tl >= l && tr <= r) || tl == tr){
        st[v] = change; //change here in rmq to st[v] += change as only change is added to the max or min number
        if(tr != tl){
            lazy[2*v] = change;
            lazy[2*v+1] = change;
        }
        return;
    }
    ll tm = (tl + tr)/2;
    update_range(2*v,tl,tm,l,r,change);
    update_range(2*v+1,tm+1,tr,l,r,change);
    st[v] = st[2*v] | st[2*v+1]; //change here
}

void update(ll v, ll tl, ll tr, ll pos, ll change){
    if(tl == tr){
        st[v] |= change;
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm) update(2*v,tl,tm,pos,change);
    else update(2*v + 1,tm+1,tr,pos,change);
    st[v] = st[2*v] | st[2*v+1]; //change here
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0; //change here
    if(lazy[v] != -1){
        st[v] = lazy[v]; //change here
        if(tl != tr){
            lazy[2*v] = lazy[v];
            lazy[2*v+1] = lazy[v];
        }
        lazy[v] = -1;
    }
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) | query(2*v+1,tm+1,tr,l,r); // change here
}


void dfs(ll cur, ll par){
    path.pb(cur);
    sz[cur] = 1;
    pos[cur] = path.size()-1;
    update(1,0,n-1,pos[cur],pow(2,c[cur]));
    for(auto x: gr[cur]){
        if(x != par){
            dfs(x,cur);
            sz[cur] += sz[x];
        }
    }
}

void solve(){
    re n; re m;
    FOR(1,n) re c[i];
    st.resize(4*n+1);
    lazy.resize(4*n+1);
    forn(j,4*n+1) lazy[j] = -1;
    fo(n-1){
        ll x,y; re x; re y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1,0);
    // for(auto x: path) cout<<x<<" "; nl;
    // FOR(1,n) cout<<pos[i]<<" "; nl;
    // FOR(1,n) cout<<sz[i]<<" "; nl;
    while(m--){
        ll t; re t;
        if(t == 1){
            ll x,col;
            re x; re col;
            ll s = pos[x], e = pos[x]+sz[x]-1;
            update_range(1,0,n-1,s,e,pow(2,col));

            // query(1,0,n-1,pos[x],pos[x]+sz[x]-1,col);
            // update_range(1,0,n-1,pos[x],pos[x]+sz[x]-1,1,col);
        }
        else{
            ll x; re x;
            ll ans = 0;
            // cout<<pos[x]<<"()"<<pos[x]+sz[x]-1<<"\n";
            ll s = pos[x], e = pos[x]+sz[x]-1;
            ll cur = query(1,0,n-1,s,e);
            ll nw = 2;
            for(ll i = 1; i<=60; i++){
                if(cur&nw) ans++;
                nw *= 2;
            }
            cout<<ans<<"\n";
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
