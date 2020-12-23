

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

ll n,m,x,y;
const ll M = 2e5+100;
vl gr[M];
vl tin(M);
vl tout(M);
vl p(M,-1);
vl d(M,0);
ll T = 0;

void dfs(ll cur, ll dep, ll par){
    d[cur] = dep;
    tin[cur] = T++;
    p[cur] = par;
    for(auto x: gr[cur]){
        if(x != par){
            dfs(x,dep+1,cur);
        }
    }
    tout[cur] = T++;
}

void solve(){
    re n; re m;
    fo(n-1){
        re x; re y;
        gr[x].pb(y); gr[y].pb(x);
    }
    dfs(1,0,-1);
    forn(q,m){
        ll k; re k;
        vl v(k);
        fo(k) re v[i];
        ll u = v[0];
        fo(k){
            if(d[v[i]] > d[u]) u = v[i];
        }
        fo(k){
            if(v[i] == u) continue;
            if(p[v[i]] != -1) v[i] = p[v[i]];
        }
        bool flag = true;
        fo(k){
            ll cur = v[i];
            if(tin[cur] <= tin[u] && tout[cur] >= tout[u]) continue;
            else{
                flag = false;
                break;
            }
        }
        if(flag) YES;
        else NO;
    }
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
// try to find repeating pattern in matrices
