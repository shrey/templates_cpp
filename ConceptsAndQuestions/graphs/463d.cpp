

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

ll n,k;
const ll M = 1010;
ll p[M][6];

vl gr[M];

ll len[M] = {0};
bool visited[M] = {false};
ll ans = 0;

void dfs(ll cur){
    len[cur] = 1;
    visited[cur] = true;
    ll cmx = 0;
    for(auto x: gr[cur]){
        if(!visited[x])
            dfs(x);
        cmx = max(cmx,len[x]);
    }
    len[cur] += cmx;
    ans = max(ans,len[cur]);
}

void solve(){
    re n; re k;
    fo(k){
        forn(j,n){
            ll x; re x;
            p[x][i] = j;
        }
    }
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n; j++){
            bool flag = true;
            if(i == j) continue;
            forn(perm,k){
                if(p[i][perm] >= p[j][perm]) flag = false;
            }
            if(flag){
                gr[i].pb(j);
            }
        }
    }
    for(ll i = 1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }
    pr(ans);
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
