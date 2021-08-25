

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
const ll M = 2e5+100;

struct node{
    ll pre,suff,tot, sm;
};

ll n,m,a[M];

vector<node> st(4*M + 1);

node f(node a, node b){
    node res;
    res.pre = res.suff = res.tot = 0;
    res.pre = (res.pre,max(a.pre,a.sm + b.pre));
    res.suff = max(res.suff,max(a.suff + b.sm, b.suff));
    res.tot = max(a.tot,b.tot);
    res.tot = max(res.tot,a.suff + b.pre);
    res.tot = max(res.tot,max(res.pre,res.suff));
    res.tot = max(res.tot,max(res.pre,res.suff));
    res.sm = a.sm + b.sm;
    return res;
}

node emp;


void update(ll v, ll tl, ll tr, ll pos, ll change){
    if(tl == tr){
        a[tl] = change;
        st[v].pre = max(0ll,a[tl]);
        st[v].suff = max(0ll,a[tl]);
        st[v].tot = max(0ll,a[tl]);
        st[v].sm = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm) update(2*v,tl,tm,pos,change);
    else update(2*v + 1,tm+1,tr,pos,change);
    st[v] = f(st[2*v],st[2*v+1]); //change here
}

node query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return emp; //change here
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return f(query(1,tl,tm,l,r),query(1,tm+1,tr,l,r)); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v].pre = max(0ll,a[tl]);
        st[v].suff = max(0ll,a[tl]);
        st[v].tot = max(0ll,a[tl]);
        st[v].sm = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = f(st[2*v],st[2*v+1]); // change here
}

void solve(){
    re n; re m;
    fo(n) re a[i];
    emp.pre = emp.suff = emp.tot = 0;
    build(1,0,n-1);
    // node cur = query(1,0,n-1,0,n-1);
    // cout<<cur.tot<<"\n";
    while(m--){
        ll pos,val;
        re pos; re val;
        pos--;
        update(1,0,n-1,pos,val);
        node cur = query(1,0,n-1,0,n-1);
        cout<<cur.tot<<"\n";
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
