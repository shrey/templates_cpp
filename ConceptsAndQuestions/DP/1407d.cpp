

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

const ll M = 3e5+100;
ll a[M],n;
vl gr[M];

vp st(4*M + 1);
vp st1(4*M + 1);
ll dist[M] = {0};
bool vis[M] = {false};

pll rless[M],rmore[M];

pll f(pll a, pll b){
    return min(a,b);
}


pll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return mp(1e15,1e15); //change here
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return f(query(2*v,tl,tm,l,r),query(2*v+1,tm+1,tr,l,r)); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = rless[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = f(st[2*v] , st[2*v+1]); // change here
}

pll query1(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return mp(1e15,1e15); //change here
    if(tl >= l && tr <= r) return st1[v];
    ll tm = (tl + tr)/2;
    return f(query1(2*v,tl,tm,l,r),query1(2*v+1,tm+1,tr,l,r)); // change here
}

void build1(ll v, ll tl, ll tr){
    if(tl == tr){
        st1[v] = rmore[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build1(2*v,tl,tm);
    build1(2*v+1,tm+1,tr);
    st1[v] = f(st1[2*v] , st1[2*v+1]); // change here
}

void solve(){
    re n; fo(n) re a[i+1];
    for(ll i = 0; i<=4*n+1; i++){
        pll op = mp(1e15,1e15);
        st[i] = st1[i] = op;
    }
    multiset<pll> m1;
    multiset<pll,greater<pll> > m2;
    m1.insert(mp(a[1],1));
    m2.insert(mp(a[1],1));
    ll less[n+1], more[n+1];
    fo(n+1){
        less[i] = -1, more[i] = -1;
        rless[i]= mp(-1,i), rmore[i] = mp(-1,i);
    }
    for(ll i = 2; i<=n; i++){
        while(!m1.empty() && a[i] >= (*m1.begin()).ff){
            auto cur = *m1.begin();
            less[cur.sec] = i;
            m1.erase(m1.begin());
        }
        while(!m2.empty() && a[i] <= (*m2.begin()).ff){
            auto cur = *m2.begin();
            more[cur.sec] = i;
            m2.erase(m2.begin());
        }
        m1.insert(mp(a[i],i));
        m2.insert(mp(a[i],i));

    }
    m1.clear(); m2.clear();
    m1.insert(mp(a[n],n));
    m2.insert(mp(a[n],n));
    // pr("here");
    for(ll i = n-1; i>=1; i--){
        while(!m1.empty() && a[i] >= (*m1.begin()).ff){
            auto cur = *m1.begin();
            rless[cur.sec] = mp(i,cur.sec);
            m1.erase(m1.begin());
        }
        while(!m2.empty() && a[i] <= (*m2.begin()).ff){
            auto cur = *m2.begin();
            rmore[cur.sec] = mp(i,cur.sec);
            m2.erase(m2.begin());
        }
        m1.insert(mp(a[i],i));
        m2.insert(mp(a[i],i));
    }
    // build(1,1,n);
    // build1(1,1,n);
    for(ll i = 1; i<=n; i++){
        if(more[i] != -1)gr[i].pb(more[i]);
        if(less[i] != -1) gr[i].pb(less[i]);
        if(rless[i].ff != -1) gr[rless[i].ff].pb(i);
        if(rmore[i].ff != -1) gr[rmore[i].ff].pb(i);
        // if(i == n){
            // cout<<rmore[i].ff<<"()"<<rless[i].ff<<"\n";
        // }
    }
    // for(ll i = 1; i<=n; i++){
    //     cout<<more[i]<<" , "<<rmore[i].ff<<"\n";
    // }
    for(ll i = 1; i<=n-1; i++) gr[i].pb(i+1);
    queue<ll> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        ll cur = q.front();
        // cout<<cur<<"()\n";s
        q.pop();
        for(auto x: gr[cur]){
            if(!vis[x]){
                dist[x] = dist[cur] + 1;
                vis[x] = true;
                q.push(x);
            }
        }
    }
    pr(dist[n]);
    // for(ll i = 1; i<=n; i++){
    //     cout<<more[i]<<" ";
    // }
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

/*
8
1 9 8 7 6 2 1 1 4
*/