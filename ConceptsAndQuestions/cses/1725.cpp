

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
#include<deque>
#include <cstdlib>
#include <cstdio>
#include<stdlib.h>
#include <cerrno>
#include <ctime>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <random>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>


using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define prDouble(x) cout<<fixed<<setprecision(6)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define sec second
#define bct(x) __builtin_popcountll(x)
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
#define vs vector<string>
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
#define INF 1e18
#define p 1000000007

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

const ll mod = 1e9 + 7;

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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

ll pw(ll n, ll k){
    if(k == 0) return 1;
    ll t = pw(n,k/2);
    ll ans = (t*t)%mod;
    if(k % 2) return (ans*n)%mod;
    else return ans;
}

//code starts here

ll fac[1000010];

ll power(ll x, ll y )
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


ll modInverse(ll n )
{
    return power(n, p-2);
}


ll ncr(ll n,ll r )
{
   if (r==0||r==n)
      return 1;
    return (fac[n]* modInverse(fac[r]) % p *
            modInverse(fac[n-r]) % p) % p;
}

void compute(){
    fac[0] = 1;
    for (ll i=1 ; i<1000010; i++)
        fac[i] = fac[i-1]*i%p;
}

ld dp[1000][1000];

ld recur(ll n, ll sm){
    if(n == 0 && sm == 0) return 1.0;
    if(n == 0) return 0.0;
    if(sm == 0) return 0.0;
    if(dp[n][sm] != -1.0) return dp[n][sm];
    // cout<<n<<"()"<<sm<<"\n";
    ld ans = 0;
    for(ll i = 1; i<=6; i++){
        ans += ((ld)recur(n-1,sm-i)/6.0);
    }
    return dp[n][sm] = ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    for(ll i = 0; i<1000; i++){
        for(ll j = 0; j<1000; j++) dp[i][j] = -1.0;
    }
    ld tot = 0;
    ll n,a,b;
    re n; re a; re b;
    for(ll i = a; i<=b; i++){
        tot += (ld)recur(n,i);
    }
    prDouble(tot); nl;
}

int32_t main(){
    KOBE;
    compute();
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
// always check for n = 1 condition
// check loop starting and end points :(
//when dividing with mod, use mod inverse

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
