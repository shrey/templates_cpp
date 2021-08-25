

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

ll n,m;

const ll M = 4e5+100;
ll a[M];
vector<vl> mat;
vector<vl> vis;
vector<vl> need;

ll cnt = 0;

void dfs(ll x, ll y){
    vis[x][y] = true;
    // cout<<x<<"()"<<y<<"()\n";
    if(x > 0 && !vis[x-1][y] && mat[x-1][y]) dfs(x-1,y);
    if(x < n-1 && !vis[x+1][y]) dfs(x+1,y);
    if(y < m-1 && !vis[x][y+1] && mat[x][y+1]) dfs(x,y+1);
    if(y > 0 && !vis[x][y-1] && mat[x][y-1]) dfs(x,y-1);
}

void solve(){
    re n; re m;
    mat.resize(n+1);
    vis.resize(n+1);
    need.resize(n+1);
    fo(n+1){
        mat[i].resize(m+1);
        vis[i].resize(m+1);
        need[i].resize(m+1);
    }
    forn(i,n){
        forn(j,m){
            char ch; re ch;
            mat[i][j] = (ch == '#');
        }
    }
    fo(m) re a[i+1];
    forn(j,m){
        ll i = n-1;
        while(i >= 0 && mat[i][j]){
            need[i][j] = true;
            i--;
        }
    }
    ll ans = 0;
    forn(i,n){
        forn(j,m){
            if(!vis[i][j] && mat[i][j] && !need[i][j]){
                // cout<<i<<"()()()"<<j<<"\n";
                dfs(i,j);
                ans++;
            }
        }
    }
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
//when dividing with mod, use mod inverse

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
