
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

//code starts here

map<pll,vl> op;

bool compare(pair<pll,ll> &a, pair<pll,ll> &b){
    if(a.ff.ff == b.ff.ff){
        return a.ff.sec > b.ff.sec;
    }
    return a.ff.ff < b.ff.ff;
}

bool compare2(pair<pll,ll> &a, pair<pll,ll> &b){
    if(a.ff.ff == b.ff.ff){
        return a.ff.sec < b.ff.sec;
    }
    return a.ff.ff > b.ff.ff;
}

void solve(){
    ll n; re n;
    vector<pair<pll,ll> > a(n);
    fo(n){
        re a[i].ff.ff, re a[i].ff.sec;
        a[i].sec = i;
    }
    set<ll> s;
    vl res1(n); vl res2(n);
    // res1 -> if it's in some range
    // res2 -> if it contains some range
    fo(n){
        op[a[i].ff].pb(a[i].sec);
    }
    for(auto x: op){
        if(x.sec.size() > 1){
            for(auto idx: x.sec){
                res1[idx] = 1, res2[idx] = 1;
            }
        }
    }
    sort(all(a),compare);
    for(ll i = 0; i<n; i++){
        ll cur = a[i].ff.sec;
        ll idx = a[i].sec;
        if(res1[idx]) continue;
        if(!s.empty() && s.lower_bound(cur) != s.end()) res1[idx] = 1;
        s.insert(cur);
    }
    s.clear();
    sort(all(a),compare2);
    // for(auto x: a) cout<<x.ff.ff<<" () "<<x.ff.sec<<"\n";
    for(ll i = 0; i<n; i++){
        ll cur = a[i].ff.sec;
        ll idx = a[i].sec;
        if(res2[idx]) continue;
        if(!s.empty() && *s.begin() <= cur) res2[idx] = 1;
        s.insert(cur);
    }
    for(auto x: res2) cout<<x<<" "; nl;
    for(auto x: res1) cout<<x<<" "; nl;

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

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
