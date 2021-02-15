

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

ll r,g;
const ll M = 2e5+1;
ll dp[2][M] = {0};
ll mxh;

// ll recur(ll h, ll cr){
//     if(h == mxh) return 1;
//     if(dp[h][cr] != -1) return dp[h][cr];
//     ll cg = g - (h*(h+1)/2 - (r - cr));
//     ll ans = 0;
//     if(cg >= h+1){
//         ans += recur(h+1,cr);
//     }
//     if(cr >= h+1){
//         ans += recur(h+1,cr-(h+1));
//     }
//     return dp[h][cr] = ans;
// }

void solve(){
    re r; re g;
    // memset(dp,-1,sizeof(dp));
    mxh = 0;
    while(mxh*(mxh+1)/2 <= (r+g)){
        mxh++;
    }
    mxh--;
    // pr(mxh);
    fo(M) dp[0][i] = 1;
    for(ll i = 1; i<=mxh; i++){
        ll cur = i%2;
        // ll mr = max(0ll,r - (i*(i-1))/2);
        for(ll cr = 0; cr<=r; cr++){
            dp[cur][cr] = 0;
            if(cr > i*(i+1)/2 || cr+g < i*(i+1)/2) continue;
            if(cr >= i) dp[cur][cr] += dp[1-cur][cr-i];
            dp[cur][cr] %= mod;
            ll cg = g - ((i*(i-1))/2-cr);
            if(cr <= (i*(i-1)/2)) dp[cur][cr] += dp[1-cur][cr];
            dp[cur][cr] %= mod;
        }
    }
    ll ans = 0;
    for(ll i = 0; i<=r; i++){
        ans += dp[mxh%2][i];
        ans %= mod;
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
