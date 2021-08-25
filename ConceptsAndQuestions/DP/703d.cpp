

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
#define INF 1e18

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

const ll M = 1e6+100;
ll a[M];
ll n;
map<ll,ll> op;

struct node{
    ll l,r,idx;
};

bool comp(node &a, node &b){
    if(a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}

vl st(4*M + 1);

void update(ll v, ll tl, ll tr, ll pos, ll change){
    if(tl == tr){
        st[v] = change; //change here
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm) update(2*v,tl,tm,pos,change);
    else update(2*v + 1,tm+1,tr,pos,change);
    st[v] = st[2*v] ^ st[2*v+1]; //change here
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0; //change here
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) ^ query(2*v+1,tm+1,tr,l,r); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = st[2*v] ^ st[2*v+1]; // change here
}


void solve(){
    re n; fo(n) re a[i+1];
    ll m; re m;
    vector<node> q(m);
    fo(m){
        re q[i].l; re q[i].r; q[i].idx = i;
    }
    sort(all(q),comp);
    ll pre[n+1];
    pre[0] = 0;
    for(ll i = 1; i<=n; i++){
        pre[i] = a[i];
        pre[i] ^= pre[i-1];
    }
    ll r = 0;
    ll xr[m+1];
    ll res[m];
    // pr("here");
    // fo(n) cout<<pre[i]<<" "; nl;
    fo(m){
        while(r < q[i].r){
            r++;
            if(op[a[r]]){
                update(1,1,n,op[a[r]],0);
            }
            op[a[r]] = r;
            update(1,1,n,r,a[r]);
        }
        ll nw = query(1,1,n,q[i].l, q[i].r);
        ll ans = pre[q[i].r]^nw;
        // cout<<i<<"()"<<pre[q[i].r]<<"\n";
        ans ^= pre[q[i].l-1];
        res[q[i].idx] = ans;
    }
    fo(m) cout<<res[i]<<"\n";
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
