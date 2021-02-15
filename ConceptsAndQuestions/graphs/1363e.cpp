

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
ll n;
ll a[M],b[M],c[M];
vl gr[M];
ll ans = 0;
pll dfs(ll cur, ll par, ll mn){
    // cout<<cur<<"()"<<par<<"()"<<mn<<"\n";
    ll c1 = 0, c2 = 0;
    pll p = mp(0,0);
    if(b[cur] != c[cur]){
        if(b[cur] == 0) p.ff++;
        else p.sec++;
    }

    for(auto x: gr[cur]){
        if(x == par) continue;
        pll t = dfs(x,cur,min(mn,a[cur]));
        p.ff += t.ff;
        p.sec += t.sec;
    }
    if(a[cur] < mn){
        ll op = min(p.ff,p.sec);
        p.ff -= op, p.sec -= op;
        ans += 2*op*a[cur];
    }
    // cout<<cur<<"()"<<p.ff<<"()"<<p.sec<<"\n";
    return p;
}


void solve(){
    re n;
    fo(n){
        re a[i+1]; re b[i+1]; re c[i+1];
    }
    fo(n-1){
        ll x,y; re x; re y;
        gr[x].pb(y); gr[y].pb(x);
    }
    ll inf = 1e15;
    pll cur = dfs(1,0,inf);
    if(cur.ff || cur.sec){
        pr(-1);
        return;
    }
    pr(ans);
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
