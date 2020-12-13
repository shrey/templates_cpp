

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

ll n,x,y;
const ll M = 2e5+100;
vl gr[M];
vl cycle;
umap<ll,ll> visited;
vl pos(M,-1);
vl s;
umap<ll,bool> cyc;
bool flag = false;
umap<ll,ll> cnt;

void dfs1(ll cur, ll par){
    // cout<<cur<<"()"<<par<<"\n";
    visited[cur] = true;
    pos[cur] = s.size();
    s.pb(cur);
    for(auto x: gr[cur]){
        if(flag) return;
        if(visited[x] && x!=par && !flag){
            // cycle.pb(x);
            for(ll i = pos[x]; i<s.size(); i++){
                cycle.pb(s[i]);
                cyc[s[i]] = true;
            }
            flag = true;
            return;
        }
        else if(!visited[x]){
            dfs1(x,cur);
        }
    }
    s.pop_back();
}



void dfs2(ll cur){
    cnt[cur] = 1;
    visited[cur] = true;
    for(auto x: gr[cur]){
        if(!visited[x] && !cyc[x]){
            dfs2(x);
            cnt[cur] += cnt[x];
        }
    }
}

void solve(){
    re n;
    fo(n){
        re x; re y;
        gr[x].pb(y); gr[y].pb(x);
    }
    dfs1(1,0);
    visited.clear();
    ll ans = 0;
    for(auto v: cycle){
        dfs2(v);
        ll cur = cnt[v];
        // cout<<v<<"()"<<cnt[v]<<"\n";
        ans += (cur * (n-cur) + cur*(cur-1)/2);
    }
    pr(ans);
    cnt.clear();
    visited.clear();
    fo(n+1) gr[i].clear();
    s.clear();
    cycle.clear();
    cyc.clear();
    fo(n+1) pos[i] = -1;
    flag = false;
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
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
