

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

const ll M = 1e5+100;
ll n;
vl gr[M];
vl lev[M];
const ll mxe = 30;
ll up[M][mxe];
ll dep[M] = {0};
ll pos[M];

void dfs(ll cur, ll par, ll level){
    // cout<<cur<<"()"<<par<<"()"<<level<<"\n";
    dep[cur] = level;
    up[cur][0] = par;
    lev[level].pb(cur);
    pos[cur] = lev[level].size()-1;
    for(auto x: gr[cur]){
        if(x != par) dfs(x,cur,level+1);
    }
}

ll fp(ll cur, ll k){
    if(dep[cur] < k) return -1;
    for(ll l = 0; l<mxe; l++){
        if((1<<l) & k){
            cur = up[cur][l];
        }
    }
    return cur;
}

ll comp(ll cur, ll k){
    ll par = fp(cur,k);
    if(par == -1) return 0;
    ll s = 0, e = pos[cur];
    ll l = dep[cur];
    ll lef = -1,rt;
    while(s <= e){
        ll mid = (s+e)/2;
        if(fp(lev[l][mid],k) != par){
            lef = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    s = pos[cur], e = lev[l].size()-1;
    while(s <= e){
        ll mid = (s+e)/2;
        if(fp(lev[l][mid],k) == par){
            rt = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    // if(cur == 2 && k == 1) cout<<rt<<"()"<<lef<<"\n";
    return rt-lef;
}

void solve(){
    re n;
    vl r;
    fo(n){
        ll x; re x;
        if(x == 0){
            r.pb(i+1);
            continue;
        }
        gr[x].pb(i+1);
        gr[i+1].pb(x);
    }
    for(auto x: r){
        dfs(x,0,0);
    }
    for(ll l = 1; l<mxe; l++){
        for(ll i = 1; i<=n; i++){
            if(up[i][l-1] != -1) up[i][l] = up[up[i][l-1]][l-1];
        }
    }

    ll m; re m;
    while(m--){
        ll v,p;
        re v; re p;
        ll k = comp(v,p);
        if(k){
            cout<<k-1<<" ";
        }else cout<<0<<" ";
    }
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
