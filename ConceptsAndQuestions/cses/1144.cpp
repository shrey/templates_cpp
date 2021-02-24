

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

const ll M = 1e6+100;
ll p[M],n,q;
ll a[M] = {0};

vl st(4*M + 1);

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

vl vals;
ll cc(ll num){
    ll idx = lower_bound(vals.begin(),vals.end(),num) - vals.begin();
    return idx;
}

void solve(){
    re n; re q;
    fo(n){
        re p[i];
        vals.pb(p[i]);
    }
    vector<pair<ll,pll> > qry;
    fo(q){
        char ch;
        re ch;
        ll a,b; re a; re b;
        ll x = (ch == '?');
        qry.pb(mp(x,mp(a,b)));
        if(ch == '!') vals.pb(b);
        else vals.pb(a), vals.pb(b);
    }
    sort(all(vals));
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    fo(n){
        update(1,0,M-1,cc(p[i]),1);
    }
    fo(q){
        if(qry[i].ff == 1){
            ll a = cc(qry[i].sec.ff), b = cc(qry[i].sec.sec);
            // cout<<a<<"()"<<b<<"\n";
            ll ans = query(1,0,M-1,a,b);
            pr(ans);
        }else{
            ll pos = qry[i].sec.ff;
            ll val = cc(qry[i].sec.sec);
            ll curval = cc(p[pos-1]);
            // cout<<val<<"(())\n";
            p[pos-1] = qry[i].sec.sec;
            update(1,0,M-1,curval,-1);
            update(1,0,M-1,val,+1);
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
