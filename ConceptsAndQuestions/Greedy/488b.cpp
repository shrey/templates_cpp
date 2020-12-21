

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
    return (ll) a;
}



//code starts here

ll n,m;

const ll M = 1e5+100;

struct qry{
    ll l,r,q;
};

qry op[M];
ll pre[M][31] = {0};

void comp(ll num, ll l, ll r){
    ll pos = 0;
    ll mask = 1;
    while(pos <= 30){
        if(num & mask){
            pre[l][pos] += 1;
            pre[r+1][pos] -= 1;
        }
        pos ++;
        mask *= 2;
    }
}


ll a[M];

vl st(4*M+1);

ll calc(ll i){
    ll ans = 0;
    ll cur = 1;
    for(ll b = 0; b<=30; b++){
        ans += (pre[i][b] > 0) * cur;
        cur *= 2;
    }
    return ans;
}

const ll inf = (1<<30) - 1;

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return inf;
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) & query(2*v+1,tm+1,tr,l,r); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = st[2*v] & st[2*v+1]; // change here
}

void solve(){
    re n; re m;
    fo(m){
        re op[i].l; re op[i].r; re op[i].q;
    }
    fo(m){
        comp(op[i].q,op[i].l, op[i].r);
    }
    forn(pos,31){
        for(ll i = 1; i<= n; i++){
            pre[i][pos] += pre[i-1][pos];
        }
    }
    for(ll i = 1; i<=n; i++){
        a[i] = calc(i);
    }
    build(1,1,n);
    fo(m){
        ll cur = query(1,1,n,op[i].l,op[i].r);
        if(cur != op[i].q){
            NO; return;
        }
    }
    YES;
    fo(n) cout<<a[i+1]<<" ";nl;
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
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
