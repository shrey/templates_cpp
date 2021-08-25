

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

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

ll mod = 998244353;

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

ll modex(ll a,ll b,ll m){ //used to calculate a^-1
    a=a%m;
    if(b==0){
        return 1;
    }
    ll temp=modex(a,b/2,m);
    temp=(temp*temp)%m;
    if(b%2){
        temp=(temp*a)%m;
    }
    return temp;
}

ll modinv(ll a, ll m){
    return modex(a,m-2,m);
}

ll n; ll m;

void solve(){
    re n; re m;
    ll mat[n][m];
    forn(i,n) forn(j,m) re mat[i][j];
    ll fact = 1;
    for(ll i = 2; i<=n; i++){
        fact = fact*i;
        fact %= mod;
    }
    ll tot = 0;
    for(ll i = 0; i<m; i++){
        vl cur;
        forn(j,n) cur.pb(mat[j][i]);
        sort(all(cur));
        ll op = fact;
        ll ls = 1;
        for(ll j = 0; j<cur.size(); j++){
            ls *= (cur[j]-j-1);
            ls %= mod;
        }
        op = (op-ls+mod)%mod;
        tot += op;
        tot %= mod;
    }
    ll ans = (tot * modinv(fact,mod))%mod;
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
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
