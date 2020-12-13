

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

string s1,s2;
ll n,m;
const ll inf = 1e15;
ll dp[5010][5010] = {0};
// ll recur(ll i, ll j){
//     if(i == n && j == m) return 0;
//     if(i == n || j == m) return inf;
//     ll ans = inf;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s1[i] == s2[j]){
//         ans = min(ans,recur(i+1,j+1));
//     }
//     else{
//         ans = min(ans,1+recur(i+1,j+1));
//     }
//     ans = min(ans,1 + recur(i+1,j));
//     ans = min(ans,1 + recur(i,j+1));
//     return dp[i][j] = ans;
// }

void solve(){
    re s1; re s2;
    n = s1.length();
    m = s2.length();
    for(ll i = 0; i<=n; i++){
        for(ll j = 0; j<=m; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else{
                dp[i][j] = min(1 + dp[i-1][j],min(1 + dp[i][j-1],dp[i-1][j-1] + (s1[i-1] != s2[j-1])));
            }
        }
    }
    pr(dp[n][m]);
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
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
