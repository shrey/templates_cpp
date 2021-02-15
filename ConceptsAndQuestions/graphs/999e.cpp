

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

ll n,m,s,x,y;
const ll M = 5010;
vl gr[M];
bool vis[M] = {false};
bool v2[M] = {false};
void dfs(ll cur){
    vis[cur] = true;
    for(auto x: gr[cur]){
        if(!vis[x]) dfs(x);
    }
}

ll cnt = 0;

void dfs2(ll cur){
    v2[cur] = true;
    cnt++;
    for(auto x: gr[cur]){
        if(!vis[x] && !v2[x]){
            dfs2(x);
        }
    }
}

bool compare(pll &a, pll &b){
    return a.ff > b.ff;
}

void solve(){
    re n; re m; re s;
    fo(m){
        re x; re y;
        gr[x].pb(y);
    }
    vp op;
    dfs(s);
    FOR(1,n){
        if(!vis[i]){
            cnt = 0;
            memset(v2,false,sizeof(v2));
            dfs2(i);
            op.pb(mp(cnt,i));
        }
    }
    sort(op.begin(),op.end(),compare);
    ll ans = 0;
    ll pos = 0;
    while(pos < op.size()){
        if(vis[op[pos].sec]){
            pos++;
            continue;
        }
        // cout<<op[pos].ff<<"()"<<op[pos].sec<<"\n";
        ans++;
        dfs(op[pos].sec);
        pos++;
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
