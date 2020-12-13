

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

ll mod = 1e9 + 7;
const ll p = 998244353;

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

const ll M = 1e6+100;

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

void solve(){
    ll n,k; re n; re k;
    map<ll,vl> event;
    fo(n){
        ll l,r; re l; re r;
        event[l].pb(1); event[r+1].pb(-1);
    }
    ll ans = 0;
    ll active = 0;
    for(auto it: event){
        ll cnt = 0;
        for(auto nw: it.sec){
            if(nw == 1){
                cnt++;
            }else{
                active--;
            }
        }
        for(ll i = 1; i<=min(k,cnt); i++){
            if(active<k-i) continue;
            ll cur = ncr(cnt,i) * ncr(active,k-i);
            cur %= p;
            ans += cur;
            ans %= p;
        }
        active += cnt;
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    fac[0] = 1;
    for (ll i=1 ; i<1000010; i++)
        fac[i] = fac[i-1]*i%p;
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
// try to find repeating pattern in matrices
