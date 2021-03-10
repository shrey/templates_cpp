

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
ll cnt[M];
ll res[M] = {0};

void dfs1(ll cur, ll par){
    dp[cur] = 0;
    cnt[cur] = 1;
    for(auto x: gr[cur]){
        if(x == par) continue;
        dfs1(x,cur);
        cnt[cur] += cnt[x];
        dp[cur] += dp[x] + cnt[x];
    }
}

void dfs2(ll cur, ll par, ll dist){
    // cout<<cur<<"()"<<dp[cur]<<"()"<<dist<<"\n";
    res[cur] = dp[cur] + n-cnt[cur] + dist;
    dist += (n-cnt[cur]);
    ll d = dist;
    for(auto x: gr[cur]){
        if(x == par) continue;
        d += dp[x] + cnt[x];
    }
    for(auto x: gr[cur]){
        if(x == par) continue;
        dfs2(x,cur,d - (dp[x]+cnt[x]));
    }
}

void solve(){
    re n;
    fo(n-1){
        re a; re b;
        gr[a].pb(b), gr[b].pb(a);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    fo(n) cout<<res[i+1]<<" "; nl;
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
