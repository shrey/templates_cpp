

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

ll pw(ll n, ll k){
    if(k == 0) return 1;
    ll t = pw(n,k/2);
    ll ans = (t*t)%mod;
    if(k % 2) return (ans*n)%mod;
    else return ans;
}

//code starts here

ll k;

ll st[20] = {0};

void comp(){
    st[1] = 1;
    ll tot = 9;
    for(ll i = 2; i<=18; i++){
        st[i] = tot + i;
        tot += pow(10,i-1)*9*i;
    }
}

ll bs(ll num, ll dig, ll e){
    ll ans = 0;
    ll s = 0;
    while(s <= e){
        ll mid = (s+e)/2;
        ll cur = ((mid)*(2*st[dig] + (mid-1)*dig))/2;
        if(num > cur){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return ans;
}

void solve(){
    re k;
    ll cur = 45;
    ll ext = 9;
    ll dig = 1;
    while(k-cur > 0){
        k -= cur;
        dig++;
        ext *= 10;
        cur = (ext*(2*(st[dig])+(ext-1)*dig))/2;
        // cout<<dig<<"()"<<cur<<"\n";
    }
    ll cnt = bs(k,dig,ext);
    // cout<<cnt<<"()\n";
    ll op = ((cnt)*(2*st[dig] + (cnt-1)*dig))/2;
    k -= op;
    // cout<<k<<"()"<<op<<"()\n";
    ll ndig = 1;
    cur = 9;
    ext = 9;
    while(k-cur*ndig > 0){
        k -= cur*ndig;
        ext *= 10;
        ndig++;
        cur = ext;
    }
    // cout<<ndig<<"()"<<k<<"()\n";
    ll ns = pow(10,ndig-1);
    if(k % ndig == 0){
        cnt = k/ndig-1;
        k = ndig-1;
    }
    else{
        cnt = k/ndig;
        k = k%ndig-1;
    }
    ns += (cnt);
    string s = to_string(ns);
    // cout<<s<<"()\n";
    pr(s[k]);
}

int32_t main(){
    KOBE;
    comp();
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
//when dividing with mod, use mod inverse

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
