

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

//code starts here

const ll M = 50;
const ll mx = 1e5+100;
ll mat[M][M];
ll dp[M][mx];
ll n,m,b;
ll ans = 0;

ll recur(vl &vec, bool r, ll i, ll mx, ll sm){
    if(sm == b){
        return 1;
    }
    if(i == mx || sm > b) return 0;
    if(dp[i][sm] != -1) return dp[i][sm];
    ll ans = 0;
    if(r){
        ans += recur(vec,r,i+1,mx,sm);
        ans %= mod;
        ll ns = sm;
        for(auto x: vec) ns += mat[x][i];
        ans += recur(vec,r,i+1,mx,ns);
        ans %= mod;
    }else{
        ans += recur(vec,r,i+1,mx,sm);
        ans %= mod;
        ll ns = sm;
        for(auto x: vec) ns += mat[i][x];
        ans += recur(vec,r,i+1,mx,ns);
        ans %= mod;
    }
    return dp[i][sm] = ans;
}

void solve(){
    re n; re m; re b;
    ans = 0;
    forn(i,n){
        forn(j,m) re mat[i][j];
    }
    if(n < m){
        ll op = pow(2,n);
        for(ll cb = 0; cb < op; cb++){
            memset(dp,-1,sizeof(dp));
            vl r;
            for(ll i = 0; i<n; i++){
                if((1<<i)&cb) r.pb(i);
            }
            ans += recur(r,true,0,m,0);
            ans %= mod;
        }
    }else{
        ll op = pow(2,m);
        for(ll cb = 0; cb < op; cb++){
            memset(dp,-1,sizeof(dp));
            vl c;
            for(ll i = 0; i<m; i++){
                if((1<<i)&cb) c.pb(i);
            }
            // cout<<cb<<"()"<<c.size()<<"\n";
            ans += recur(c,false,0,n,0);
            ans %= mod;
        }
    }
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
