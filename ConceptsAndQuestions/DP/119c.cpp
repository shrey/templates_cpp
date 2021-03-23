

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

//code starts here

ll n,m,k;
ll dp[52][52][52][102]; // i of m, j of n, last subject chosen, number of excercises
ll a[52],b[52],c[52];
ll idx[52];

ll inf = 1e17;
vector<pair<ll,pair<pll,ll> > > op;

ll recur(ll i, ll j, ll prev, ll ext){
    if(i == m+1 && j != n) return -inf; //opt possible for reducing extra cases
    if(j == n) return dp[i][j][prev][ext] = 0;
    if(dp[i][j][prev][ext] != -1) return dp[i][j][prev][ext];
    ll ans = -inf;
    ll val = recur(i+1,j,prev,ext);
    if(val >= 0) ans = max(ans,val);
    if(prev != 0){
        if(c[i] > c[prev]){
            ll exer = a[prev] + ext;
            for(ll e = a[i]; e <= b[i]; e++){
                if(e == exer + k || e == k * (exer)){
                    ll val = recur(i+1,j+1,i,e-a[i]);
                    if(val >= 0) ans = max(ans,e + val);
                }
            }
        }
    }else{
        for(ll e = 0; e <= (b[i]-a[i]); e++){
            ll val = recur(i+1,j+1,i,e);
            if(val >= 0) ans = max(ans,a[i] + e + val);
        }
    }
    return dp[i][j][prev][ext] = ans;
}

vp res;

void track(ll i, ll j, ll prev, ll ext){
    if(i == m+1 || j == n) return;
    ll val = dp[i][j][prev][ext];
    if(dp[i+1][j][prev][ext] == val){
        track(i+1,j,prev,ext);
        return;
    }
    if(prev != 0){
        ll exer = a[prev] + ext;
        for(ll e = a[i]; e<=b[i]; e++){
            if(dp[i+1][j+1][i][e-a[i]] != -1 && (e == exer + k || e == exer * k)&& e + dp[i+1][j+1][i][e-a[i]] == val){
                res.pb(mp(idx[i],e));
                track(i+1,j+1,i,e-a[i]);
                return;
            }
        }
    }else{
        for(ll e = 0; e<=(b[i]-a[i]); e++){
            if(dp[i+1][j+1][i][e] != -1 && val == e + a[i] + dp[i+1][j+1][i][e]){
                res.pb(mp(idx[i],e + a[i]));
                track(i+1,j+1,i,e);
                return;
            }
        }
    }
}


void solve(){
    re n; re m; re k;
    memset(dp,-1,sizeof(dp));
    op.resize(m+1);
    fo(m){
        // re a[i+1]; re b[i+1]; re c[i+1];
        re op[i+1].sec.ff.ff; re op[i+1].sec.ff.sec; re op[i+1].ff;
        op[i+1].sec.sec = i+1;
    }
    sort(all(op));
    for(ll i = 1; i<=m; i++){
        a[i] = op[i].sec.ff.ff; b[i] = op[i].sec.ff.sec;
        c[i] = op[i].ff;
        idx[i] = op[i].sec.sec;
    }
    // pr("here");
    ll val = recur(1,0,0,0);
    if(val < 0){
        NO;
        // pr(val);
        return;
    }
    track(1,0,0,0);
    YES;
    for(auto p: res) cout<<p.ff<<" "<<p.sec<<"\n";
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
