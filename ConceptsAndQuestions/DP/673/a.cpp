

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
#define I long long

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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

I modex(I a,I b,I m){
  a=a%m;
  if(b==0){
    return 1;
  }
  I temp=modex(a,b/2,m);
  temp=(temp*temp)%m;
  if(b%2){
    temp=(temp*a)%m;
  }
  return temp;
}
I md(I a,I b){
    ll m = 1e9+7;
  a=a%m;
  b=b%m;
  ll c = gcd(a,b);
  a=a/c;
  b=b/c;
  c=modex(b,m-2,m);
  return (a*c)%m;
}

//code starts here

const ll M = 25;
char mat[M][M];
ll n,m,x,y;

ll extended_euclid(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modulo_inverse(ll a, ll m){
    ll x,y;
    ll g = extended_euclid(a,m,x,y);
    if(g!=1){
        return -1;
    }
    x = (x%m+m)%m;
    return x;
}

ll  mult(ll a, ll b){
    ll c = gcd(a,b);
    a /= c;
    b /= c;
    c = modulo_inverse(b,mod);
    ll ans = (a*c)%mod;
    return ans;
}


void solve(){
    re n; re m;
    forn(i,n){
        forn(j,m) re mat[i][j];
    }
    re x; re y;
    pll dp[n+1][m+1];
    forn(i,n){
        forn(j,m){
            if(mat[i][j] == 'x'){
                dp[i][j].ff = 0; dp[i][j].sec = 1;
            }
            if(mat[i][j] == '2'){
                dp[i][j].ff = 0, dp[i][j].sec = 0;
            }
        }
    }
    for(ll i = n-1; i>=0; i--){
        for(ll j = m-1; j>=0; j--){
            if(mat[i][j] == '2' || mat[i][j] == 'x') continue;
            dp[i][j].ff = md((dp[i+1][j].ff*(y-1))%mod,y) + md(dp[i][j+1].ff,y) + 1;
            dp[i][j].ff %= mod;
            dp[i][j].sec = md((dp[i+1][j].sec*(y-1))%mod,y) + md(dp[i][j+1].sec,y);
            dp[i][j].sec %= mod;
        }
    }
    ll ans = 0;
    ll tot = 0;
    forn(i,n){
        forn(j,m){
            if(mat[i][j] == '1'){
                ans += (md(dp[i][j].ff,1-dp[i][j].sec));
                ans = (ans+mod)%mod;
                tot++;
            }
        }
    }
    ans = md(ans,tot);
    ans += mod;
    ans %= mod;
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    re t;
    while(t--) solve();
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
