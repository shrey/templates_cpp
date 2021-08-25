

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
#define bct(x) __builtin_popcountll(x)
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

ll pow(ll n, ll k){
    if(k == 0) return 1;
    ll t = pow(n,k/2);
    ll ans = (t*t)%mod;
    if(k % 2) return (ans*n)%mod;
    else return ans;
}

//code starts here

ll n,m,p;

const ll M = 2e5+100;
ll cnt[M] = {0};
ll tot[M] = {0};
vs a;
void solve(){
    ll res = 0;
    srand(time(NULL));
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    re n; re m; re p;
    a.resize(n+1);
    fo(n) re a[i];
    ll iter = 60;
    vl ans(m,0);
    while(iter--){
        // pr("here");
        ll idx = rng()%n;
        vl op;
        string cur = a[idx];
        fo(cur.length()){
            if(cur[i] == '1') op.pb(i);
        }
        ll totmask = (1<<((ll)op.size()));
        forn(k,totmask) cnt[k] = 0, tot[k] = 0;
        forn(i,n){
            ll curm = 0;
            forn(j,op.size()){
                if(a[i][op[j]] == '1') curm += (1ll<<j);
            }
            cnt[curm]++;
        }
        forn(msk,totmask){
            ll j = msk;
            while(j){
                tot[j] += cnt[msk];
                j = (j-1)&msk;
            }
        }
        forn(mask,totmask+1){
            if(tot[mask]*2 >= n && bct(mask) > res){
                res = bct(mask);
                vl carr(m,0);
                forn(j,op.size()){
                    if((mask>>j)&1){
                        carr[op[j]] = 1;
                    }
                }
                ans = carr;
            }
        }
    }
    for(auto x: ans) cout<<x; nl;
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
//when dividing with mod, use mod inverse

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
