

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
vl gr[M];
ll n,a,b;

ll dp[M];

void dfs1(ll cur, ll par){
    dp[cur] = 0;
    for(auto x: gr[cur]){
        if(x == par) continue;
        dfs1(x,cur);
        dp[cur] = max(dp[cur],dp[x]+1);
    }
}

ll res[M];

void dfs2(ll cur, ll par, ll mx){
    // cout<<cur<<"()"<<par<<"()"<<mx<<"\n";
    res[cur] = max(mx,dp[cur]);
    multiset<ll, greater<ll> > m;
    for(auto x: gr[cur]){
        if(x == par) continue;
        m.insert(dp[x]+1);
    }
    // if(cur == 1) cout<<*m.begin()<<"()()\n";
    if(m.empty()) return;
    auto it = m.begin();
    ll n1 = *m.begin(),n2;
    if(m.size() == 1){
        n2 = mx;
    }
    else{
        auto it2 = ++it; n2 = *it2;
    }
    for(auto x: gr[cur]){
        if(x == par) continue;
        if(dp[x]+1 == n1){
            dfs2(x,cur,max(mx+1,n2+1));
        }else{
            dfs2(x,cur,max(mx+1,n1+1));
        }
    }
}

void solve(){
    re n;
    fo(n-1){
        re a; re b;
        gr[a].pb(b); gr[b].pb(a);
    }
    dfs1(1,0);
    // fo(n) cout<<dp[i+1]<<" "; nl;
    dfs2(1,0,0);
    for(ll i = 1; i<=n; i++) cout<<res[i]<<" "; nl;
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
