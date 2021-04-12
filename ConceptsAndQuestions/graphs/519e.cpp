

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

//code starts here

const ll M = 1e5+100;
ll n,m;

ll par[LG][M],level[M],tot[M];
vl gr[M];
ll s[M] = {0};


void dfs(ll k,ll parent,ll d){
    par[0][k]=parent;
    level[k]=d;
    tot[k]=1;
    for(auto it:gr[k])
    {
        if(it==parent)
            continue;
        dfs(it,k,d+1);
        tot[k]+=tot[it];
    }
}


void precompute(){
  for(ll i=1;i<LG;i++){
    for(ll j=1;j<=n;j++){
      if(par[i-1][j])
          par[i][j]=par[i-1][par[i-1][j]];
    }
  }
}


ll lca(ll u, ll v)
{
    if(level[u]<level[v])
        swap(u,v);
    ll diff=level[u]-level[v];
    for(ll i=LG-1;i>=0;i--){
        if((1ll<<i) & diff){
            u=par[i][u];
        }
    }
    if(u==v)
        return u;
    for(ll i=LG-1;i>=0;i--){
        if(par[i][u] && par[i][u]!=par[i][v]){
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}

ll up(ll cur, ll k){
    for(ll i = LG-1; i>=0; i--){
        if((1<<i) & k){
            cur = par[i][cur];
        }
    }
    return cur;
}

void solve(){
    re n;
    fo(n-1){
        ll x,y;
        re x; re y;
        gr[x].pb(y); gr[y].pb(x);
    }
    dfs(1,0,0);
    precompute();
    re m;
    while(m--){
        ll x,y;
        re x; re y;
        if(level[x] < level[y]) swap(x,y);
        ll l = lca(x,y);
        // cout<<x<<"()"<<y<<" = "<<tot[x]<<"\n";
        ll d = level[x] + level[y] - 2*level[l];
        if(d % 2){
            pr(0);
            continue;
        }
        ll k = up(x,d/2);
        ll op = up(x,d/2-1);
        ll ans = tot[k] - tot[op];
        if(k == l){
            op = up(y,d/2-1);
            ans -= tot[op];
            ans += (n  - (tot[l]));
        }
        pr(ans);
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
