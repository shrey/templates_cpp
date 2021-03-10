

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
#define LG 30

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
    return (ll) a;
}



//code starts here

const ll M = 2e5+100;



ll par[LG][M],level[M],tot[M], maxe[LG][M] = {0};
ll c[M];
ll x,y;
ll n,m;
vector<pair<pll,pll> >  e;
vp gr[M];


void dfs(ll k,ll parent,ll d){
    par[0][k]=parent;
    // cout<<k<<"()";
    level[k]=d;
    tot[k]=1;
    for(auto it:gr[k])
    {
        if(it.ff==parent)
            continue;
        dfs(it.ff,k,d+1);
        maxe[0][it.ff] = it.sec;
        tot[k]+=tot[it.ff];
    }
}


void precompute(){
  for(ll i=1;i<LG;i++){
    for(ll j=1;j<=n;j++){
      if(par[i-1][j])
          par[i][j]=par[i-1][par[i-1][j]];
        maxe[i][j] = max(maxe[i-1][j],maxe[i-1][par[i-1][j]]);
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

ll mxdist(ll u, ll diff){
    ll mx = 0;
    for(ll i = LG-1; i>=0; i--){
        if((1ll<<i) & diff){
            mx = max(mx,maxe[i][u]);
            u = par[i][u];
        }
    }
    return mx;
}



vl p(M,0); vl r(M,1);

ll getp(ll v){
    if(v == p[v]) return v;
    return p[v] = getp(p[v]);
}

void unite(ll u, ll v){
    u = getp(u), v = getp(v);
    if(u == v) return;
    if(r[u] < r[v]) swap(u,v);
    r[u] += r[v];
    p[v] = u;
}


void solve(){
    //assign value of parent p[i] = i
    re n; re m;
    fo(n+1) p[i] = i;
    e.resize(m);
    fo(m){
        re e[i].sec.ff; re e[i].sec.sec; re e[i].ff.ff;
        ll x = e[i].sec.ff, y = e[i].sec.sec, w = e[i].ff.ff;
        e[i].ff.sec = i;
        // gr[x].pb(mp(y,w));
        // gr[y].pb(mp(x,w));
    }
    sort(e.begin(),e.end());
    ll res[m];
    fo(m) res[i] = -1;
    ll ans = 0;
    for(ll i = 0; i<m; i++){
        auto op = e[i];
        ll a = op.sec.ff, b = op.sec.sec;
        if(getp(a) != getp(b)){
            gr[a].pb(mp(b,op.ff.ff));
            gr[b].pb(mp(a,op.ff.ff));
            unite(a,b);
            ans += op.ff.ff;
            res[op.ff.sec] = 0;
        }
    }
    fo(m) if(res[i] == 0) res[i] = ans;
    dfs(1,0,0);
    // pr("here");
    precompute();
    fo(m){
        if(res[e[i].ff.sec] != -1){
            continue;
        }
            // cout<<i<<"()\n";
        ll l = lca(e[i].sec.ff,e[i].sec.sec);
        ll mx = 0;
        ll u = e[i].sec.ff, v = e[i].sec.sec;
        mx = max(mx,mxdist(u, level[u]-level[l]));
        mx = max(mx,mxdist(v,level[v]-level[l]));
        res[e[i].ff.sec] = ans + e[i].ff.ff - mx;
    }
    fo(m) pr(res[i]);
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    fo(M) p[i] = i;
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
