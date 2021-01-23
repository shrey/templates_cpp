

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

ld dp[1010];
ll n;
vector<pair<pair<ll,ld> , pll > > op;

ld d(ll x1, ll y1, ll x2, ll y2){
    ld cur = (x1-x2) * (x1-x2) + (y1 - y2) * (y1-y2);
    return sqrt(cur);
}

// ld recur(ll i, ll prev){
//     if(i == n) return 0.0;
//     if(dp[i][prev] != -1.0) return dp[i][prev];
//     ll x1 = op[prev].sec.ff, y1 = op[prev].sec.sec, t1 = op[prev].ff.ff;
//     ll x2 = op[i].sec.ff, y2 = op[i].sec.sec, t2 = op[i].ff.ff;
//     ld tme = t2 - t1;
//     ld need = d(x1,y1,x2,y2);
//     ld ans = 0;
//     if(tme >= need){
//         ans = op[i].ff.sec + recur(i+1,i);
//     }
//     ans = max(ans,recur(i+1,prev));
//     return dp[i][prev] = ans;
// }

bool compare(pair<pair<ll,ld>, pll > &a, pair<pair<ll,ld> , pll > &b){
    return a.ff.ff<b.ff.ff;
}


void solve(){
    re n;
    op.resize(n);
    fo(n){
        re op[i].sec.ff; re op[i].sec.sec; re op[i].ff.ff; re op[i].ff.sec;
    }
    sort(op.begin(),op.end(),compare);
    forn(i,1000) dp[i] = 0.0;
    ld ans = 0.0;
    for(ll i = 0; i<n; i++){
        dp[i] = op[i].ff.sec;
        for(ll j = 0; j<i; j++){
            ld need = d(op[i].sec.ff,op[i].sec.sec,op[j].sec.ff,op[j].sec.sec);
            ld tme = op[i].ff.ff - op[j].ff.ff;
            if(tme >= need){
                dp[i] = max(dp[j] + op[i].ff.sec,dp[i]);
            }
        }
        ans = max(ans,dp[i]);
    }
    prDouble(ans); nl;
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
