

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

ll n;
const ll M = 5e5+100;
ll arr[M];
vl factors;
vl primes;
const ll P = 3180;
vb is_prime(4000,true);

void seive(){
    for(ll i = 2; i<=3180; i++){
        if(is_prime[i]){
            for(ll j = i*i; j<=P; j+=i){
                is_prime[j] = false;
            }
            primes.pb(i);
        }
    }
    // fo(primes.size()) cout<<primes[i]<<" ";nl;
}

void fact(ll num){
    for(ll i = 0; i<primes.size(); i++){
        ll cnt = 1;
        while(num>0 && num%primes[i] == 0){
            num/=primes[i];
            cnt*=primes[i];
        }
        if(cnt!=1){
            factors.pb(cnt);
        }
    }
    if(num>1) factors.pb(num);
    return;
}

void solve(){
    re n;
    fo(n) re arr[i];
    vl l1(n);
    vl l2(n);
    for(ll i = 0; i<n; i++){
        factors.clear();
        fact(arr[i]);
        if(factors.size()<=1){
            l1[i] = -1;
            l2[i] = -1;
        }
        else{
            l1[i] = factors[0];
            l2[i] = arr[i]/factors[0];
        }
    }
    fo(n) cout<<l1[i]<<" ";nl;
    fo(n) cout<<l2[i]<<" ";nl;
}

int32_t main(){
    KOBE;
    seive();
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
