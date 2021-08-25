

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

const ll M = 3e5+100;
ll a[M] = {0};
vl gr[M]; vl gr2[M];
ll n,m,x,y;
vl scc;
vl order;
ll dp[M];
ll num[M];
vector<vl> cc;
ll ans = 0;

umap<ll,bool> visited;

void dfs(ll cur){
    visited[cur] = true;
    for(auto x: gr[cur]){
        if(!visited[x]) dfs(x);
    }
    order.pb(cur);
}

void dfs2(ll cur){
    visited[cur] = true;
    scc.pb(cur);
    for(auto x: gr2[cur]){
        if(!visited[x]){
            dfs2(x);
        }
    }
}

void dfs0(ll cur){
    visited[cur] = true;
    dp[cur] = 0;
    ll mx = 0;
    for(auto x: cc[num[cur]]){
        dp[cur] += a[x];
        visited[x] = true;
    }
    for(auto g: cc[num[cur]]){
        for(auto x: gr[g]){
            if(num[x] == num[cur]) continue;
            if(!visited[x]) dfs0(x);
            mx = max(mx,dp[x]);
        }
    }
    // cout<<cur<<"()"<<dp[cur]<<"()"<<mx<<"\n";
    dp[cur] += mx;
    ans = max(ans,dp[cur]);
    for(auto x: cc[num[cur]]) dp[x] = dp[cur];
}

void solve(){
    re n; re m;
    fo(n) re a[i+1];
    fo(m){
        re x; re y;
        gr[x].pb(y);
        gr2[y].pb(x);
    }
    for(ll i = 1; i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    ll ways = 1;
    visited.clear();
    for(ll i = n-1; i>=0; i--){
        if(!visited[order[i]]){
            dfs2(order[i]);
            ll tot = 0;
            cc.pb(scc);
            for(auto x: scc){
                tot += a[x];
                num[x] = cc.size()-1;
                // cout<<x<<"()";
            }
            // nl;
            scc.clear();
        }
    }
    visited.clear();
    for(ll i = 1; i<=n; i++){
        if(!visited[i]) dfs0(i);
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

/*
10 20
7 3 5 8 7 3 3 1 2 10
9 8
5 9
1 3
3 6
10 8
7 9
6 7
9 10
5 8
8 10
5 7
4 8
10 5
6 1
10 6
8 7
2 3
4 10
7 6
10 7
*/