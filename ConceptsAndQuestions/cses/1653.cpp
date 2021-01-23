

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

const ll M = 2e6+100;
pll dp[M];
bool vis[M] = {false};
ll n,x;
ll w[30];
ll mx;
const ll inf = 1e15;

pll mn(pll &a, pll &b){
    if(a.ff < b.ff) return a;
    else if(b.ff < a.ff) return b;
    else{
        return (a.sec < b.sec)? a : b;
    }
}

ll cnt = 0;

pll recur(ll mask){
    // cnt++;
    // if(cnt > 20) return mp(0,0);
    if(mask == mx) return mp(1,0);
    if(vis[mask]) return dp[mask];
    vis[mask] = true;
    // cout<<mask<<"()\n";
    pll ans = mp(inf,inf);
    for(ll i = 0; i<n; i++){
        if(((1<<i)&mask) == 0){
            ll cmask = mask + (1<<i);
            pll opt = recur(cmask);
            ll sz = opt.ff;
            if(opt.sec + w[i] > x){
                opt.ff++;
                opt.sec = w[i];
            }
            else opt.sec += w[i];
            ans = mn(ans,opt);
        }
    }
    return dp[mask] = ans;
}


void solve(){
    re n; re x;
    fo(n) re w[i];
    mx = (1<<n) - 1;
    // memset(dp,-1,sizeof(dp));
    sort(w,w+n,greater<ll>());
    // fo(n) cout<<w[i]<<" ";nl;
    pr(recur(0).ff);
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
