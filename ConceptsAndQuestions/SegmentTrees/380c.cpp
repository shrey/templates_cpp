

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

const ll M = 1e6+100;
vl o(4*M);
vl c(4*M);
vl t(4*M);

class node{
    public:
    ll open,close,tot;
    node(){
        open = 0, close = 0, tot = 0;
    }
};

node merge(node &a, node &b){
    ll temp = min(a.open,b.close);
    node cur;
    cur.tot = a.tot + b.tot + temp;
    cur.open = a.open + b.open - temp;
    cur.close = a.close + b.close - temp;
    return cur;
}
string s;

node st[4*M];

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        if(s[tl] == '(') st[v].open = 1;
        else st[v].close = 1;
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = merge(st[2*v],st[2*v+1]);
    return;
    // cout<<tl<<"()"<<tr<<" = "<<t[v]<<"\n";
}

node query(ll v, ll tl, ll tr, ll l, ll r){
    if(tr < l || tl > r){
        node nn;
        return nn;
    }
    if(tl >= l && tr <= r){
        return st[v];
    }
    ll tm = (tl + tr)/2;
    node n1 = query(2*v,tl,tm,l,r);
    node n2 = query(2*v+1,tm+1,tr,l,r);
    node cur = merge(n1,n2);
    return cur;
}

void solve(){
    re s;
    ll m; re m;
    ll n = s.length();
    build(1,0,n-1);
    while(m--){
        ll l,r;
        re l; re r;
        pr(query(1,0,n-1,l-1,r-1).tot*2);
    }
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
