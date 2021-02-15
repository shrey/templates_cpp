

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

//code starts here

const ll M = 1e5+100;
ll n,m,d,p[M],v,y;
vl gr[M];
ll du[M],dd[M];
ll mark[M] = {0};
ll inf = -1e15;
ll parent[M];
void dfs1(ll cur, ll par){
    if(mark[cur]) dd[cur] = max(dd[cur],0ll);
    parent[cur] = par;
    for(auto x: gr[cur]){
        if(x != par){
            dfs1(x,cur);
            dd[cur] = max(dd[cur],dd[x]+1);
        }
    }
}

void dfs2(ll cur, ll par){
    if(mark[cur]) du[cur] = max(du[cur],0ll);
    ll upr = inf;
    ll mx1 = -1, mx2 = -1, v;
    for(auto x: gr[cur]){
        if(x != par){
            if(dd[x] > mx1){
                mx2 = mx1;
                v = x;
                mx1 = dd[x];
            }
            else if(dd[x] > mx2){
                mx2 = dd[x];
            }
        }
    }
    // if(cur == 1){
    //     cout<<mx1<<"()"<<du[cur]<<"\n";
    // }
    for(auto x: gr[cur]){
        if(x == par) continue;
        if(x == v){
            if(mx2 != -1) du[x] = max(du[x],mx2+2);
        }else if(mx1 != -1){
            du[x] = max(du[x],mx1+2);
        }
        du[x] = max(du[x],du[cur]+1);
        dfs2(x,cur);
    }
}

void solve(){
    re n; re m; re d;
    fo(m) re p[i];
    fo(m) mark[p[i]] = true;
    fo(n-1){
        re v; re y;
        gr[v].pb(y); gr[y].pb(v);
    }

    memset(dd,inf,sizeof(dd));
    memset(du,inf,sizeof(du));
    fo(M){
        dd[i] = inf, du[i] = inf;
    }
    dfs1(1,0); dfs2(1,0);
    ll ans = 0;
    for(ll i = 1; i<=n; i++){
        if(dd[i] <= d && du[i] <= d){
            ans++;
            // cout<<i<<"()\n";
        }
        // cout<<i<<" = "<<dd[i]<<" , "<<du[i]<<"\n";
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


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
