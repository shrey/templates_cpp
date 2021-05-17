

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

ll n,m;

vector<pair<pll,ll> > a;
vp crd;
vp b;

bool compare(pair<pll,ll> &x, pair<pll,ll>&y){
    return x.ff.sec < y.ff.sec;
}

void solve(){
    re n; re m;
    a.resize(n-1);
    crd.resize(n);
    fo(n){
        re crd[i].ff, re crd[i].sec;
        if(i == 0) continue;
        a[i-1].ff.ff = crd[i].ff - crd[i-1].sec; a[i-1].ff.sec = crd[i].sec - crd[i-1].ff;
        a[i-1].sec = i-1;
    }
    // pr("here");
    b.resize(m);
    multiset<pair<ll,ll> > s;
    fo(m){
        re b[i].ff; b[i].sec = i;
        s.insert(b[i]);
    }
    sort(all(a),compare);
    // pr("here");
    vl res(n-1);
    for(auto x: a){
        cout<<x.ff.ff<<"()"<<x.ff.sec<<"\n";
        auto it = s.lower_bound(mp(x.ff.ff,-1));
        if(it == s.end()){
            No;
            return;
        }
        res[x.sec] = it->sec;
        s.erase(it);
    }
    Yes;
    fo(n-1) cout<<res[i]+1<<" "; nl;
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
