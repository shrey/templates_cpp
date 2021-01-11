

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

ll n;
const ll M = 1010;
ll a[M];
ll dp[M][M];
const ll inf = 1e15;

ll recur(ll pos, ll idx){
    if(pos >= n) return dp[pos][idx] = 0;
    if(idx >= n) return dp[pos][idx] = a[pos];
    if(dp[pos][idx] != -1) return dp[pos][idx];
    ll ans = inf;
    // ans = min(ans,a[pos] + recur(idx,idx+1));
    ans = min(ans,max(a[pos],a[idx]) + recur(idx+1,idx+2));
    if(idx < n-1) ans = min(ans,max(a[pos],a[idx+1]) + recur(idx,idx + 2));
    if(idx < n-1) ans = min(ans,max(a[idx],a[idx+1]) + recur(pos,idx+2));
    return dp[pos][idx] = ans;
}

vp res;


ll dir[] = {-1,0,1};

void path(ll pos, ll idx){
    if(pos >= n) return;
    if(idx >= n) {
        res.pb(mp(pos,-1));
        return;
    }
    // cout<<pos<<"()"<<idx<<"\n";
    ll dist[3];
    dist[0] = (idx < n-1) ? max(a[idx],a[idx+1]) + dp[pos][idx+2] : inf;
    dist[1] = max(a[pos],a[idx]) + dp[idx+1][idx+2];
    dist[2] = (idx < n-1) ? dp[idx][idx+2] + max(a[pos],a[idx+1]) : inf;
    // if(pos == 0) cout<<dist[0]<<" , "<<dist[1]<<" , "<<dist[2]<<"\n";
    ll ans = min(dist[0],min(dist[1],dist[2]));
    fo(3){
        if(dist[i] == ans){
            if(i == 0){
                res.pb(mp(idx,idx+1));
                path(pos,idx+2);
            }
            else if(i == 1){
                res.pb(mp(pos,idx));
                path(idx+1,idx+2);
            }
            else{
                res.pb(mp(pos,idx+1));
                path(idx,idx+2);
            }
            break;
        }
    }
}

void solve(){
    re n;
    fo(n) re a[i];
    memset(dp,-1,sizeof(dp));
    pr(recur(0,1));
    path(0,1);
    for(auto x: res){
        cout<<x.ff+1<<" ";
        if(x.sec != -1) cout<<x.sec+1;
        nl;
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
