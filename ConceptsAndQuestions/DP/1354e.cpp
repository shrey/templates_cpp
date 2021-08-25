

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
#define INF 1e18

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

vl gr[5010];
ll dp[5001][5001];
ll n,m;
ll n1,n2,n3;
vl side(5010);
ll pre[5010] = {0};
vector<vl> a;
vp arr;
vl sz;
vl res(5010);

bool bpcheck(ll src){
    queue<ll> q;
    q.push(src);
    sz.pb(src);
    side[src] = 0;
    while(!q.empty()){
        ll par = q.front();
        q.pop();
        for(auto x: gr[par]){
            if(side[x] == -1){
                sz.pb(x);
                side[x] = side[par] ^ 1;
                q.push(x);
            }else{
                if(side[x] == side[par]){
                    return false;
                }
            }
        }
    }
    return true;
}



ll recur(ll i, ll j){
    // cout<<i<<"()"<<j<<"\n";
    if(i == arr.size()){
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    ll l = arr[i].ff, r = arr[i].sec;
    ll ans = 0;
    ll k = n;
    if(i > 0) k -= (pre[i-1]+j);
    if(k >= l && j >= r){
        ans |= recur(i+1,j-r);
    }
    if(k >= r && j >= l){
        ans |= recur(i+1,j-l);
    }
    return dp[i][j] = ans;
}
void build(ll i, ll j, ll k){
    if(i == a.size()) return;
    ll l = arr[i].ff, r = arr[i].sec;
    if(j >= l && k >= r && dp[i+1][j-l]){
        for(auto x: a[i]){
            res[x] = side[x];
        }
        build(i+1,j-l,k-r);
        return;
    }
    if(j >= r && k >= l && dp[i+1][j-r]){
        for(auto x: a[i]){
            res[x] = !side[x];
        }
        build(i+1,j-r,k-l);
        return;
    }
}




void solve(){
    re n; re m;
    re n1; re n2; re n3;
    fo(n+1) side[i] = -1;
    fo(n+1) res[i] = -1;
    memset(dp,-1,sizeof(dp));
    fo(m){
        ll x,y; re x; re y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    for(ll i = 1; i<=n; i++){
        if(side[i] == -1){
            sz.clear();
            if(!bpcheck(i)){
                NO;
                return;
            }
            a.pb(sz);
        }
    }
    for(auto v: a){
       ll l = 0, r = 0;
       for(auto x: v){
           if(side[x] == 0) l++;
           else r++;
       }
       arr.pb(mp(l,r));
    }
    fo(arr.size()){
        pre[i] = arr[i].ff + arr[i].sec;
        if(i > 0) pre[i] += pre[i-1];
    }
    if(!recur(0,n2)){
        NO;
        return;
    }
    // pr("here");
    build(0,n2,n1+n3);
    YES;
    for(ll i = 1; i<=n; i++){
        if(res[i] == 0)cout<<2;
        else{
            if(n1){
                cout<<1;
                n1--;
            }else{
                cout<<3;
                n3--;
            }
        }
    }
    nl;
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
