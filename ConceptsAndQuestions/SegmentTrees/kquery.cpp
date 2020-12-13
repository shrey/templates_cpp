

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

const ll M = 3e5+100;
ll n,q,arr[M];
// vp op(M);
vl st(4*M);
vl b(M,1);
struct node{
    ll s,e,k;
    ll idx;
};

node qry[M];

bool compare(node &a, node &b){
    return (a.k<b.k);
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = b[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = st[2*v] + st[2*v+1];
}

void update(ll v, ll tl, ll tr, ll pos){
    if(tl == tr) st[v] = 0;
    else{
        ll tm = (tl + tr)/2;
        if(pos <= tm) update(2*v,tl,tm,pos);
        else update(2*v+1,tm+1,tr,pos);
        st[v] = st[2*v] + st[2*v+1];
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r){
    if(tr<l || tl > r) return 0;
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return sum(2*v,tl,tm,l,r) + sum(2*v+1,tm+1,tr,l,r);
}

void solve(){
    re n;
    vp op(n);
    fo(n){
        re op[i].ff;
        op[i].sec = i;
    }
    re q;
    fo(q){
        re qry[i].s; re qry[i].e; re qry[i].k;
        qry[i].idx = i;
    }
    ll ans[q+1];
    sort(op.begin(),op.end());
    sort(qry,qry+q,compare);
    // fo(q){
    //     cout<<qry[i].k<<"()"<<qry[i].s<<"()"<<qry[i].idx<<"\n";
    // }
    build(1,0,n-1);
    ll po = 0;
    fo(q){
        ll x = qry[i].k;
        while(po < n && op[po].ff <= x){
            update(1,0,n-1,op[po].sec);
            po++;
        }
        ans[qry[i].idx] = sum(1,0,n-1,qry[i].s-1,qry[i].e-1);
    }
    fo(q) pr(ans[i]);

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
