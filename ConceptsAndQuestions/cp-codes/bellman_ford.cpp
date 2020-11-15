

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



const ll inf = 1e15;
vector<pair<pair<ll,ll>, ll > > e;
const ll M = 5010;


void dfs(vector<vl> &gr, vl &vis, ll cur){
    vis[cur] = true;
    for(auto x: gr[cur]){
        if(!vis[x]){
            dfs(gr,vis,x);
        }
    }
}

ll m,n,x,y,w;
void solve(){
    re n; re m;
    vl vis_a(M,0);
    vl vis_b(M,0);
    vector<vl> gr1(M);
    vector<vl> gr2(M);
    vl d(n+1,inf);
    d[1] = 0;
    fo(m){
        re x; re y; re w;
        w*=(-1);
        e.pb(mp(mp(x,y),w));
        gr1[x].pb(y);
        gr2[y].pb(x);
    }
    dfs(gr1,vis_a,1);
    dfs(gr2,vis_b,n);
    ll flag = 0;
    for(ll i = 1; i<=n; i++){
        flag = 0;
        for(ll j = 0; j<m; j++){
            x = e[j].ff.ff; y = e[j].ff.sec;
            w = e[j].sec;
            if(d[x]<inf){
                if(vis_a[x] && vis_b[y] && d[y]>d[x]+w){
                    d[y] = d[x] + w;
                    flag = 1;
                }
            }
        }
    }
    if(flag){
        pr(-1);
        return;
    }
    pr(-1*d[n]);
}

int32_t main(){
    KOBE;
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
