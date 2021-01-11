

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
    return (ll) a;
}



//code starts here

ll n,m,T,x,y,w;
const ll M = 5010;
vp gr[M];
ll dp[M][M]; //min time required from i to n using k edges
ll inf = 1e15;
vl res;

ll dfs(ll cur, ll cnt){
    if(cur == n && cnt == 1) return 0;
    if(cur == n || cnt <= 1) return inf;
    if(dp[cur][cnt] != -1) return dp[cur][cnt];
    // cout<<cur<<" , "<<cnt<<" = "<<"\n";
    ll ans = inf;
    for(auto x: gr[cur]){
        ll t = dfs(x.ff,cnt-1);
        if(t != inf) ans = min(ans,t + x.sec);
    }
    return dp[cur][cnt] = ans;
}

void dfs2(ll cur, ll cnt){
    if(cur == n){
        // res.pb(n);
        return;
    }
    ll mn = inf;
    ll idx = -1;
    for(auto x: gr[cur]){
        if(dp[x.ff][cnt-1] != -1 && dp[x.ff][cnt-1] + x.sec == dp[cur][cnt]){
            res.pb(x.ff);
            dfs2(x.ff,cnt-1);
            return;
        }
    }
    // if(idx == -1){
    //     cout<<cur<<"()"<<cnt<<"\n";
    //     return;
    // }
    // res.pb(idx);
    // dfs2(idx,cnt-1);
}

void solve(){
    re n; re m; re T;
    // memset(dp,inf,sizeof(dp));
    forn(i,M){
        forn(j,M)dp[i][j] = -1;
    }
    dp[n][1] = 0;
    fo(m){
        re x; re y; re w;
        gr[x].pb(mp(y,w));
    }
    ll ans = 0;
    for(ll i = 1; i<=n; i++){
        ll t = dfs(1,i);
        // cout<<i<<" , "<<t<<"\n";
        if(t <= T){
            ans = i;
        }
    }
    pr(ans);
    res.pb(1);
    dfs2(1,ans);
    for(auto x: res) cout<<x<<" ";nl;
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
