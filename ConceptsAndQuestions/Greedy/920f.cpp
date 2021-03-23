

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

//code starts here

const ll M = 1e6+100;
const ll M2 = 3e5+100;
ll n,m;

ll st2[4*M2+1] = {0};
ll cnt[M] = {0};
ll st[4*M2+1] = {0};
ll a[M2];

void update(ll v, ll tl, ll tr, ll l, ll r){
    if(tl == tr){
        st[v] = cnt[st[v]]; //change here
        return;
    }
    ll tm = (tl + tr)/2;
    if(l <= tm && st2[v] > 2) update(2*v,tl,tm,l,r);
    if(r >= tm+1 && st2[v] > 2) update(2*v + 1,tm+1,tr,l,r);
    st[v] = st[2*v] + st[2*v+1]; //change here
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = st[2*v] + st[2*v+1]; // change here
}

void update2(ll v, ll tl, ll tr, ll l, ll r){
    if(tl == tr){
        st2[v] = cnt[st2[v]]; //change here
        return;
    }
    ll tm = (tl + tr)/2;
    if(l <= tm && st2[v] > 2) update2(2*v,tl,tm,l,r);
    if(r >= tm+1 && st2[v] > 2) update2(2*v + 1,tm+1,tr,l,r);
    st2[v] = max(st2[2*v] , st2[2*v+1]); //change here
}

ll query2(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return st2[v];
    ll tm = (tl + tr)/2;
    return max(query2(2*v,tl,tm,l,r), query2(2*v+1,tm+1,tr,l,r)); // change here
}

void build2(ll v, ll tl, ll tr){
    if(tl == tr){
        st2[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build2(2*v,tl,tm);
    build2(2*v+1,tm+1,tr);
    st2[v] = max(st2[2*v],st2[2*v+1]); // change here
}

ll sp[M], vis[M];

void comp(){
    for(ll i = 1; i<=1e6; i++){
        for(ll j = i; j<=1e6; j+=i){
            cnt[j]++;
        }
    }
}

void solve(){
    re n; re m;
    fo(n) re a[i];
    comp();
    build(1,0,n-1);
    build2(1,0,n-1);
    while(m--){
        ll t; re t;
        ll x,y;
        re x; re y;
        x--, y--;
        if(t == 1){
            ll mx = query2(1,0,n-1,x,y);
            if(mx > 2){
                update(1,0,n-1,x,y);
                update2(1,0,n-1,x,y);
            }
        }else{
            ll ans = query(1,0,n-1,x,y);
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


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
