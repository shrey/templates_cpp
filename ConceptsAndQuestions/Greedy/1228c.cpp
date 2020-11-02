

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
#define re(x) cin>>x
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

ll n,x;

vl primes;

void fact(ll num){
    for(ll i = 2; (i*i)<=num; i++){
        if(num%i == 0){
            primes.pb(i);
            while(num>0 && num%i == 0) num/=i;
        }
    }
    if(num>1) primes.pb(num);
}

ll pow_mod(ll num, ll k){
    if(k == 0) return 1;
    ll a = pow_mod(num,k/2);
    if(k%2){
        return (num%mod * (a * a)%mod)%mod;
    }
    return ((a*a)%mod);
}

ll comp(ll cur){
    ll ans = 0;
    ll temp = cur;

    while(temp<=n){
        ans = (ans + (n/temp))%mod;
        temp = (temp*cur)%mod;
    }
    return ans;
}

void solve(){
    fact(x);
    fo(primes.size()) cout<<primes[i]<<" ";
    nl;
    ll ans = 1;
    for(ll i = 0; i<primes.size(); i++){
        ll k = comp(primes[i]);
        pr(k);
        ans = ((ans*(pow_mod(primes[i],k)))%mod);
        ans = (ans+mod)%mod;
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    re(x);
    re(n);
    pr(n);
    n%=mod;
    solve();
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
